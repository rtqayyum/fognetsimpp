/*
 * mqttApp2.cc
 *
 *  Created on: May 10, 2018
 *      Author: compute1
 */

#include "inet/applications/mqttapp/mqttApp2.h"

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

Define_Module(mqttApp2);

simsignal_t mqttApp2::sentPkSignal = registerSignal("sentPk");
simsignal_t mqttApp2::rcvdPkSignal = registerSignal("rcvdPk");

simsignal_t mqttApp2::latencySignal = registerSignal("latency");
simsignal_t mqttApp2::latencyH1Signal = registerSignal("latencyH1");
simsignal_t mqttApp2::taskTimeSignal = registerSignal("taskTime");


mqttApp2::~mqttApp2()
{
    cancelAndDelete(selfMsg);
}

void mqttApp2::initialize(int stage)
{
    ApplicationBase::initialize(stage);

    if (stage == INITSTAGE_LOCAL) {

        uploadedTasks.clear();

        isConnected=false;
        std::string tt=par("subscribeToTopics");
        std::string pubTopics=par("subscribeToTopics");
        publish=par("publish");
        //clientID=RandomString(10);

        ptrSubscribe=0;
        prtPublish=0;
        publish=par("publish");
        taskSize=par("taskSize");

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

        messageCount=0;
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

void mqttApp2::handleMessageWhenUp(cMessage *msg)
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




void mqttApp2::sendPacket()
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


void mqttApp2::processStart()
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

void mqttApp2::processSend()
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

void mqttApp2::sendConnect()
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

void mqttApp2::processPacket(cPacket *pk)
{

    emit(rcvdPkSignal, pk);
    EV_INFO << "Received packet: " << UDPSocket::getReceivedPacketInfo(pk) << endl;

    EV<<"received pk: "<< pk->getName();


    if (dynamic_cast<MqttMsgConnack* >(pk) || dynamic_cast<MqttMsgSuback* >(pk)) {

        if(subscribeToTopics.size() < 1){

        }

        processConSubAck(pk);
    }
    else if (dynamic_cast<MqttMsgPuback* >(pk)) {

        try {
            MqttMsgPuback *ack = check_and_cast<MqttMsgPuback *>(pk);
            //task queued ack from compute brokers
            if(ack->getStatus()==5){
                for(unsigned int i=0;i<uploadedTasks.size();i++){
                    if(strcmp(ack->getMessageID(),uploadedTasks[i]->getMessageId())==0){
                        emit(latencySignal, ((simTime()-uploadedTasks[i]->getTimeCreated())*1000));


                        break;
                    }
                }
            }

            //computation request is forwarded to the computer brokers
            else if(ack->getStatus()==4){
                for(unsigned int i=0;i<uploadedTasks.size();i++){
                    if(strcmp(ack->getMessageID(),uploadedTasks[i]->getMessageId())==0){
                        emit(latencyH1Signal, ((simTime()-uploadedTasks[i]->getTimeCreated())*1000));
                        EV<<"simtest"<<(simTime()-uploadedTasks[i]->getTimeCreated()) <<"\n";
                        break;
                    }
                }
            }

            else if (ack->getStatus()==6) {
                for(unsigned int i=0;i<uploadedTasks.size();i++){
                    if(strcmp(ack->getMessageID(),uploadedTasks[i]->getMessageId())==0){
                        emit(taskTimeSignal,((simTime()-uploadedTasks[i]->getTimeCreated())*1000));


                        //emit(delaySignal, ((simTime()-uploadedTasks[i]->getTimeCreated())));
                        //emit(delaySignal, (simTime()-uploadedTasks[i]->getTimeCreated()));
                        //emit(delaySignal, 1.3);
                        uploadedTasks.erase(uploadedTasks.begin()+i);
                        std::ostringstream str;
                        str << "Task: "<< ack->getMessageID()<<" performed";

                        this->getParentModule()->bubble(str.str().c_str());
                        break;
                    }
                }
            }

        } catch (const std::exception& e) {

        }

        // emit(delaySignal, 1.2);
        /*

        MqttMsgPuback *ack = check_and_cast<MqttMsgPuback *>(pk);

        for(unsigned int lp=0; lp<publishedDatatable.size(); lp++){
            if(strcmp(ack->getMessageID(),publishedDatatable[lp]->getMqttMessages()->getMessageID())==0){
                emit(delaySignal, simTime()-publishedDatatable[lp]->getMqttMessages()->getCreationTime());
                break;
            }
        }

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

void mqttApp2::processConSubAck(cPacket *c){

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

void mqttApp2::sendMqttData()
{
    messageCount=messageCount+1;

    std::string s = std::to_string(messageCount);
    s=s+clientID;
    char const *mID = s.c_str();


    std::ostringstream str;
    str << "MQTTData " << "-" << "topic 1-"<<mID; // publishToTopics[0];

    MqttMsgPublish *mqttPublish = new MqttMsgPublish(str.str().c_str());
    L3Address destAddr = chooseDestAddr();

    //mqttPublish->setMessageID(RandomString(15).c_str());
    mqttPublish->setMessageID(mID);
    //delete mID;

    //fixed sized task
    //mqttPublish->setMIPSRequired(taskSize);

    //variable sized tasks


    mqttPublish->setMIPSRequired(200 + rand() % (( 900 + 1 ) - 200));

    mqttPublish->setRequiredTime(0.01);


    //EV<<"my name: "<<getParentModule()->

    mqttPublish->setClientID(clientID.c_str());

    //mqttPublish->setTopic(publishToTopics[0].c_str());

    mqttPublish->setTopic("compute task");

    //mqttPublish->setByteLength(rand() % 100 + 900);
    mqttPublish->setByteLength(128);
    //mqttPublish->setByteLength(par("messageLength").longValue());

    mqttPublish->setQoS(1);


    ModelPublishData* pubD=new ModelPublishData(mqttPublish->getMessageID(),mqttPublish->getByteLength(),simTime());

    uploadedTasks.push_back(pubD);

    for(unsigned int k=0;k<uploadedTasks.size();k++){
        EV<<"Message No. "<< k <<"-----"<<uploadedTasks[k]->getMessageId()<<"\n";
    }

    //////////////////////////////////////////
    emit(sentPkSignal, mqttPublish);

    //publishedRequests.push_back(mqttPublish);
    socket.sendTo(mqttPublish, destAddr, destPort);




    simtime_t d = simTime() + par("sendInterval").doubleValue();
    if (stopTime < SIMTIME_ZERO || d < stopTime) {
        selfMsg->setKind(MQTTDATA);
        cancelEvent(selfMsg);
        scheduleAt(d, selfMsg);
    }



}


void mqttApp2::setSocketOptions()
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

L3Address mqttApp2::chooseDestAddr()
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

std::string mqttApp2::RandomString(unsigned int len)

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

bool mqttApp2::handleNodeStart(IDoneCallback *doneCallback)
{
    simtime_t start = std::max(startTime, simTime());
    if ((stopTime < SIMTIME_ZERO) || (start < stopTime) || (start == stopTime && startTime == stopTime)) {
        selfMsg->setKind(START);
        scheduleAt(start, selfMsg);
    }
    return true;
}

bool mqttApp2::handleNodeShutdown(IDoneCallback *doneCallback)
{
    if (selfMsg)
        cancelEvent(selfMsg);
    //TODO if(socket.isOpened()) socket.close();
    return true;
}

void mqttApp2::handleNodeCrash()
{
    if (selfMsg)
        cancelEvent(selfMsg);
}

void mqttApp2::processStop()
{
    socket.close();
}

void mqttApp2::finish()
{
    recordScalar("packets sent", numSent);
    recordScalar("packets received", numReceived);
    recordScalar("latency", latencySignal);
    recordScalar("latencyH1", latencyH1Signal);
    ApplicationBase::finish();
}

} // namespace inet




