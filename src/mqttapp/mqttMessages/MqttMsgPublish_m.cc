//
// Generated file, do not edit! Created by nedtool 4.6 from inet/applications/mqttapp/mqttMessages/MqttMsgPublish.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "MqttMsgPublish_m.h"

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

Register_Class(MqttMsgPublish);

MqttMsgPublish::MqttMsgPublish(const char *name, int kind) : ::cPacket(name,kind)
{
    this->clientID_var = 0;
    this->topic_var = 0;
    this->mqttMessage_var = 0;
    this->qoS_var = 0;
    this->MIPSRequired_var = 0;
    this->requiredTime_var = 0;
    this->messageID_var = 0;
}

MqttMsgPublish::MqttMsgPublish(const MqttMsgPublish& other) : ::cPacket(other)
{
    copy(other);
}

MqttMsgPublish::~MqttMsgPublish()
{
}

MqttMsgPublish& MqttMsgPublish::operator=(const MqttMsgPublish& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void MqttMsgPublish::copy(const MqttMsgPublish& other)
{
    this->clientID_var = other.clientID_var;
    this->topic_var = other.topic_var;
    this->mqttMessage_var = other.mqttMessage_var;
    this->qoS_var = other.qoS_var;
    this->MIPSRequired_var = other.MIPSRequired_var;
    this->requiredTime_var = other.requiredTime_var;
    this->messageID_var = other.messageID_var;
}

void MqttMsgPublish::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->clientID_var);
    doPacking(b,this->topic_var);
    doPacking(b,this->mqttMessage_var);
    doPacking(b,this->qoS_var);
    doPacking(b,this->MIPSRequired_var);
    doPacking(b,this->requiredTime_var);
    doPacking(b,this->messageID_var);
}

void MqttMsgPublish::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->clientID_var);
    doUnpacking(b,this->topic_var);
    doUnpacking(b,this->mqttMessage_var);
    doUnpacking(b,this->qoS_var);
    doUnpacking(b,this->MIPSRequired_var);
    doUnpacking(b,this->requiredTime_var);
    doUnpacking(b,this->messageID_var);
}

const char * MqttMsgPublish::getClientID() const
{
    return clientID_var.c_str();
}

void MqttMsgPublish::setClientID(const char * clientID)
{
    this->clientID_var = clientID;
}

const char * MqttMsgPublish::getTopic() const
{
    return topic_var.c_str();
}

void MqttMsgPublish::setTopic(const char * topic)
{
    this->topic_var = topic;
}

const char * MqttMsgPublish::getMqttMessage() const
{
    return mqttMessage_var.c_str();
}

void MqttMsgPublish::setMqttMessage(const char * mqttMessage)
{
    this->mqttMessage_var = mqttMessage;
}

int MqttMsgPublish::getQoS() const
{
    return qoS_var;
}

void MqttMsgPublish::setQoS(int qoS)
{
    this->qoS_var = qoS;
}

int MqttMsgPublish::getMIPSRequired() const
{
    return MIPSRequired_var;
}

void MqttMsgPublish::setMIPSRequired(int MIPSRequired)
{
    this->MIPSRequired_var = MIPSRequired;
}

double MqttMsgPublish::getRequiredTime() const
{
    return requiredTime_var;
}

void MqttMsgPublish::setRequiredTime(double requiredTime)
{
    this->requiredTime_var = requiredTime;
}

const char * MqttMsgPublish::getMessageID() const
{
    return messageID_var.c_str();
}

void MqttMsgPublish::setMessageID(const char * messageID)
{
    this->messageID_var = messageID;
}

class MqttMsgPublishDescriptor : public cClassDescriptor
{
  public:
    MqttMsgPublishDescriptor();
    virtual ~MqttMsgPublishDescriptor();

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

Register_ClassDescriptor(MqttMsgPublishDescriptor);

MqttMsgPublishDescriptor::MqttMsgPublishDescriptor() : cClassDescriptor("inet::MqttMsgPublish", "cPacket")
{
}

MqttMsgPublishDescriptor::~MqttMsgPublishDescriptor()
{
}

bool MqttMsgPublishDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<MqttMsgPublish *>(obj)!=NULL;
}

const char *MqttMsgPublishDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int MqttMsgPublishDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount(object) : 7;
}

unsigned int MqttMsgPublishDescriptor::getFieldTypeFlags(void *object, int field) const
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
    };
    return (field>=0 && field<7) ? fieldTypeFlags[field] : 0;
}

const char *MqttMsgPublishDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "clientID",
        "topic",
        "mqttMessage",
        "qoS",
        "MIPSRequired",
        "requiredTime",
        "messageID",
    };
    return (field>=0 && field<7) ? fieldNames[field] : NULL;
}

int MqttMsgPublishDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "clientID")==0) return base+0;
    if (fieldName[0]=='t' && strcmp(fieldName, "topic")==0) return base+1;
    if (fieldName[0]=='m' && strcmp(fieldName, "mqttMessage")==0) return base+2;
    if (fieldName[0]=='q' && strcmp(fieldName, "qoS")==0) return base+3;
    if (fieldName[0]=='M' && strcmp(fieldName, "MIPSRequired")==0) return base+4;
    if (fieldName[0]=='r' && strcmp(fieldName, "requiredTime")==0) return base+5;
    if (fieldName[0]=='m' && strcmp(fieldName, "messageID")==0) return base+6;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *MqttMsgPublishDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "string",
        "string",
        "int",
        "int",
        "double",
        "string",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : NULL;
}

const char *MqttMsgPublishDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int MqttMsgPublishDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    MqttMsgPublish *pp = (MqttMsgPublish *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string MqttMsgPublishDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    MqttMsgPublish *pp = (MqttMsgPublish *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getClientID());
        case 1: return oppstring2string(pp->getTopic());
        case 2: return oppstring2string(pp->getMqttMessage());
        case 3: return long2string(pp->getQoS());
        case 4: return long2string(pp->getMIPSRequired());
        case 5: return double2string(pp->getRequiredTime());
        case 6: return oppstring2string(pp->getMessageID());
        default: return "";
    }
}

bool MqttMsgPublishDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    MqttMsgPublish *pp = (MqttMsgPublish *)object; (void)pp;
    switch (field) {
        case 0: pp->setClientID((value)); return true;
        case 1: pp->setTopic((value)); return true;
        case 2: pp->setMqttMessage((value)); return true;
        case 3: pp->setQoS(string2long(value)); return true;
        case 4: pp->setMIPSRequired(string2long(value)); return true;
        case 5: pp->setRequiredTime(string2double(value)); return true;
        case 6: pp->setMessageID((value)); return true;
        default: return false;
    }
}

const char *MqttMsgPublishDescriptor::getFieldStructName(void *object, int field) const
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

void *MqttMsgPublishDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    MqttMsgPublish *pp = (MqttMsgPublish *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

} // namespace inet

