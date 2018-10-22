 #ifndef CLIENT
 #define CLIENT

#include "inet/applications/base/ApplicationBase.h"
#include "inet/transportlayer/contract/udp/UDPSocket.h"
namespace inet {

class Client {

private:
    const char* clientID = nullptr;
        L3Address clientIP;
        int clientPort;
        int QoS;
        const char* protocolName = nullptr;
        const char* protocolVersion = nullptr;
        int willFlag;
        const char* willTopic = nullptr;
        const char* willMessage = nullptr;
        int cleanSession;
        int keepAlivePeriod;
public:
    Client() {
        // TODO Auto-generated constructor stub

    }
    Client(const char* clientID,
    L3Address clientIP,
    int clientPort,
    int QoS,
    const char* protocolName,
    const char* protocolVersion,
    int willFlag,
    const char* willTopic ,
    const char* willMessage,
    int cleanSession,
    int keepAlivePeriod) {
        this->clientID=clientID;
        this->clientIP=clientIP;
        this->clientPort=clientPort;
        this->QoS=QoS;
        this->protocolName=protocolName;
        this->protocolVersion=protocolVersion;
        this->willFlag=willFlag;
        this->willTopic=willTopic;
        this->willMessage=willMessage;
        this->cleanSession=cleanSession;
        this->keepAlivePeriod=keepAlivePeriod;
    }
    ~Client() {
        // TODO Auto-generated destructor stub
    }

    int getCleanSession() const {
        return cleanSession;
    }

    void setCleanSession(int cleanSession) {
        this->cleanSession = cleanSession;
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

    int getKeepAlivePeriod() const {
        return keepAlivePeriod;
    }

    void setKeepAlivePeriod(int keepAlivePeriod) {
        this->keepAlivePeriod = keepAlivePeriod;
    }

    const char* getProtocolName() const {
        return protocolName;
    }

    void setProtocolName(const char* protocolName = nullptr) {
        this->protocolName = protocolName;
    }

    const char* getProtocolVersion() const {
        return protocolVersion;
    }

    void setProtocolVersion(const char* protocolVersion = nullptr) {
        this->protocolVersion = protocolVersion;
    }

    int getQoS() const {
        return QoS;
    }

    void setQoS(int qoS) {
        QoS = qoS;
    }

    int getWillFlag() const {
        return willFlag;
    }

    void setWillFlag(int willFlag) {
        this->willFlag = willFlag;
    }

    const char* getWillMessage() const {
        return willMessage;
    }

    void setWillMessage(const char* willMessage = nullptr) {
        this->willMessage = willMessage;
    }

    const char* getWillTopic() const {
        return willTopic;
    }

    void setWillTopic(const char* willTopic = nullptr) {
        this->willTopic = willTopic;
    }



};

}
#endif
