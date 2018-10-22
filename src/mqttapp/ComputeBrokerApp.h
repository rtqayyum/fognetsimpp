/*
 * ComputeBrokerApp.h
 *
 *  Created on: Apr 6, 2018
 *      Author: compute1
 */

#ifndef __INET_COMPUTEBROKERAPP_H
#define __INET_COMPUTEBROKERAPP_H

#include <vector>

#include "inet/common/INETDefs.h"

#include "inet/applications/base/ApplicationBase.h"
#include "inet/transportlayer/contract/udp/UDPSocket.h"
#include "Request.cc"

namespace inet {

/**
 * UDP application. See NED for more info.
 */
class INET_API ComputeBrokerApp : public ApplicationBase
{
  protected:
    enum SelfMsgKinds { START = 1, SEND, STOP, ADVERTISEMIPS, RELEASERESOURCE, MQTTSUBSCRIBED };

    // parameters
    std::vector<L3Address> destAddresses;
    std::string clientID;
    int localPort = -1, destPort = -1;
    simtime_t startTime;
    simtime_t stopTime;
    const char *packetName = nullptr;
    bool isConnected;
    int MIPS;
    std::vector<Request*> requests;


    // state
    UDPSocket socket;
    cMessage *selfMsg = nullptr;

    // statistics
    int numSent = 0;
    int numReceived = 0;

    static simsignal_t sentPkSignal;
    static simsignal_t rcvdPkSignal;

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
    virtual void updateBaseBroker();

    virtual void sendConnect();
    //virtual void sendSubscribe();

    virtual bool handleNodeStart(IDoneCallback *doneCallback) override;
    virtual bool handleNodeShutdown(IDoneCallback *doneCallback) override;
    virtual void handleNodeCrash() override;
    virtual void advertiseMIPS();
    virtual void releaseResource();
    std::string RandomString(unsigned int len);

  public:
    ComputeBrokerApp() {}
    ~ComputeBrokerApp();
};

} // namespace inet

#endif // ifndef __INET_COMPUTEBROKERAPP_H

