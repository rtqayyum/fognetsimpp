/*
 * PublishedData.cc
 *
 *  Created on: Apr 26, 2018
 *      Author: compute1
 */
#ifndef PUBLISHEDDATA
 #define PUBLISHEDDATA

#include "inet/applications/base/ApplicationBase.h"
#include "inet/transportlayer/contract/udp/UDPSocket.h"
#include "inet/applications/mqttapp/mqttMessages/MqttMsgPublish_m.h"

namespace inet {

class PublishedData {

protected:
    enum messageStatus{UNACKED=1,ACKED=2,ACCEPTED=3,FORWARDED=4,QUEUED=5};

private:
    MqttMsgPublish* mqttMessages;
    int status;
public:
    PublishedData() {
        // TODO Auto-generated constructor stub

    }
    PublishedData(MqttMsgPublish* mes, int status) {
        this->mqttMessages=mes;
        this->status=status;
    }
    ~PublishedData() {
        // TODO Auto-generated destructor stub
    }

    const MqttMsgPublish* getMqttMessages() const {
        return mqttMessages;
    }

    void setMqttMessages(MqttMsgPublish* mqttMessages) {
        this->mqttMessages = mqttMessages;
    }

    int getStatus() const {
        return status;
    }

    void setStatus(int status) {
        this->status = status;
    }
};

}
#endif




