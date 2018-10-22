//
// Generated file, do not edit! Created by nedtool 4.6 from inet/applications/mqttapp/mqttMessages/MqttMsgConnect.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "MqttMsgConnect_m.h"

USING_NAMESPACE


// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}



namespace inet {

// Template rule for outputting std::vector<T> types
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

Register_Class(MqttMsgConnect);

MqttMsgConnect::MqttMsgConnect(const char *name, int kind) : ::cPacket(name,kind)
{
    this->expectedReplyLength_var = 0;
    this->replyDelay_var = 0;
    this->serverClose_var = 0;
    this->type_var = 0;
    this->dupFlag_var = 0;
    this->qosLevel_var = 0;
    this->retain_var = 0;
    this->messageId_var = 0;
    this->protocolName_var = 0;
    this->protocolVersion_var = 0;
    this->clientId_var = 0;
    this->willRetain_var = 0;
    this->willQosLevel_var = 0;
    this->willFlag_var = 0;
    this->willTopic_var = 0;
    this->willMessage_var = 0;
    this->username_var = 0;
    this->password_var = 0;
    this->cleanSession_var = 0;
    this->keepAlivePeriod_var = 0;
    this->isBroker_var = 0;
}

MqttMsgConnect::MqttMsgConnect(const MqttMsgConnect& other) : ::cPacket(other)
{
    copy(other);
}

MqttMsgConnect::~MqttMsgConnect()
{
}

MqttMsgConnect& MqttMsgConnect::operator=(const MqttMsgConnect& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void MqttMsgConnect::copy(const MqttMsgConnect& other)
{
    this->expectedReplyLength_var = other.expectedReplyLength_var;
    this->replyDelay_var = other.replyDelay_var;
    this->serverClose_var = other.serverClose_var;
    this->type_var = other.type_var;
    this->dupFlag_var = other.dupFlag_var;
    this->qosLevel_var = other.qosLevel_var;
    this->retain_var = other.retain_var;
    this->messageId_var = other.messageId_var;
    this->protocolName_var = other.protocolName_var;
    this->protocolVersion_var = other.protocolVersion_var;
    this->clientId_var = other.clientId_var;
    this->willRetain_var = other.willRetain_var;
    this->willQosLevel_var = other.willQosLevel_var;
    this->willFlag_var = other.willFlag_var;
    this->willTopic_var = other.willTopic_var;
    this->willMessage_var = other.willMessage_var;
    this->username_var = other.username_var;
    this->password_var = other.password_var;
    this->cleanSession_var = other.cleanSession_var;
    this->keepAlivePeriod_var = other.keepAlivePeriod_var;
    this->isBroker_var = other.isBroker_var;
}

void MqttMsgConnect::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->expectedReplyLength_var);
    doPacking(b,this->replyDelay_var);
    doPacking(b,this->serverClose_var);
    doPacking(b,this->type_var);
    doPacking(b,this->dupFlag_var);
    doPacking(b,this->qosLevel_var);
    doPacking(b,this->retain_var);
    doPacking(b,this->messageId_var);
    doPacking(b,this->protocolName_var);
    doPacking(b,this->protocolVersion_var);
    doPacking(b,this->clientId_var);
    doPacking(b,this->willRetain_var);
    doPacking(b,this->willQosLevel_var);
    doPacking(b,this->willFlag_var);
    doPacking(b,this->willTopic_var);
    doPacking(b,this->willMessage_var);
    doPacking(b,this->username_var);
    doPacking(b,this->password_var);
    doPacking(b,this->cleanSession_var);
    doPacking(b,this->keepAlivePeriod_var);
    doPacking(b,this->isBroker_var);
}

void MqttMsgConnect::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->expectedReplyLength_var);
    doUnpacking(b,this->replyDelay_var);
    doUnpacking(b,this->serverClose_var);
    doUnpacking(b,this->type_var);
    doUnpacking(b,this->dupFlag_var);
    doUnpacking(b,this->qosLevel_var);
    doUnpacking(b,this->retain_var);
    doUnpacking(b,this->messageId_var);
    doUnpacking(b,this->protocolName_var);
    doUnpacking(b,this->protocolVersion_var);
    doUnpacking(b,this->clientId_var);
    doUnpacking(b,this->willRetain_var);
    doUnpacking(b,this->willQosLevel_var);
    doUnpacking(b,this->willFlag_var);
    doUnpacking(b,this->willTopic_var);
    doUnpacking(b,this->willMessage_var);
    doUnpacking(b,this->username_var);
    doUnpacking(b,this->password_var);
    doUnpacking(b,this->cleanSession_var);
    doUnpacking(b,this->keepAlivePeriod_var);
    doUnpacking(b,this->isBroker_var);
}

int MqttMsgConnect::getExpectedReplyLength() const
{
    return expectedReplyLength_var;
}

void MqttMsgConnect::setExpectedReplyLength(int expectedReplyLength)
{
    this->expectedReplyLength_var = expectedReplyLength;
}

double MqttMsgConnect::getReplyDelay() const
{
    return replyDelay_var;
}

void MqttMsgConnect::setReplyDelay(double replyDelay)
{
    this->replyDelay_var = replyDelay;
}

bool MqttMsgConnect::getServerClose() const
{
    return serverClose_var;
}

void MqttMsgConnect::setServerClose(bool serverClose)
{
    this->serverClose_var = serverClose;
}

const char * MqttMsgConnect::getType() const
{
    return type_var.c_str();
}

void MqttMsgConnect::setType(const char * type)
{
    this->type_var = type;
}

bool MqttMsgConnect::getDupFlag() const
{
    return dupFlag_var;
}

void MqttMsgConnect::setDupFlag(bool dupFlag)
{
    this->dupFlag_var = dupFlag;
}

int MqttMsgConnect::getQosLevel() const
{
    return qosLevel_var;
}

void MqttMsgConnect::setQosLevel(int qosLevel)
{
    this->qosLevel_var = qosLevel;
}

bool MqttMsgConnect::getRetain() const
{
    return retain_var;
}

void MqttMsgConnect::setRetain(bool retain)
{
    this->retain_var = retain;
}

const char * MqttMsgConnect::getMessageId() const
{
    return messageId_var.c_str();
}

void MqttMsgConnect::setMessageId(const char * messageId)
{
    this->messageId_var = messageId;
}

const char * MqttMsgConnect::getProtocolName() const
{
    return protocolName_var.c_str();
}

void MqttMsgConnect::setProtocolName(const char * protocolName)
{
    this->protocolName_var = protocolName;
}

const char * MqttMsgConnect::getProtocolVersion() const
{
    return protocolVersion_var.c_str();
}

void MqttMsgConnect::setProtocolVersion(const char * protocolVersion)
{
    this->protocolVersion_var = protocolVersion;
}

const char * MqttMsgConnect::getClientId() const
{
    return clientId_var.c_str();
}

void MqttMsgConnect::setClientId(const char * clientId)
{
    this->clientId_var = clientId;
}

bool MqttMsgConnect::getWillRetain() const
{
    return willRetain_var;
}

void MqttMsgConnect::setWillRetain(bool willRetain)
{
    this->willRetain_var = willRetain;
}

const char * MqttMsgConnect::getWillQosLevel() const
{
    return willQosLevel_var.c_str();
}

void MqttMsgConnect::setWillQosLevel(const char * willQosLevel)
{
    this->willQosLevel_var = willQosLevel;
}

bool MqttMsgConnect::getWillFlag() const
{
    return willFlag_var;
}

void MqttMsgConnect::setWillFlag(bool willFlag)
{
    this->willFlag_var = willFlag;
}

const char * MqttMsgConnect::getWillTopic() const
{
    return willTopic_var.c_str();
}

void MqttMsgConnect::setWillTopic(const char * willTopic)
{
    this->willTopic_var = willTopic;
}

const char * MqttMsgConnect::getWillMessage() const
{
    return willMessage_var.c_str();
}

void MqttMsgConnect::setWillMessage(const char * willMessage)
{
    this->willMessage_var = willMessage;
}

const char * MqttMsgConnect::getUsername() const
{
    return username_var.c_str();
}

void MqttMsgConnect::setUsername(const char * username)
{
    this->username_var = username;
}

const char * MqttMsgConnect::getPassword() const
{
    return password_var.c_str();
}

void MqttMsgConnect::setPassword(const char * password)
{
    this->password_var = password;
}

bool MqttMsgConnect::getCleanSession() const
{
    return cleanSession_var;
}

void MqttMsgConnect::setCleanSession(bool cleanSession)
{
    this->cleanSession_var = cleanSession;
}

unsigned short MqttMsgConnect::getKeepAlivePeriod() const
{
    return keepAlivePeriod_var;
}

void MqttMsgConnect::setKeepAlivePeriod(unsigned short keepAlivePeriod)
{
    this->keepAlivePeriod_var = keepAlivePeriod;
}

bool MqttMsgConnect::getIsBroker() const
{
    return isBroker_var;
}

void MqttMsgConnect::setIsBroker(bool isBroker)
{
    this->isBroker_var = isBroker;
}

class MqttMsgConnectDescriptor : public cClassDescriptor
{
  public:
    MqttMsgConnectDescriptor();
    virtual ~MqttMsgConnectDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(MqttMsgConnectDescriptor);

MqttMsgConnectDescriptor::MqttMsgConnectDescriptor() : cClassDescriptor("inet::MqttMsgConnect", "cPacket")
{
}

MqttMsgConnectDescriptor::~MqttMsgConnectDescriptor()
{
}

bool MqttMsgConnectDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<MqttMsgConnect *>(obj)!=NULL;
}

const char *MqttMsgConnectDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int MqttMsgConnectDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 21+basedesc->getFieldCount(object) : 21;
}

unsigned int MqttMsgConnectDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<21) ? fieldTypeFlags[field] : 0;
}

const char *MqttMsgConnectDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "expectedReplyLength",
        "replyDelay",
        "serverClose",
        "type",
        "dupFlag",
        "qosLevel",
        "retain",
        "messageId",
        "protocolName",
        "protocolVersion",
        "clientId",
        "willRetain",
        "willQosLevel",
        "willFlag",
        "willTopic",
        "willMessage",
        "username",
        "password",
        "cleanSession",
        "keepAlivePeriod",
        "isBroker",
    };
    return (field>=0 && field<21) ? fieldNames[field] : NULL;
}

int MqttMsgConnectDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='e' && strcmp(fieldName, "expectedReplyLength")==0) return base+0;
    if (fieldName[0]=='r' && strcmp(fieldName, "replyDelay")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "serverClose")==0) return base+2;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+3;
    if (fieldName[0]=='d' && strcmp(fieldName, "dupFlag")==0) return base+4;
    if (fieldName[0]=='q' && strcmp(fieldName, "qosLevel")==0) return base+5;
    if (fieldName[0]=='r' && strcmp(fieldName, "retain")==0) return base+6;
    if (fieldName[0]=='m' && strcmp(fieldName, "messageId")==0) return base+7;
    if (fieldName[0]=='p' && strcmp(fieldName, "protocolName")==0) return base+8;
    if (fieldName[0]=='p' && strcmp(fieldName, "protocolVersion")==0) return base+9;
    if (fieldName[0]=='c' && strcmp(fieldName, "clientId")==0) return base+10;
    if (fieldName[0]=='w' && strcmp(fieldName, "willRetain")==0) return base+11;
    if (fieldName[0]=='w' && strcmp(fieldName, "willQosLevel")==0) return base+12;
    if (fieldName[0]=='w' && strcmp(fieldName, "willFlag")==0) return base+13;
    if (fieldName[0]=='w' && strcmp(fieldName, "willTopic")==0) return base+14;
    if (fieldName[0]=='w' && strcmp(fieldName, "willMessage")==0) return base+15;
    if (fieldName[0]=='u' && strcmp(fieldName, "username")==0) return base+16;
    if (fieldName[0]=='p' && strcmp(fieldName, "password")==0) return base+17;
    if (fieldName[0]=='c' && strcmp(fieldName, "cleanSession")==0) return base+18;
    if (fieldName[0]=='k' && strcmp(fieldName, "keepAlivePeriod")==0) return base+19;
    if (fieldName[0]=='i' && strcmp(fieldName, "isBroker")==0) return base+20;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *MqttMsgConnectDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "double",
        "bool",
        "string",
        "bool",
        "int",
        "bool",
        "string",
        "string",
        "string",
        "string",
        "bool",
        "string",
        "bool",
        "string",
        "string",
        "string",
        "string",
        "bool",
        "unsigned short",
        "bool",
    };
    return (field>=0 && field<21) ? fieldTypeStrings[field] : NULL;
}

const char *MqttMsgConnectDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int MqttMsgConnectDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    MqttMsgConnect *pp = (MqttMsgConnect *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string MqttMsgConnectDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    MqttMsgConnect *pp = (MqttMsgConnect *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getExpectedReplyLength());
        case 1: return double2string(pp->getReplyDelay());
        case 2: return bool2string(pp->getServerClose());
        case 3: return oppstring2string(pp->getType());
        case 4: return bool2string(pp->getDupFlag());
        case 5: return long2string(pp->getQosLevel());
        case 6: return bool2string(pp->getRetain());
        case 7: return oppstring2string(pp->getMessageId());
        case 8: return oppstring2string(pp->getProtocolName());
        case 9: return oppstring2string(pp->getProtocolVersion());
        case 10: return oppstring2string(pp->getClientId());
        case 11: return bool2string(pp->getWillRetain());
        case 12: return oppstring2string(pp->getWillQosLevel());
        case 13: return bool2string(pp->getWillFlag());
        case 14: return oppstring2string(pp->getWillTopic());
        case 15: return oppstring2string(pp->getWillMessage());
        case 16: return oppstring2string(pp->getUsername());
        case 17: return oppstring2string(pp->getPassword());
        case 18: return bool2string(pp->getCleanSession());
        case 19: return ulong2string(pp->getKeepAlivePeriod());
        case 20: return bool2string(pp->getIsBroker());
        default: return "";
    }
}

bool MqttMsgConnectDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    MqttMsgConnect *pp = (MqttMsgConnect *)object; (void)pp;
    switch (field) {
        case 0: pp->setExpectedReplyLength(string2long(value)); return true;
        case 1: pp->setReplyDelay(string2double(value)); return true;
        case 2: pp->setServerClose(string2bool(value)); return true;
        case 3: pp->setType((value)); return true;
        case 4: pp->setDupFlag(string2bool(value)); return true;
        case 5: pp->setQosLevel(string2long(value)); return true;
        case 6: pp->setRetain(string2bool(value)); return true;
        case 7: pp->setMessageId((value)); return true;
        case 8: pp->setProtocolName((value)); return true;
        case 9: pp->setProtocolVersion((value)); return true;
        case 10: pp->setClientId((value)); return true;
        case 11: pp->setWillRetain(string2bool(value)); return true;
        case 12: pp->setWillQosLevel((value)); return true;
        case 13: pp->setWillFlag(string2bool(value)); return true;
        case 14: pp->setWillTopic((value)); return true;
        case 15: pp->setWillMessage((value)); return true;
        case 16: pp->setUsername((value)); return true;
        case 17: pp->setPassword((value)); return true;
        case 18: pp->setCleanSession(string2bool(value)); return true;
        case 19: pp->setKeepAlivePeriod(string2ulong(value)); return true;
        case 20: pp->setIsBroker(string2bool(value)); return true;
        default: return false;
    }
}

const char *MqttMsgConnectDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *MqttMsgConnectDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    MqttMsgConnect *pp = (MqttMsgConnect *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

} // namespace inet

