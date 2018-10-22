/*
 * ComputeBrokerApp3.cc
 *
 *  Created on: May 16, 2018
 *      Author: compute1
 */
#include "inet/applications/mqttapp/ComputeBrokerApp3.h"
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

Define_Module(ComputeBrokerApp3);

simsignal_t ComputeBrokerApp3::sentPkSignal = registerSignal("sentPk");
simsignal_t ComputeBrokerApp3::rcvdPkSignal = registerSignal("rcvdPk");
simsignal_t ComputeBrokerApp3::queueTimeSignal = registerSignal("queueTime");


ComputeBrokerApp3::~ComputeBrokerApp3()
{
    cancelAndDelete(selfMsg);
}

void ComputeBrokerApp3::initialize(int stage)
{
    ApplicationBase::initialize(stage);

    if (stage == INITSTAGE_LOCAL) {

        isConnected=false;
        MIPS=par("MIPS");


        busyTime=0.0;
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

void ComputeBrokerApp3::handleMessageWhenUp(cMessage *msg)
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

void ComputeBrokerApp3::sendPacket()
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

void ComputeBrokerApp3::processStart()
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

void ComputeBrokerApp3::processSend()
{

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

void ComputeBrokerApp3::sendConnect()
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

void ComputeBrokerApp3::advertiseMIPS()
{
    FognetMsgAdvertiseMIPS *mipsMessage = new FognetMsgAdvertiseMIPS("MIPS: ");

    std::string s = std::to_string(this->getId());
    char const *pchar = s.c_str();

    clientID=s;

    mipsMessage->setComputeBrokerID(pchar);

    mipsMessage->setMIPS(MIPS);
    mipsMessage->setBusyTime(busyTime);

    /*
    if(requests.size()<1){
        mipsMessage->setBusyTime(busyTime);
    }
    else{
        double temp=0.0;
        for(unsigned int i=0;i<requests.size();i++){
            temp=temp+requests[i]->getRequiredTime();
        }
        EV<<"temppp"<<temp;
        mipsMessage->setBusyTime(temp);
    }

     */

    //mipsMessage->setQosLevel(0);
    //mqttMessage->setClientId(packetName);

    L3Address destAddr = chooseDestAddr();

    socket.sendTo(mipsMessage, destAddr, destPort);

    //scheduleAt(simTime() + 0.01 , selfMsg);
}

void ComputeBrokerApp3::releaseResource(){
    std::ostringstream str;
    str << "Task  " << currentTask.getRequestId() << " performed";

    MqttMsgPuback *pubak=new MqttMsgPuback(str.str().c_str());
    pubak->setQos(0);
    pubak->setMessageID(currentTask.getRequestId());
    pubak->setStatus(6); //task performed successfully
    busyTime=busyTime-currentTask.getRequiredTime();
    socket.sendTo(pubak,currentTask.getClientIp(), currentTask.getClientPort());

    //requests.erase(requests.begin()+0);
    resourceStatus=false;

    if(requests.size()>0){
        resourceStatus=true;
        emit(queueTimeSignal, ((simTime()-requests[0]->getQueueStartTime())*1000));
        //EV<<"asdfgh"<<requests[0]->getQueueStartTime() <<"\n";

        currentTask.setClientId(requests[0]->getClientId());
        currentTask.setRequestId(requests[0]->getRequestId());
        currentTask.setClientIp(requests[0]->getClientIp());
        currentTask.setClientPort(requests[0]->getClientPort());
        currentTask.setRequiredTime(requests[0]->getRequiredTime());

        requests.erase(requests.begin()+0);

        selfMsg->setKind(RELEASERESOURCE);
        cancelEvent(selfMsg);
        scheduleAt(simTime() + currentTask.getRequiredTime() , selfMsg);

    }

    advertiseMIPS();

}

void ComputeBrokerApp3::processPacket(cPacket *pk)
{

    if (dynamic_cast<MqttMsgConnack* >(pk)) {

        cancelEvent(selfMsg);
        selfMsg->setKind(ADVERTISEMIPS);
        scheduleAt(simTime() + 0.01 , selfMsg);

    }

    else if (dynamic_cast<FognetMsgTask* >(pk)){

        FognetMsgTask *tsk = check_and_cast<FognetMsgTask *>(pk);
        UDPDataIndication *ctrl = check_and_cast<UDPDataIndication *>(pk->removeControlInfo());
        L3Address srcAddress = ctrl->getSrcAddr();
        int srcPort = ctrl->getSrcPort();
        //int sktid=ctrl->getSockId();
        delete ctrl;
        //double tskTime=((static_cast<double>(tsk->getByteLength()))/MIPS);
        double tskTime=tsk->getRequiredMIPS()/MIPS;
        try{
            //Request *req=new Request(tsk->getClientID(),tsk->getRequestID(),srcAddress,srcPort,tsk->getRequiredMIPS(),tskTime,true);

            busyTime=busyTime+tskTime;

            //status false means, no task is being processed
            if(resourceStatus==false){

                resourceStatus=true;
                MqttMsgPuback *taskAck=new MqttMsgPuback("task assigned");
                taskAck->setMessageID(tsk->getRequestID());
                taskAck->setStatus(5);

                //FognetMsgTaskAck *taskAck=new FognetMsgTaskAck("task assigned");
                //taskAck->setRequestID(tsk->getRequestID());
                //taskAck->setStatus(true);

                socket.sendTo(taskAck, srcAddress, srcPort);


                currentTask.setClientId(tsk->getClientID());
                currentTask.setRequestId(tsk->getRequestID());
                currentTask.setClientIp(srcAddress);
                currentTask.setClientPort(srcPort);
                currentTask.setRequiredTime(tskTime);


                selfMsg->setKind(RELEASERESOURCE);
                //selfMsg->setName(tsk->getId());
                scheduleAt(simTime() +  tskTime, selfMsg);

            }
            else{
                Request *req=new Request(tsk->getClientID(),tsk->getRequestID(),srcAddress,srcPort,tsk->getRequiredMIPS(),tskTime,false);
                req->setQueueStartTime(simTime().dbl());


                requests.push_back(req);
                //FognetMsgTaskAck *taskAck=new FognetMsgTaskAck("task is queued");
                //taskAck->setRequestID(tsk->getRequestID());
                //taskAck->setStatus(true);
                MqttMsgPuback *taskAck=new MqttMsgPuback("task queued");
                taskAck->setMessageID(tsk->getRequestID());
                taskAck->setStatus(4);
                socket.sendTo(taskAck, srcAddress, srcPort);
            }

        }
        catch (std::exception e) {

        }
    }

    //delete pk;
    numReceived++;
}

void ComputeBrokerApp3::updateBaseBroker(){

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

void ComputeBrokerApp3::setSocketOptions()
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

L3Address ComputeBrokerApp3::chooseDestAddr()
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

std::string ComputeBrokerApp3::RandomString(unsigned int len)

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

bool ComputeBrokerApp3::handleNodeStart(IDoneCallback *doneCallback)
{
    simtime_t start = std::max(startTime, simTime());
    if ((stopTime < SIMTIME_ZERO) || (start < stopTime) || (start == stopTime && startTime == stopTime)) {
        selfMsg->setKind(START);
        scheduleAt(start, selfMsg);
    }
    return true;
}

bool ComputeBrokerApp3::handleNodeShutdown(IDoneCallback *doneCallback)
{
    if (selfMsg)
        cancelEvent(selfMsg);
    //TODO if(socket.isOpened()) socket.close();
    return true;
}

void ComputeBrokerApp3::handleNodeCrash()
{
    if (selfMsg)
        cancelEvent(selfMsg);
}

void ComputeBrokerApp3::processStop()
{
    socket.close();
}

void ComputeBrokerApp3::finish()
{
    recordScalar("packets sent", numSent);
    recordScalar("packets received", numReceived);
    ApplicationBase::finish();
}

} // namespace inet









