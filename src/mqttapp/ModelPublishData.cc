/*
 * ModelPublishData.cc
 *
 *  Created on: May 10, 2018
 *      Author: compute1
 */


#ifndef MODELPUBLISHDATA
 #define MODELPUBLISHDATA

#include "inet/applications/base/ApplicationBase.h"
#include "inet/transportlayer/contract/udp/UDPSocket.h"

namespace inet {

class ModelPublishData {

protected:

private:
    const char* messageID;
    simtime_t timeCreated;
    int64_t byteSize;

public:
    ModelPublishData() {
        // TODO Auto-generated constructor stub
    }
    ModelPublishData(const char* messageID, int64_t byteSize, simtime_t timeCreated) {
        this->messageID=messageID;
        this->timeCreated=timeCreated;
        this->byteSize=byteSize;
    }
    ~ModelPublishData() {
        // TODO Auto-generated destructor stub
    }

    long getByteSize() const {
        return byteSize;
    }

    void setByteSize(long byteSize) {
        this->byteSize = byteSize;
    }

    const char* getMessageId() const {
        return messageID;
    }

    void setMessageId(const char* messageId) {
        messageID = messageId;
    }

    const simtime_t& getTimeCreated() const {
        return timeCreated;
    }

    void setTimeCreated(const simtime_t& timeCreated) {
        this->timeCreated = timeCreated;
    }
};

}
#endif







