//
// Copyright (C) 2000 Institut fuer Telematik, Universitaet Karlsruhe
// Copyright (C) 2004,2011 Andras Varga
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program; if not, see <http://www.gnu.org/licenses/>.
//

#include "inet/applications/mqttapp/mqttApp.h"

#include "inet/networklayer/common/L3AddressResolver.h"
#include "inet/common/ModuleAccess.h"
#include "inet/common/lifecycle/NodeOperations.h"
#include "inet/transportlayer/contract/udp/UDPControlInfo_m.h"
#include "inet/applications/mqttapp/mqttMessages/MqttMsgConnect_m.h"
#include "inet/applications/mqttapp/mqttMessages/MqttMsgConnack_m.h"
#include "inet/applications/mqttapp/mqttMessages/MqttMsgSubscribe_m.h"
#include "inet/applications/mqttapp/mqttMessages/MqttMsgPublish_m.h"
#include "inet/applications/mqttapp/mqttMessages/MqttMsgSuback_m.h"
#include "inet/applications/mqttapp/mqttMessages/MqttMsgPuback_m.h"

namespace inet {

Define_Module(mqttApp);

simsignal_t mqttApp::sentPkSignal = registerSignal("sentPk");
simsignal_t mqttApp::rcvdPkSignal = registerSignal("rcvdPk");
simsignal_t mqttApp::delaySignal = registerSignal("delay");


mqttApp::~mqttApp()
{
    cancelAndDelete(selfMsg);
}

void mqttApp::initialize(int stage)
{
    ApplicationBase::initialize(stage);

    if (stage == INITSTAGE_LOCAL) {

        isConnected=false;
        std::string tt=par("subscribeToTopics");
        std::string pubTopics=par("subscribeToTopics");
        publish=par("publish");
        //clientID=RandomString(10);

        ptrSubscribe=0;
        prtPublish=0;
        publish=par("publish");

        //populate the vector with all topics to subscribe

        std::istringstream f(tt);
        std::string s;

        while (getline(f, s, ',')) {
            //EV<<"topics: "<< s <<"\n";
            subscribeToTopics.push_back(s);
        }

        //populate the vector with all topics to publish data

        std::istringstream ff(pubTopics);
        std::string ss;

        while (getline(ff, ss, ',')) {
            EV<<"topics: "<< ss <<"\n";
            publishToTopics.push_back(ss);
        }


        numSent = 0;
        numReceived = 0;
        WATCH(numSent);
        WATCH(numReceived);

        localPort = par("localPort");
        destPort = par("destPort");
        startTime = par("startTime").doubleValue();
        stopTime = par("stopTime").doubleValue();
        packetName = par("packetName");
        if (stopTime >= SIMTIME_ZERO && stopTime < startTime)
            throw cRuntimeError("Invalid startTime/stopTime parameters");
        selfMsg = new cMessage("sendTimer");
    }
}

void mqttApp::handleMessageWhenUp(cMessage *msg)
{
    if (msg->isSelfMessage()) {
        ASSERT(msg == selfMsg);
        switch (selfMsg->getKind()) {
        case START:
            processStart();
            break;

        case SEND:
            processSend();
            break;

        case STOP:
            processStop();
            break;
        case MQTTSUBSCRIBED:

            break;
        case MQTTDATA:
            if(publish==true){
                sendMqttData();
            }
            break;

        default:
            throw cRuntimeError("Invalid kind %d in self message", (int)selfMsg->getKind());
        }
    }
    else if (msg->getKind() == UDP_I_DATA) {
        // process incoming packet

        processPacket(PK(msg));
    }
    else if (msg->getKind() == UDP_I_ERROR) {
        EV_WARN << "Ignoring UDP error report\n";
        delete msg;
    }
    else {
        throw cRuntimeError("Unrecognized message (%s)%s", msg->getClassName(), msg->getName());
    }

    if (hasGUI()) {
        char buf[40];
        sprintf(buf, "rcvd: %d pks\nsent: %d pks", numReceived, numSent);
        getDisplayString().setTagArg("t", 0, buf);
    }
}




void mqttApp::sendPacket()
{
    std::ostringstream str;
    str << packetName << "-" << numSent;

    MqttMsgConnect *mqttMessage = new MqttMsgConnect("mqttConnect");

    mqttMessage->setClientId(packetName);

    cPacket *payload = new cPacket(str.str().c_str());
    payload->setByteLength(par("messageLength").longValue());

    L3Address destAddr = chooseDestAddr();

    emit(sentPkSignal, payload);

    socket.sendTo(mqttMessage, destAddr, destPort);

    //socket.sendTo(payload, destAddr, destPort);
    numSent++;
}


void mqttApp::processStart()
{
    socket.setOutputGate(gate("udpOut"));
    const char *localAddress = par("localAddress");
    socket.bind(*localAddress ? L3AddressResolver().resolve(localAddress) : L3Address(), localPort);
    setSocketOptions();

    const char *destAddrs = par("destAddresses");
    cStringTokenizer tokenizer(destAddrs);
    const char *token;

    while ((token = tokenizer.nextToken()) != nullptr) {
        L3Address result;
        L3AddressResolver().tryResolve(token, result);
        if (result.isUnspecified())
            EV_ERROR << "cannot resolve destination address: " << token << endl;
        else
            destAddresses.push_back(result);

    }

    if (!destAddresses.empty()) {
        //selfMsg->setKind(CONNECT);
        selfMsg->setKind(SEND);
        processSend();
    }
    else {
        if (stopTime >= SIMTIME_ZERO) {
            selfMsg->setKind(STOP);
            scheduleAt(stopTime, selfMsg);
        }
    }
}

void mqttApp::processSend()
{
    EV<<"client break1";

    //sendPacket();

    sendConnect();
    simtime_t d = simTime() + par("sendInterval").doubleValue();
    if (stopTime < SIMTIME_ZERO || d < stopTime) {
        selfMsg->setKind(MQTTDATA);
        scheduleAt(d, selfMsg);
    }
    else {
        selfMsg->setKind(STOP);
        scheduleAt(stopTime, selfMsg);
    }
}

void mqttApp::sendConnect()
{

    MqttMsgConnect *mqttMessage = new MqttMsgConnect("mqttConnect");

    std::string s = std::to_string(this->getId());
    char const *pchar = s.c_str();

    clientID=s;

    mqttMessage->setClientId(pchar);

    mqttMessage->setQosLevel(1);
    //mqttMessage->setClientId(packetName);

    L3Address destAddr = chooseDestAddr();

    socket.sendTo(mqttMessage, destAddr, destPort);

    numSent++;
}

void mqttApp::processPacket(cPacket *pk)
{
    /*

    emit(rcvdPkSignal, pk);
    EV_INFO << "Received packet: " << UDPSocket::getReceivedPacketInfo(pk) << endl;

    EV<<"received pk: "<< pk->getName();

     */

    if (dynamic_cast<MqttMsgConnack* >(pk) || dynamic_cast<MqttMsgSuback* >(pk)) {

        if(subscribeToTopics.size() < 1){

        }

        processConSubAck(pk);
    }
    else if (dynamic_cast<MqttMsgPuback* >(pk)) {

       // emit(delaySignal, 1.2);
        MqttMsgPuback *ack = check_and_cast<MqttMsgPuback *>(pk);

        for(unsigned int lp=0; lp<publishedDatatable.size(); lp++){
            if(strcmp(ack->getMessageID(),publishedDatatable[lp]->getMqttMessages()->getMessageID())==0){
                emit(delaySignal, simTime()-publishedDatatable[lp]->getMqttMessages()->getCreationTime());
                break;
            }
        }

        //delete pk;





        /*

        MqttMsgPuback *ack = check_and_cast<MqttMsgPuback *>(pk);
        if(publishedDatatable.size()>0){
            for(unsigned int i=0; i<publishedDatatable.size();i++){
                if(strcmp(publishedDatatable[i]->getMqttMessages()->getMessageID(),ack->getMessageID())==0){
                    publishedDatatable[i]->setStatus(ack->getStatus());
                    break;
                }
            }
        }

        */

        /*

        int acceptedTasks=0;
        int completedTasks=0;
        int forwardedTasks=0;
        int unAckedTasks=0;



        for(unsigned int j=0; j<publishedDatatable.size();j++){

            if(publishedDatatable[j]->getStatus()==3){
                acceptedTasks=acceptedTasks+1;
            }
            else if(publishedDatatable[j]->getStatus()==6){
                completedTasks=completedTasks+1;
            }
            else if(publishedDatatable[j]->getStatus()==4){
                forwardedTasks=forwardedTasks+1;
            }
            else if(publishedDatatable[j]->getStatus()==1){
                unAckedTasks=unAckedTasks+1;
            }
        }
        EV<<"Unacked Tasks: "<<unAckedTasks<<"\n";
        EV<<"Accepted Tasks: "<<acceptedTasks<<"\n";
        EV<<"Completed Tasks: "<<completedTasks<<"\n";
        EV<<"Forwarded Tasks: "<<forwardedTasks<<"\n";


        */

    }

    else{

        if(publish==true){
            EV<<"breakpoint1";
            selfMsg->setKind(MQTTDATA);
            sendMqttData();
        }
    }

    if (dynamic_cast<MqttMsgSuback* >(pk))
    {


    }

    delete pk;
    numReceived++;

}

void mqttApp::processConSubAck(cPacket *c){

    if(publish==true && publishToTopics.size() > 0){
        selfMsg->setKind(MQTTDATA);
        sendMqttData();

    }

    if((subscribeToTopics.size() > 0) && (ptrSubscribe < subscribeToTopics.size())){

        std::ostringstream str;

        str << "subscribe" << "-" << subscribeToTopics[ptrSubscribe];

        MqttMsgSubscribe *mqttSubscribe = new MqttMsgSubscribe(str.str().c_str());

        mqttSubscribe->setTopic(subscribeToTopics[ptrSubscribe].c_str());
        mqttSubscribe->setQos(0);

        EV_WARN<<"subscribed topic:"<< subscribeToTopics[ptrSubscribe];

        //mqttSubscribe->setClientID(RandomString(10).c_str());

        //mqttSubscribe->setClientID(clientID.c_str());

        std::string s = std::to_string(this->getId());
        char const *pchar = s.c_str();

        mqttSubscribe->setClientID(pchar);

        L3Address destAddr = chooseDestAddr();

        socket.sendTo(mqttSubscribe, destAddr, destPort);

        ptrSubscribe++;
    }
}

void mqttApp::sendMqttData()
{
    const char* mID=RandomString(15).c_str();

    std::ostringstream str;
    str << "MQTTData " << "-" << "topic 1-"<<mID; // publishToTopics[0];

    MqttMsgPublish *mqttPublish = new MqttMsgPublish(str.str().c_str());
    L3Address destAddr = chooseDestAddr();

    //mqttPublish->setMessageID(RandomString(15).c_str());
    mqttPublish->setMessageID(mID);
    //delete mID;

    mqttPublish->setMIPSRequired(100);
    mqttPublish->setRequiredTime(0.01);


    //EV<<"my name: "<<getParentModule()->

    mqttPublish->setClientID(clientID.c_str());

    //mqttPublish->setTopic(publishToTopics[0].c_str());

    mqttPublish->setTopic("test topic 1");

    mqttPublish->setByteLength(rand() % 100 + 100);
    //mqttPublish->setByteLength(par("messageLength").longValue());



    mqttPublish->setQoS(1);

    PublishedData* pubData=new PublishedData();



    pubData->setMqttMessages(mqttPublish);
    pubData->setStatus(1);

    publishedDatatable.push_back(pubData);

    EV<<"table len: "<<publishedDatatable.size();

    //publishedRequests.push_back(mqttPublish);
    socket.sendTo(mqttPublish, destAddr, destPort);

    simtime_t d = simTime() + par("sendInterval").doubleValue();
    if (stopTime < SIMTIME_ZERO || d < stopTime) {
        selfMsg->setKind(MQTTDATA);
        cancelEvent(selfMsg);
        scheduleAt(d, selfMsg);
    }

}


void mqttApp::setSocketOptions()
{
    int timeToLive = par("timeToLive");
    if (timeToLive != -1)
        socket.setTimeToLive(timeToLive);

    int typeOfService = par("typeOfService");
    if (typeOfService != -1)
        socket.setTypeOfService(typeOfService);

    const char *multicastInterface = par("multicastInterface");
    if (multicastInterface[0]) {
        IInterfaceTable *ift = getModuleFromPar<IInterfaceTable>(par("interfaceTableModule"), this);
        InterfaceEntry *ie = ift->getInterfaceByName(multicastInterface);
        if (!ie)
            throw cRuntimeError("Wrong multicastInterface setting: no interface named \"%s\"", multicastInterface);
        socket.setMulticastOutputInterface(ie->getInterfaceId());
    }

    bool receiveBroadcast = par("receiveBroadcast");
    if (receiveBroadcast)
        socket.setBroadcast(true);

    bool joinLocalMulticastGroups = par("joinLocalMulticastGroups");
    if (joinLocalMulticastGroups) {
        MulticastGroupList mgl = getModuleFromPar<IInterfaceTable>(par("interfaceTableModule"), this)->collectMulticastGroups();
        socket.joinLocalMulticastGroups(mgl);
    }
}

L3Address mqttApp::chooseDestAddr()
{
    int k = intrand(destAddresses.size());
    if (destAddresses[k].isLinkLocal()) {    // KLUDGE for IPv6
        const char *destAddrs = par("destAddresses");
        cStringTokenizer tokenizer(destAddrs);
        const char *token = nullptr;

        for (int i = 0; i <= k; ++i)
            token = tokenizer.nextToken();
        destAddresses[k] = L3AddressResolver().resolve(token);
    }
    return destAddresses[k];
}

std::string mqttApp::RandomString(unsigned int len)

{
    srand(time(0));
    std::string str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::string newstr;
    int pos;
    while(newstr.size() != len) {
        pos = ((rand() % (str.size() - 1)));
        newstr += str.substr(pos,1);
    }
    return newstr;
}

bool mqttApp::handleNodeStart(IDoneCallback *doneCallback)
{
    simtime_t start = std::max(startTime, simTime());
    if ((stopTime < SIMTIME_ZERO) || (start < stopTime) || (start == stopTime && startTime == stopTime)) {
        selfMsg->setKind(START);
        scheduleAt(start, selfMsg);
    }
    return true;
}

bool mqttApp::handleNodeShutdown(IDoneCallback *doneCallback)
{
    if (selfMsg)
        cancelEvent(selfMsg);
    //TODO if(socket.isOpened()) socket.close();
    return true;
}

void mqttApp::handleNodeCrash()
{
    if (selfMsg)
        cancelEvent(selfMsg);
}

void mqttApp::processStop()
{
    socket.close();
}

void mqttApp::finish()
{
    recordScalar("packets sent", numSent);
    recordScalar("packets received", numReceived);
    ApplicationBase::finish();
}

} // namespace inet

