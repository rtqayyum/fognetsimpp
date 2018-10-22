//
// Generated file, do not edit! Created by nedtool 4.6 from inet/applications/mqttapp/mqttMessages/MqttMsgSubscribe.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "MqttMsgSubscribe_m.h"

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

Register_Class(MqttMsgSubscribe);

MqttMsgSubscribe::MqttMsgSubscribe(const char *name, int kind) : ::cPacket(name,kind)
{
    this->clientID_var = 0;
    this->topic_var = 0;
    this->qos_var = 0;
}

MqttMsgSubscribe::MqttMsgSubscribe(const MqttMsgSubscribe& other) : ::cPacket(other)
{
    copy(other);
}

MqttMsgSubscribe::~MqttMsgSubscribe()
{
}

MqttMsgSubscribe& MqttMsgSubscribe::operator=(const MqttMsgSubscribe& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void MqttMsgSubscribe::copy(const MqttMsgSubscribe& other)
{
    this->clientID_var = other.clientID_var;
    this->topic_var = other.topic_var;
    this->qos_var = other.qos_var;
}

void MqttMsgSubscribe::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->clientID_var);
    doPacking(b,this->topic_var);
    doPacking(b,this->qos_var);
}

void MqttMsgSubscribe::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->clientID_var);
    doUnpacking(b,this->topic_var);
    doUnpacking(b,this->qos_var);
}

const char * MqttMsgSubscribe::getClientID() const
{
    return clientID_var.c_str();
}

void MqttMsgSubscribe::setClientID(const char * clientID)
{
    this->clientID_var = clientID;
}

const char * MqttMsgSubscribe::getTopic() const
{
    return topic_var.c_str();
}

void MqttMsgSubscribe::setTopic(const char * topic)
{
    this->topic_var = topic;
}

int MqttMsgSubscribe::getQos() const
{
    return qos_var;
}

void MqttMsgSubscribe::setQos(int qos)
{
    this->qos_var = qos;
}

class MqttMsgSubscribeDescriptor : public cClassDescriptor
{
  public:
    MqttMsgSubscribeDescriptor();
    virtual ~MqttMsgSubscribeDescriptor();

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

Register_ClassDescriptor(MqttMsgSubscribeDescriptor);

MqttMsgSubscribeDescriptor::MqttMsgSubscribeDescriptor() : cClassDescriptor("inet::MqttMsgSubscribe", "cPacket")
{
}

MqttMsgSubscribeDescriptor::~MqttMsgSubscribeDescriptor()
{
}

bool MqttMsgSubscribeDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<MqttMsgSubscribe *>(obj)!=NULL;
}

const char *MqttMsgSubscribeDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int MqttMsgSubscribeDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int MqttMsgSubscribeDescriptor::getFieldTypeFlags(void *object, int field) const
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
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *MqttMsgSubscribeDescriptor::getFieldName(void *object, int field) const
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
        "qos",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int MqttMsgSubscribeDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "clientID")==0) return base+0;
    if (fieldName[0]=='t' && strcmp(fieldName, "topic")==0) return base+1;
    if (fieldName[0]=='q' && strcmp(fieldName, "qos")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *MqttMsgSubscribeDescriptor::getFieldTypeString(void *object, int field) const
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
        "int",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *MqttMsgSubscribeDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int MqttMsgSubscribeDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    MqttMsgSubscribe *pp = (MqttMsgSubscribe *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string MqttMsgSubscribeDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    MqttMsgSubscribe *pp = (MqttMsgSubscribe *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getClientID());
        case 1: return oppstring2string(pp->getTopic());
        case 2: return long2string(pp->getQos());
        default: return "";
    }
}

bool MqttMsgSubscribeDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    MqttMsgSubscribe *pp = (MqttMsgSubscribe *)object; (void)pp;
    switch (field) {
        case 0: pp->setClientID((value)); return true;
        case 1: pp->setTopic((value)); return true;
        case 2: pp->setQos(string2long(value)); return true;
        default: return false;
    }
}

const char *MqttMsgSubscribeDescriptor::getFieldStructName(void *object, int field) const
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

void *MqttMsgSubscribeDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    MqttMsgSubscribe *pp = (MqttMsgSubscribe *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

} // namespace inet

