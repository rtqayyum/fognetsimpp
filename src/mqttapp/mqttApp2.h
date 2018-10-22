/*
 * mqttApp2.h
 *
 *  Created on: May 10, 2018
 *      Author: compute1
 */

#ifndef __INET_MQTTAPP2_H
#define __INET_MQTTAPP2_H

#include <vector>

#include "inet/common/INETDefs.h"

#include "inet/applications/base/ApplicationBase.h"
#include "inet/transportlayer/contract/udp/UDPSocket.h"
#include "inet/applications/mqttapp/mqttMessages/MqttMsgPublish_m.h"
#include "PublishedData.cc"
#include "ModelPublishData.cc"

namespace inet {

/**
 * UDP application. See NED for more info.
 */
class INET_API mqttApp2 : public ApplicationBase
{
  protected:
    enum SelfMsgKinds { START = 1, SEND, STOP, MQTTDATA, MQTTSUBSCRIBED };

    // parameters
    std::vector<L3Address> destAddresses;
    std::string clientID;
    int localPort = -1, destPort = -1;
    simtime_t startTime;
    simtime_t stopTime;
    const char *packetName = nullptr;
    int ptrSubscribe;
    int prtPublish;
    bool isConnected;
    bool publish;
    int messageCount;
    int taskSize;

    std::vector<ModelPublishData *> uploadedTasks;



    std::vector<PublishedData *> publishedDatatable;
    std::vector<MqttMsgPublish *> publishedRequests;
    std::vector<std::string> subscribeToTopics;
    std::vector<std::string> publishToTopics;


    // state
    UDPSocket socket;
    cMessage *selfMsg = nullptr;

    // statistics
    int numSent = 0;
    int numReceived = 0;


    static simsignal_t latencySignal;
    static simsignal_t latencyH1Signal;
    static simsignal_t sentPkSignal;
    static simsignal_t rcvdPkSignal;
    static simsignal_t taskTimeSignal;

  protected:
    virtual int numInitStages() const override { return NUM_INIT_STAGES; }
    virtual void initialize(int stage) override;
    virtual void handleMessageWhenUp(cMessage *msg) override;
    virtual void finish() override;

    // chooses random destination address
    virtual L3Address chooseDestAddr();
    virtual void sendPacket();
    virtual void processPacket(cPacket *msg);
    virtual void setSocketOptions();

    virtual void processStart();
    virtual void processSend();
    virtual void processStop();
    virtual void sendMqttData();
    virtual void processConSubAck(cPacket *c);

    virtual void sendConnect();
    //virtual void sendSubscribe();

    virtual bool handleNodeStart(IDoneCallback *doneCallback) override;
    virtual bool handleNodeShutdown(IDoneCallback *doneCallback) override;
    virtual void handleNodeCrash() override;
    std::string RandomString(unsigned int len);

  public:
    mqttApp2() {}
    ~mqttApp2();
};

} // namespace inet

#endif // ifndef __INET_UDPBASICAPP_H





