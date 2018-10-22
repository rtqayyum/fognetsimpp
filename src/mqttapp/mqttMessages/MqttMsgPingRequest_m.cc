//
// Generated file, do not edit! Created by nedtool 4.6 from inet/applications/mqttapp/mqttMessages/MqttMsgPingRequest.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "MqttMsgPingRequest_m.h"

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

Register_Class(MqttMsgPingRequest);

MqttMsgPingRequest::MqttMsgPingRequest(const char *name, int kind) : ::cPacket(name,kind)
{
    this->qos_var = 0;
    this->messageID_var = 0;
    this->clientId_var = 0;
    this->bytes_var = 0;
}

MqttMsgPingRequest::MqttMsgPingRequest(const MqttMsgPingRequest& other) : ::cPacket(other)
{
    copy(other);
}

MqttMsgPingRequest::~MqttMsgPingRequest()
{
}

MqttMsgPingRequest& MqttMsgPingRequest::operator=(const MqttMsgPingRequest& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void MqttMsgPingRequest::copy(const MqttMsgPingRequest& other)
{
    this->qos_var = other.qos_var;
    this->messageID_var = other.messageID_var;
    this->clientId_var = other.clientId_var;
    this->bytes_var = other.bytes_var;
}

void MqttMsgPingRequest::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->qos_var);
    doPacking(b,this->messageID_var);
    doPacking(b,this->clientId_var);
    doPacking(b,this->bytes_var);
}

void MqttMsgPingRequest::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->qos_var);
    doUnpacking(b,this->messageID_var);
    doUnpacking(b,this->clientId_var);
    doUnpacking(b,this->bytes_var);
}

int MqttMsgPingRequest::getQos() const
{
    return qos_var;
}

void MqttMsgPingRequest::setQos(int qos)
{
    this->qos_var = qos;
}

const char * MqttMsgPingRequest::getMessageID() const
{
    return messageID_var.c_str();
}

void MqttMsgPingRequest::setMessageID(const char * messageID)
{
    this->messageID_var = messageID;
}

const char * MqttMsgPingRequest::getClientId() const
{
    return clientId_var.c_str();
}

void MqttMsgPingRequest::setClientId(const char * clientId)
{
    this->clientId_var = clientId;
}

int MqttMsgPingRequest::getBytes() const
{
    return bytes_var;
}

void MqttMsgPingRequest::setBytes(int bytes)
{
    this->bytes_var = bytes;
}

class MqttMsgPingRequestDescriptor : public cClassDescriptor
{
  public:
    MqttMsgPingRequestDescriptor();
    virtual ~MqttMsgPingRequestDescriptor();

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

Register_ClassDescriptor(MqttMsgPingRequestDescriptor);

MqttMsgPingRequestDescriptor::MqttMsgPingRequestDescriptor() : cClassDescriptor("inet::MqttMsgPingRequest", "cPacket")
{
}

MqttMsgPingRequestDescriptor::~MqttMsgPingRequestDescriptor()
{
}

bool MqttMsgPingRequestDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<MqttMsgPingRequest *>(obj)!=NULL;
}

const char *MqttMsgPingRequestDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int MqttMsgPingRequestDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount(object) : 4;
}

unsigned int MqttMsgPingRequestDescriptor::getFieldTypeFlags(void *object, int field) const
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
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *MqttMsgPingRequestDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "qos",
        "messageID",
        "clientId",
        "bytes",
    };
    return (field>=0 && field<4) ? fieldNames[field] : NULL;
}

int MqttMsgPingRequestDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='q' && strcmp(fieldName, "qos")==0) return base+0;
    if (fieldName[0]=='m' && strcmp(fieldName, "messageID")==0) return base+1;
    if (fieldName[0]=='c' && strcmp(fieldName, "clientId")==0) return base+2;
    if (fieldName[0]=='b' && strcmp(fieldName, "bytes")==0) return base+3;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *MqttMsgPingRequestDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "string",
        "string",
        "int",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : NULL;
}

const char *MqttMsgPingRequestDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int MqttMsgPingRequestDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    MqttMsgPingRequest *pp = (MqttMsgPingRequest *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string MqttMsgPingRequestDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    MqttMsgPingRequest *pp = (MqttMsgPingRequest *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getQos());
        case 1: return oppstring2string(pp->getMessageID());
        case 2: return oppstring2string(pp->getClientId());
        case 3: return long2string(pp->getBytes());
        default: return "";
    }
}

bool MqttMsgPingRequestDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    MqttMsgPingRequest *pp = (MqttMsgPingRequest *)object; (void)pp;
    switch (field) {
        case 0: pp->setQos(string2long(value)); return true;
        case 1: pp->setMessageID((value)); return true;
        case 2: pp->setClientId((value)); return true;
        case 3: pp->setBytes(string2long(value)); return true;
        default: return false;
    }
}

const char *MqttMsgPingRequestDescriptor::getFieldStructName(void *object, int field) const
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

void *MqttMsgPingRequestDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    MqttMsgPingRequest *pp = (MqttMsgPingRequest *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

} // namespace inet

