/*
 * ComputeBrokerApp2.cc
 *
 *  Created on: May 10, 2018
 *      Author: compute1
 */

#include "inet/applications/mqttapp/ComputeBrokerApp2.h"
#include "inet/networklayer/common/L3AddressResolver.h"
#include "inet/common/ModuleAccess.h"
#include "inet/common/lifecycle/NodeOperations.h"
#include "inet/transportlayer/contract/udp/UDPControlInfo_m.h"
#include "inet/applications/mqttapp/mqttMessages/MqttMsgConnect_m.h"
#include "inet/applications/mqttapp/mqttMessages/MqttMsgConnack_m.h"
#include "inet/applications/mqttapp/mqttMessages/MqttMsgSubscribe_m.h"
#include "inet/applications/mqttapp/mqttMessages/MqttMsgPublish_m.h"
#include "inet/applications/mqttapp/mqttMessages/MqttMsgPuback_m.h"
#include "inet/applications/mqttapp/mqttMessages/MqttMsgSuback_m.h"
#include "inet/applications/mqttapp/fognetMessages/FognetMsgAdvertiseMIPS_m.h"
#include "inet/applications/mqttapp/fognetMessages/FognetMsgTask_m.h"
#include "inet/applications/mqttapp/fognetMessages/FognetMsgTaskAck_m.h"

namespace inet {

Define_Module(ComputeBrokerApp2);

simsignal_t ComputeBrokerApp2::sentPkSignal = registerSignal("sentPk");
simsignal_t ComputeBrokerApp2::rcvdPkSignal = registerSignal("rcvdPk");


ComputeBrokerApp2::~ComputeBrokerApp2()
{
    cancelAndDelete(selfMsg);
}

void ComputeBrokerApp2::initialize(int stage)
{
    ApplicationBase::initialize(stage);

    if (stage == INITSTAGE_LOCAL) {

        isConnected=false;
        MIPS=par("MIPS");

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

void ComputeBrokerApp2::handleMessageWhenUp(cMessage *msg)
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
        case ADVERTISEMIPS:
            advertiseMIPS();
            break;
        case RELEASERESOURCE:
            releaseResource();
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
    else if(msg->getKind() == RELEASERESOURCE){
        releaseResource();
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

void ComputeBrokerApp2::sendPacket()
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

void ComputeBrokerApp2::processStart()
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

void ComputeBrokerApp2::processSend()
{
    EV<<"client break1";

    //sendPacket();
    sendConnect();
    simtime_t d = simTime() + par("sendInterval").doubleValue();
    if (stopTime < SIMTIME_ZERO || d < stopTime) {
        selfMsg->setKind(ADVERTISEMIPS);
        scheduleAt(d, selfMsg);
    }
    else {
        selfMsg->setKind(STOP);
        scheduleAt(stopTime, selfMsg);
    }
}

void ComputeBrokerApp2::sendConnect()
{
    MqttMsgConnect *mqttMessage = new MqttMsgConnect("mqttConnect");

    mqttMessage->setIsBroker(true);

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

void ComputeBrokerApp2::advertiseMIPS()
{
    FognetMsgAdvertiseMIPS *mipsMessage = new FognetMsgAdvertiseMIPS("MIPS: ");

    std::string s = std::to_string(this->getId());
    char const *pchar = s.c_str();

    clientID=s;

    mipsMessage->setComputeBrokerID(pchar);

    mipsMessage->setMIPS(MIPS);

    //mipsMessage->setQosLevel(0);
    //mqttMessage->setClientId(packetName);

    L3Address destAddr = chooseDestAddr();

    socket.sendTo(mipsMessage, destAddr, destPort);

    scheduleAt(simTime() + 0.01 , selfMsg);
}

void ComputeBrokerApp2::releaseResource(){
    //FognetMsgTask *tsk = check_and_cast<FognetMsgTask *>(pk);

    for(unsigned int i=0; i < requests.size(); i++){
        if(requests[i]->getRequiredTime() < simTime().dbl()){
            MIPS=MIPS + requests[i]->getRequiredMips(); //releasing the resource

            std::ostringstream str;
            str << "Task  " << requests[i]->getRequestId() << " performed";

            /*
            FognetMsgTaskAck *ackk=new FognetMsgTaskAck(str.str().c_str());
            ackk->setRequestID(requests[i]->getRequestId());
            ackk->setStatus(6);
            socket.sendTo(ackk,requests[i]->getClientIp(), requests[i]->getClientPort());

            */

            MqttMsgPuback *pubak=new MqttMsgPuback(str.str().c_str());
            pubak->setQos(0);
            pubak->setMessageID(requests[i]->getRequestId());
            pubak->setStatus(6);
            socket.sendTo(pubak,requests[i]->getClientIp(), requests[i]->getClientPort());
            this->bubble("Task performed");
            requests.erase(requests.begin()+ i); //remove request/task from table
            break;
        }

    }

    advertiseMIPS();
    //cancelEvent(selfMsg);
    //selfMsg->setKind(ADVERTISEMIPS);
    //scheduleAt(simTime() + 0.0001 , selfMsg);

}

void ComputeBrokerApp2::processPacket(cPacket *pk)
{

    if (dynamic_cast<MqttMsgConnack* >(pk)) {

        cancelEvent(selfMsg);
        selfMsg->setKind(ADVERTISEMIPS);
        scheduleAt(simTime() + 0.01 , selfMsg);

    }

    else if (dynamic_cast<FognetMsgTask* >(pk)){

        EV<<"break1 \n";


        FognetMsgTask *tsk = check_and_cast<FognetMsgTask *>(pk);
        UDPDataIndication *ctrl = check_and_cast<UDPDataIndication *>(pk->removeControlInfo());
        L3Address srcAddress = ctrl->getSrcAddr();
        int srcPort = ctrl->getSrcPort();
        //int sktid=ctrl->getSockId();
        delete ctrl;
        try{
            if(tsk->getRequiredMIPS() < MIPS){

                EV<<"break2 \n";
                MIPS=MIPS-tsk->getRequiredMIPS();

                Request *req=new Request(tsk->getClientID(),tsk->getRequestID(),srcAddress,srcPort,tsk->getRequiredMIPS(),simTime().dbl() + tsk->getRequiredTime(),true);

                requests.push_back(req);

                EV<<"task queue: "<<requests.size()<<"\n";

                //add mechanism to remove req from vectror after requiredTime passed, and update this->MIPS

                FognetMsgTaskAck *taskAck=new FognetMsgTaskAck("task assigned");



                taskAck->setRequestID(tsk->getRequestID());
                taskAck->setStatus(true);

                socket.sendTo(taskAck, srcAddress, srcPort);


                cancelEvent(selfMsg);
                selfMsg->setKind(RELEASERESOURCE);

                scheduleAt(simTime() + tsk->getRequiredTime(), selfMsg);

            }

            else{
                FognetMsgTaskAck *taskAck=new FognetMsgTaskAck("task rejected");

                taskAck->setRequestID(tsk->getRequestID());
                taskAck->setStatus(false);

                socket.sendTo(taskAck, srcAddress, srcPort);
            }


        }
        catch (std::exception e) {

        }





    }


    //delete pk;
    numReceived++;

}

void ComputeBrokerApp2::updateBaseBroker(){

    std::ostringstream str;

    str << "update base broker";

    MqttMsgPublish *msgUpdateBaseBroker = new MqttMsgPublish(str.str().c_str());

    msgUpdateBaseBroker->setQoS(0);


    std::string s = std::to_string(this->getId());
    char const *pchar = s.c_str();

    msgUpdateBaseBroker->setClientID(pchar);

    L3Address destAddr = chooseDestAddr();

    socket.sendTo(msgUpdateBaseBroker, destAddr, destPort);

    //ptrSubscribe++;

}

void ComputeBrokerApp2::sendMqttData()
{
    std::ostringstream str;
    str << "MQTTData " << "-" << "temp topic"; // publishToTopics[0];

    MqttMsgPublish *mqttPublish = new MqttMsgPublish(str.str().c_str());
    L3Address destAddr = chooseDestAddr();

    mqttPublish->setMIPSRequired(100);

    //EV<<"my name: "<<getParentModule()->

    mqttPublish->setClientID(clientID.c_str());

    //mqttPublish->setTopic(publishToTopics[0].c_str());

    mqttPublish->setTopic("test topic 1");

    mqttPublish->setQoS(1);

    socket.sendTo(mqttPublish, destAddr, destPort);


    simtime_t d = simTime() + par("sendInterval").doubleValue();
    if (stopTime < SIMTIME_ZERO || d < stopTime) {
        //selfMsg->setKind(MQTTDATA);
        cancelEvent(selfMsg);
        scheduleAt(d, selfMsg);
    }

}


void ComputeBrokerApp2::setSocketOptions()
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

L3Address ComputeBrokerApp2::chooseDestAddr()
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

std::string ComputeBrokerApp2::RandomString(unsigned int len)

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

bool ComputeBrokerApp2::handleNodeStart(IDoneCallback *doneCallback)
{
    simtime_t start = std::max(startTime, simTime());
    if ((stopTime < SIMTIME_ZERO) || (start < stopTime) || (start == stopTime && startTime == stopTime)) {
        selfMsg->setKind(START);
        scheduleAt(start, selfMsg);
    }
    return true;
}

bool ComputeBrokerApp2::handleNodeShutdown(IDoneCallback *doneCallback)
{
    if (selfMsg)
        cancelEvent(selfMsg);
    //TODO if(socket.isOpened()) socket.close();
    return true;
}

void ComputeBrokerApp2::handleNodeCrash()
{
    if (selfMsg)
        cancelEvent(selfMsg);
}

void ComputeBrokerApp2::processStop()
{
    socket.close();
}

void ComputeBrokerApp2::finish()
{
    recordScalar("packets sent", numSent);
    recordScalar("packets received", numReceived);
    ApplicationBase::finish();
}

} // namespace inet





