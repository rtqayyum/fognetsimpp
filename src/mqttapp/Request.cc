/*
 * Request.cc
 *
 *  Created on: Apr 9, 2018
 *      Author: compute1
 */
#ifndef REQUEST
#define REQUEST

#include "inet/applications/base/ApplicationBase.h"
#include "inet/transportlayer/contract/udp/UDPSocket.h"
namespace inet {

class Request {

private:
    const char* clientID = nullptr;
    const char* requestID = nullptr;
    L3Address clientIP;
    int clientPort;
    int requiredMIPS;
    bool status;
    double requiredTime;
    double timeToFlush;
    int ackStatus;
    double queueStartTime;


public:
    Request() {
        // TODO Auto-generated constructor stub

    }
    Request(const char* clientID,
            const char* requestID,
            L3Address clientIP,
            int clientPort,
            int requiredMIPS,
            double requiredTime,
            bool status) {
        this->clientID=clientID;
        this->requestID=requestID;
        this->clientIP=clientIP;
        this->clientPort=clientPort;
        this->requiredMIPS=requiredMIPS;
        this->requiredTime=requiredTime;
        this->status=status;
    }
    Request(const char* clientID,
                const char* requestID,
                L3Address clientIP,
                int clientPort,
                int requiredMIPS,
                double requiredTime,
                bool status,
                double timeToFlush) {
            this->clientID=clientID;
            this->requestID=requestID;
            this->clientIP=clientIP;
            this->clientPort=clientPort;
            this->requiredMIPS=requiredMIPS;
            this->requiredTime=requiredTime;
            this->timeToFlush=timeToFlush;
            this->status=status;

        }


    ~Request() {
        // TODO Auto-generated destructor stub
    }

    const char* getClientId() const {
        return clientID;
    }

    void setClientId(const char* clientId = nullptr) {
        clientID = clientId;
    }

    const L3Address& getClientIp() const {
        return clientIP;
    }

    void setClientIp(const L3Address& clientIp) {
        clientIP = clientIp;
    }

    int getClientPort() const {
        return clientPort;
    }

    void setClientPort(int clientPort) {
        this->clientPort = clientPort;
    }

    const char* getRequestId() const {
        return requestID;
    }

    void setRequestId(const char* requestId = nullptr) {
        requestID = requestId;
    }

    int getRequiredMips() const {
        return requiredMIPS;
    }

    void setRequiredMips(int requiredMips) {
        requiredMIPS = requiredMips;
    }

    double getRequiredTime() const {
        return requiredTime;
    }

    void setRequiredTime(double requiredTime) {
        this->requiredTime = requiredTime;
    }

    bool isStatus() const {
        return status;
    }

    void setStatus(bool status) {
        this->status = status;
    }

    int getAckStatus() const {
        return ackStatus;
    }

    void setAckStatus(int ackStatus) {
        this->ackStatus = ackStatus;
    }

    double getQueueStartTime() const {
        return queueStartTime;
    }

    void setQueueStartTime(double queueStartTime) {
        this->queueStartTime = queueStartTime;
    }
};

}
#endif




