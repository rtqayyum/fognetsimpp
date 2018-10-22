 #ifndef SUBSCRIPTION
 #define SUBSCRIPTION

#include "inet/applications/base/ApplicationBase.h"
namespace inet {

class Subscription {

private:
    const char* clientID = nullptr;
        int QoS;
        const char* topic = nullptr;
public:
        Subscription() {
        // TODO Auto-generated constructor stub

    }
        Subscription(const char* clientID, int QoS, const char* topic) {
        this->clientID=clientID;
        this->QoS=QoS;
        this->topic=topic;
    }
    ~Subscription() {
        // TODO Auto-generated destructor stub
    }

    const char* getClientId() const {
        return clientID;
    }

    void setClientId(const char* clientId = nullptr) {
        clientID = clientId;
    }

    int getQoS() const {
        return QoS;
    }

    void setQoS(int qoS) {
        QoS = qoS;
    }

    const char* getTopic() const {
        return topic;
    }

    void setTopic(const char* topic = nullptr) {
        this->topic = topic;
    }
};

}
#endif
