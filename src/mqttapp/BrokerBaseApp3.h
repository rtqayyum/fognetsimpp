/*
 * BrokerBaseApp3.h
 *
 *  Created on: May 16, 2018
 *      Author: compute1
 */

#ifndef __INET_BROKERBASEAPP3_H
#define __INET_BROKERBASEAPP32_H

#include "inet/common/INETDefs.h"

#include "inet/applications/base/ApplicationBase.h"
#include "inet/transportlayer/contract/udp/UDPSocket.h"
#include "Client.cc"
#include "Broker.cc"
#include "Subscription.cc"
#include "inet/applications/mqttapp/mqttMessages/MqttMsgPublish_m.h"
#include "Request.cc"

namespace inet {

/**
 * UDP application. See NED for more info.
 */
class INET_API BrokerBaseApp3 : public ApplicationBase
{
  protected:
    enum SelfMsgKinds { START = 1, SEND, STOP, ADVERTISEMIPS, RELEASERESOURCE, MQTTSUBSCRIBED };
    UDPSocket socket;
    int numEchoed;    // just for WATCH
    static simsignal_t pkSignal;
    int numClients;
    int numSubscribed;
    std::vector<Client*> clients;
    std::vector<Broker*> brokers;
    int MIPS;
    static simsignal_t delaySignal;
    int algo;

    cMessage *selfMsg = nullptr;

    //Client* clients[10];
    std::vector<Subscription*> subscriptions;
    std::vector<MqttMsgPublish*> MqttMessages;
    std::vector<Request*> requests;
    //const char* subscriptions[10][3];

  protected:
    virtual int numInitStages() const override { return NUM_INIT_STAGES; }
    virtual void initialize(int stage) override;
    virtual void handleMessageWhenUp(cMessage *msg) override;
    virtual void finish() override;
    virtual void updateDisplay();

    virtual bool handleNodeStart(IDoneCallback *doneCallback) override;
    virtual bool handleNodeShutdown(IDoneCallback *doneCallback) override;
    virtual void handleNodeCrash() override;
    Client* findClient(const char* clientID);
    virtual void publishAll(cMessage *msg);
    virtual void sendPubAck(MqttMsgPublish *msg,L3Address ip, int port, bool status);
    virtual std::string RandomString(unsigned int len);
    virtual void releaseResource(const char* id);
    virtual void publishMessage(const char* clientID, cMessage *msg);
};

} // namespace inet

#endif // ifndef __INET_BROKERBASEAPP_H










