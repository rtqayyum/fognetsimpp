//
// Generated file, do not edit! Created by nedtool 4.6 from inet/applications/mqttapp/mqttMessages/MqttMsgBase.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "MqttMsgBase_m.h"

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

MqttMsgBase_Base::MqttMsgBase_Base(const char *name, int kind) : ::cPacket(name,kind)
{
}

MqttMsgBase_Base::MqttMsgBase_Base(const MqttMsgBase_Base& other) : ::cPacket(other)
{
    copy(other);
}

MqttMsgBase_Base::~MqttMsgBase_Base()
{
}

MqttMsgBase_Base& MqttMsgBase_Base::operator=(const MqttMsgBase_Base& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void MqttMsgBase_Base::copy(const MqttMsgBase_Base& other)
{
}

void MqttMsgBase_Base::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    // field type is abstract -- please do packing in customized class
    // field dupFlag is abstract -- please do packing in customized class
    // field qosLevel is abstract -- please do packing in customized class
    // field retain is abstract -- please do packing in customized class
    // field messageId is abstract -- please do packing in customized class
}

void MqttMsgBase_Base::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    // field type is abstract -- please do unpacking in customized class
    // field dupFlag is abstract -- please do unpacking in customized class
    // field qosLevel is abstract -- please do unpacking in customized class
    // field retain is abstract -- please do unpacking in customized class
    // field messageId is abstract -- please do unpacking in customized class
}

class MqttMsgBaseDescriptor : public cClassDescriptor
{
  public:
    MqttMsgBaseDescriptor();
    virtual ~MqttMsgBaseDescriptor();

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

Register_ClassDescriptor(MqttMsgBaseDescriptor);

MqttMsgBaseDescriptor::MqttMsgBaseDescriptor() : cClassDescriptor("inet::MqttMsgBase", "cPacket")
{
}

MqttMsgBaseDescriptor::~MqttMsgBaseDescriptor()
{
}

bool MqttMsgBaseDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<MqttMsgBase_Base *>(obj)!=NULL;
}

const char *MqttMsgBaseDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"customize")) return "true";
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int MqttMsgBaseDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount(object) : 5;
}

unsigned int MqttMsgBaseDescriptor::getFieldTypeFlags(void *object, int field) const
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
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *MqttMsgBaseDescriptor::getFieldName(void *object, int field) const
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
    };
    return (field>=0 && field<5) ? fieldNames[field] : NULL;
}

int MqttMsgBaseDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "dupFlag")==0) return base+1;
    if (fieldName[0]=='q' && strcmp(fieldName, "qosLevel")==0) return base+2;
    if (fieldName[0]=='r' && strcmp(fieldName, "retain")==0) return base+3;
    if (fieldName[0]=='m' && strcmp(fieldName, "messageId")==0) return base+4;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *MqttMsgBaseDescriptor::getFieldTypeString(void *object, int field) const
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
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : NULL;
}

const char *MqttMsgBaseDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int MqttMsgBaseDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    MqttMsgBase_Base *pp = (MqttMsgBase_Base *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string MqttMsgBaseDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    MqttMsgBase_Base *pp = (MqttMsgBase_Base *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getType());
        case 1: return bool2string(pp->getDupFlag());
        case 2: return long2string(pp->getQosLevel());
        case 3: return bool2string(pp->getRetain());
        case 4: return oppstring2string(pp->getMessageId());
        default: return "";
    }
}

bool MqttMsgBaseDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    MqttMsgBase_Base *pp = (MqttMsgBase_Base *)object; (void)pp;
    switch (field) {
        case 0: pp->setType((value)); return true;
        case 1: pp->setDupFlag(string2bool(value)); return true;
        case 2: pp->setQosLevel(string2long(value)); return true;
        case 3: pp->setRetain(string2bool(value)); return true;
        case 4: pp->setMessageId((value)); return true;
        default: return false;
    }
}

const char *MqttMsgBaseDescriptor::getFieldStructName(void *object, int field) const
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

void *MqttMsgBaseDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    MqttMsgBase_Base *pp = (MqttMsgBase_Base *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

} // namespace inet

