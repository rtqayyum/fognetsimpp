//
// Generated file, do not edit! Created by nedtool 4.6 from inet/applications/mqttapp/fognetMessages/FognetMsgAdvertiseMIPS.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "FognetMsgAdvertiseMIPS_m.h"

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

Register_Class(FognetMsgAdvertiseMIPS);

FognetMsgAdvertiseMIPS::FognetMsgAdvertiseMIPS(const char *name, int kind) : ::cPacket(name,kind)
{
    this->MIPS_var = 0;
    this->computeBrokerID_var = 0;
    this->busyTime_var = 0;
}

FognetMsgAdvertiseMIPS::FognetMsgAdvertiseMIPS(const FognetMsgAdvertiseMIPS& other) : ::cPacket(other)
{
    copy(other);
}

FognetMsgAdvertiseMIPS::~FognetMsgAdvertiseMIPS()
{
}

FognetMsgAdvertiseMIPS& FognetMsgAdvertiseMIPS::operator=(const FognetMsgAdvertiseMIPS& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void FognetMsgAdvertiseMIPS::copy(const FognetMsgAdvertiseMIPS& other)
{
    this->MIPS_var = other.MIPS_var;
    this->computeBrokerID_var = other.computeBrokerID_var;
    this->busyTime_var = other.busyTime_var;
}

void FognetMsgAdvertiseMIPS::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->MIPS_var);
    doPacking(b,this->computeBrokerID_var);
    doPacking(b,this->busyTime_var);
}

void FognetMsgAdvertiseMIPS::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->MIPS_var);
    doUnpacking(b,this->computeBrokerID_var);
    doUnpacking(b,this->busyTime_var);
}

int FognetMsgAdvertiseMIPS::getMIPS() const
{
    return MIPS_var;
}

void FognetMsgAdvertiseMIPS::setMIPS(int MIPS)
{
    this->MIPS_var = MIPS;
}

const char * FognetMsgAdvertiseMIPS::getComputeBrokerID() const
{
    return computeBrokerID_var.c_str();
}

void FognetMsgAdvertiseMIPS::setComputeBrokerID(const char * computeBrokerID)
{
    this->computeBrokerID_var = computeBrokerID;
}

double FognetMsgAdvertiseMIPS::getBusyTime() const
{
    return busyTime_var;
}

void FognetMsgAdvertiseMIPS::setBusyTime(double busyTime)
{
    this->busyTime_var = busyTime;
}

class FognetMsgAdvertiseMIPSDescriptor : public cClassDescriptor
{
  public:
    FognetMsgAdvertiseMIPSDescriptor();
    virtual ~FognetMsgAdvertiseMIPSDescriptor();

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

Register_ClassDescriptor(FognetMsgAdvertiseMIPSDescriptor);

FognetMsgAdvertiseMIPSDescriptor::FognetMsgAdvertiseMIPSDescriptor() : cClassDescriptor("inet::FognetMsgAdvertiseMIPS", "cPacket")
{
}

FognetMsgAdvertiseMIPSDescriptor::~FognetMsgAdvertiseMIPSDescriptor()
{
}

bool FognetMsgAdvertiseMIPSDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<FognetMsgAdvertiseMIPS *>(obj)!=NULL;
}

const char *FognetMsgAdvertiseMIPSDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int FognetMsgAdvertiseMIPSDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int FognetMsgAdvertiseMIPSDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *FognetMsgAdvertiseMIPSDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "MIPS",
        "computeBrokerID",
        "busyTime",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int FognetMsgAdvertiseMIPSDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='M' && strcmp(fieldName, "MIPS")==0) return base+0;
    if (fieldName[0]=='c' && strcmp(fieldName, "computeBrokerID")==0) return base+1;
    if (fieldName[0]=='b' && strcmp(fieldName, "busyTime")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *FognetMsgAdvertiseMIPSDescriptor::getFieldTypeString(void *object, int field) const
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
        "double",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *FognetMsgAdvertiseMIPSDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int FognetMsgAdvertiseMIPSDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    FognetMsgAdvertiseMIPS *pp = (FognetMsgAdvertiseMIPS *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string FognetMsgAdvertiseMIPSDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    FognetMsgAdvertiseMIPS *pp = (FognetMsgAdvertiseMIPS *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getMIPS());
        case 1: return oppstring2string(pp->getComputeBrokerID());
        case 2: return double2string(pp->getBusyTime());
        default: return "";
    }
}

bool FognetMsgAdvertiseMIPSDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    FognetMsgAdvertiseMIPS *pp = (FognetMsgAdvertiseMIPS *)object; (void)pp;
    switch (field) {
        case 0: pp->setMIPS(string2long(value)); return true;
        case 1: pp->setComputeBrokerID((value)); return true;
        case 2: pp->setBusyTime(string2double(value)); return true;
        default: return false;
    }
}

const char *FognetMsgAdvertiseMIPSDescriptor::getFieldStructName(void *object, int field) const
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

void *FognetMsgAdvertiseMIPSDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    FognetMsgAdvertiseMIPS *pp = (FognetMsgAdvertiseMIPS *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

} // namespace inet

