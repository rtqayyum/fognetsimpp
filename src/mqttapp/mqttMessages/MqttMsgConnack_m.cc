//
// Generated file, do not edit! Created by nedtool 4.6 from inet/applications/mqttapp/mqttMessages/MqttMsgConnack.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "MqttMsgConnack_m.h"

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

Register_Class(MqttMsgConnack);

MqttMsgConnack::MqttMsgConnack(const char *name, int kind) : ::cPacket(name,kind)
{
    this->type_var = 0;
    this->dupFlag_var = 0;
    this->qosLevel_var = 0;
    this->retain_var = 0;
    this->messageId_var = 0;
    this->sessionPresent_var = 0;
    this->returnCode_var = 0;
}

MqttMsgConnack::MqttMsgConnack(const MqttMsgConnack& other) : ::cPacket(other)
{
    copy(other);
}

MqttMsgConnack::~MqttMsgConnack()
{
}

MqttMsgConnack& MqttMsgConnack::operator=(const MqttMsgConnack& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void MqttMsgConnack::copy(const MqttMsgConnack& other)
{
    this->type_var = other.type_var;
    this->dupFlag_var = other.dupFlag_var;
    this->qosLevel_var = other.qosLevel_var;
    this->retain_var = other.retain_var;
    this->messageId_var = other.messageId_var;
    this->sessionPresent_var = other.sessionPresent_var;
    this->returnCode_var = other.returnCode_var;
}

void MqttMsgConnack::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->type_var);
    doPacking(b,this->dupFlag_var);
    doPacking(b,this->qosLevel_var);
    doPacking(b,this->retain_var);
    doPacking(b,this->messageId_var);
    doPacking(b,this->sessionPresent_var);
    doPacking(b,this->returnCode_var);
}

void MqttMsgConnack::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->type_var);
    doUnpacking(b,this->dupFlag_var);
    doUnpacking(b,this->qosLevel_var);
    doUnpacking(b,this->retain_var);
    doUnpacking(b,this->messageId_var);
    doUnpacking(b,this->sessionPresent_var);
    doUnpacking(b,this->returnCode_var);
}

const char * MqttMsgConnack::getType() const
{
    return type_var.c_str();
}

void MqttMsgConnack::setType(const char * type)
{
    this->type_var = type;
}

bool MqttMsgConnack::getDupFlag() const
{
    return dupFlag_var;
}

void MqttMsgConnack::setDupFlag(bool dupFlag)
{
    this->dupFlag_var = dupFlag;
}

int MqttMsgConnack::getQosLevel() const
{
    return qosLevel_var;
}

void MqttMsgConnack::setQosLevel(int qosLevel)
{
    this->qosLevel_var = qosLevel;
}

bool MqttMsgConnack::getRetain() const
{
    return retain_var;
}

void MqttMsgConnack::setRetain(bool retain)
{
    this->retain_var = retain;
}

const char * MqttMsgConnack::getMessageId() const
{
    return messageId_var.c_str();
}

void MqttMsgConnack::setMessageId(const char * messageId)
{
    this->messageId_var = messageId;
}

bool MqttMsgConnack::getSessionPresent() const
{
    return sessionPresent_var;
}

void MqttMsgConnack::setSessionPresent(bool sessionPresent)
{
    this->sessionPresent_var = sessionPresent;
}

int MqttMsgConnack::getReturnCode() const
{
    return returnCode_var;
}

void MqttMsgConnack::setReturnCode(int returnCode)
{
    this->returnCode_var = returnCode;
}

class MqttMsgConnackDescriptor : public cClassDescriptor
{
  public:
    MqttMsgConnackDescriptor();
    virtual ~MqttMsgConnackDescriptor();

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

Register_ClassDescriptor(MqttMsgConnackDescriptor);

MqttMsgConnackDescriptor::MqttMsgConnackDescriptor() : cClassDescriptor("inet::MqttMsgConnack", "cPacket")
{
}

MqttMsgConnackDescriptor::~MqttMsgConnackDescriptor()
{
}

bool MqttMsgConnackDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<MqttMsgConnack *>(obj)!=NULL;
}

const char *MqttMsgConnackDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int MqttMsgConnackDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount(object) : 7;
}

unsigned int MqttMsgConnackDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *MqttMsgConnackDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "type",
        "dupFlag",
        "qosLevel",
        "retain",
        "messageId",
        "sessionPresent",
        "returnCode",
    };
    return (field>=0 && field<7) ? fieldNames[field] : NULL;
}

int MqttMsgConnackDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "dupFlag")==0) return base+1;
    if (fieldName[0]=='q' && strcmp(fieldName, "qosLevel")==0) return base+2;
    if (fieldName[0]=='r' && strcmp(fieldName, "retain")==0) return base+3;
    if (fieldName[0]=='m' && strcmp(fieldName, "messageId")==0) return base+4;
    if (fieldName[0]=='s' && strcmp(fieldName, "sessionPresent")==0) return base+5;
    if (fieldName[0]=='r' && strcmp(fieldName, "returnCode")==0) return base+6;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *MqttMsgConnackDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "bool",
        "int",
        "bool",
        "string",
        "bool",
        "int",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : NULL;
}

const char *MqttMsgConnackDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int MqttMsgConnackDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    MqttMsgConnack *pp = (MqttMsgConnack *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string MqttMsgConnackDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    MqttMsgConnack *pp = (MqttMsgConnack *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getType());
        case 1: return bool2string(pp->getDupFlag());
        case 2: return long2string(pp->getQosLevel());
        case 3: return bool2string(pp->getRetain());
        case 4: return oppstring2string(pp->getMessageId());
        case 5: return bool2string(pp->getSessionPresent());
        case 6: return long2string(pp->getReturnCode());
        default: return "";
    }
}

bool MqttMsgConnackDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    MqttMsgConnack *pp = (MqttMsgConnack *)object; (void)pp;
    switch (field) {
        case 0: pp->setType((value)); return true;
        case 1: pp->setDupFlag(string2bool(value)); return true;
        case 2: pp->setQosLevel(string2long(value)); return true;
        case 3: pp->setRetain(string2bool(value)); return true;
        case 4: pp->setMessageId((value)); return true;
        case 5: pp->setSessionPresent(string2bool(value)); return true;
        case 6: pp->setReturnCode(string2long(value)); return true;
        default: return false;
    }
}

const char *MqttMsgConnackDescriptor::getFieldStructName(void *object, int field) const
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

void *MqttMsgConnackDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    MqttMsgConnack *pp = (MqttMsgConnack *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

} // namespace inet

