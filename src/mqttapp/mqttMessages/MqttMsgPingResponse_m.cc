//
// Generated file, do not edit! Created by nedtool 4.6 from inet/applications/mqttapp/mqttMessages/MqttMsgPingResponse.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "MqttMsgPingResponse_m.h"

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

Register_Class(MqttMsgPingResponse);

MqttMsgPingResponse::MqttMsgPingResponse(const char *name, int kind) : ::cPacket(name,kind)
{
    this->messageID_var = 0;
    this->bytes_var = 0;
    this->status_var = 0;
}

MqttMsgPingResponse::MqttMsgPingResponse(const MqttMsgPingResponse& other) : ::cPacket(other)
{
    copy(other);
}

MqttMsgPingResponse::~MqttMsgPingResponse()
{
}

MqttMsgPingResponse& MqttMsgPingResponse::operator=(const MqttMsgPingResponse& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void MqttMsgPingResponse::copy(const MqttMsgPingResponse& other)
{
    this->messageID_var = other.messageID_var;
    this->bytes_var = other.bytes_var;
    this->status_var = other.status_var;
}

void MqttMsgPingResponse::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->messageID_var);
    doPacking(b,this->bytes_var);
    doPacking(b,this->status_var);
}

void MqttMsgPingResponse::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->messageID_var);
    doUnpacking(b,this->bytes_var);
    doUnpacking(b,this->status_var);
}

const char * MqttMsgPingResponse::getMessageID() const
{
    return messageID_var.c_str();
}

void MqttMsgPingResponse::setMessageID(const char * messageID)
{
    this->messageID_var = messageID;
}

int MqttMsgPingResponse::getBytes() const
{
    return bytes_var;
}

void MqttMsgPingResponse::setBytes(int bytes)
{
    this->bytes_var = bytes;
}

int MqttMsgPingResponse::getStatus() const
{
    return status_var;
}

void MqttMsgPingResponse::setStatus(int status)
{
    this->status_var = status;
}

class MqttMsgPingResponseDescriptor : public cClassDescriptor
{
  public:
    MqttMsgPingResponseDescriptor();
    virtual ~MqttMsgPingResponseDescriptor();

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

Register_ClassDescriptor(MqttMsgPingResponseDescriptor);

MqttMsgPingResponseDescriptor::MqttMsgPingResponseDescriptor() : cClassDescriptor("inet::MqttMsgPingResponse", "cPacket")
{
}

MqttMsgPingResponseDescriptor::~MqttMsgPingResponseDescriptor()
{
}

bool MqttMsgPingResponseDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<MqttMsgPingResponse *>(obj)!=NULL;
}

const char *MqttMsgPingResponseDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int MqttMsgPingResponseDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int MqttMsgPingResponseDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *MqttMsgPingResponseDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "messageID",
        "bytes",
        "status",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int MqttMsgPingResponseDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='m' && strcmp(fieldName, "messageID")==0) return base+0;
    if (fieldName[0]=='b' && strcmp(fieldName, "bytes")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "status")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *MqttMsgPingResponseDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "int",
        "int",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *MqttMsgPingResponseDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int MqttMsgPingResponseDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    MqttMsgPingResponse *pp = (MqttMsgPingResponse *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string MqttMsgPingResponseDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    MqttMsgPingResponse *pp = (MqttMsgPingResponse *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getMessageID());
        case 1: return long2string(pp->getBytes());
        case 2: return long2string(pp->getStatus());
        default: return "";
    }
}

bool MqttMsgPingResponseDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    MqttMsgPingResponse *pp = (MqttMsgPingResponse *)object; (void)pp;
    switch (field) {
        case 0: pp->setMessageID((value)); return true;
        case 1: pp->setBytes(string2long(value)); return true;
        case 2: pp->setStatus(string2long(value)); return true;
        default: return false;
    }
}

const char *MqttMsgPingResponseDescriptor::getFieldStructName(void *object, int field) const
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

void *MqttMsgPingResponseDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    MqttMsgPingResponse *pp = (MqttMsgPingResponse *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

} // namespace inet

