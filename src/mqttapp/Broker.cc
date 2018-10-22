/*
 * Broker.cc
 *
 *  Created on: Apr 9, 2018
 *      Author: compute1
 */

#ifndef BROKER
#define BROKER

#include "inet/applications/base/ApplicationBase.h"
#include "inet/transportlayer/contract/udp/UDPSocket.h"
namespace inet {

class Broker {

private:
    const char* brokerID = nullptr;
    L3Address brokerIP;
    int brokerPort;
    int MIPS;
    double busyTime=0.0;
public:
    Broker() {
        // TODO Auto-generated constructor stub

    }
    Broker(const char* brokerID,
            L3Address brokerIP,
            int brokerPort,
            int MIPS) {
        this->brokerID=brokerID;
        this->brokerIP=brokerIP;
        this->brokerPort=brokerPort;
        this->MIPS=MIPS;
    }
    ~Broker() {
        // TODO Auto-generated destructor stub
    }

    const char* getBrokerId() const {
        return brokerID;
    }

    void setBrokerId(const char* brokerId = nullptr) {
        brokerID = brokerId;
    }

    const L3Address& getBrokerIp() const {
        return brokerIP;
    }

    void setBrokerIp(const L3Address& brokerIp) {
        brokerIP = brokerIp;
    }

    int getBrokerPort() const {
        return brokerPort;
    }

    void setBrokerPort(int brokerPort) {
        this->brokerPort = brokerPort;
    }

    int getMips() const {
        return MIPS;
    }

    void setMips(int mips) {
        MIPS = mips;
    }

    double getBusyTime() const {
        return busyTime;
    }

    void setBusyTime(double busyTime = 0.0) {
        this->busyTime = busyTime;
    }
};

}
#endif



