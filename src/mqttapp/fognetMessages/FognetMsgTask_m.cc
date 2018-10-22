//
// Generated file, do not edit! Created by nedtool 4.6 from inet/applications/mqttapp/fognetMessages/FognetMsgTask.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "FognetMsgTask_m.h"

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

Register_Class(FognetMsgTask);

FognetMsgTask::FognetMsgTask(const char *name, int kind) : ::cPacket(name,kind)
{
    this->requestID_var = 0;
    this->requiredTime_var = 0;
    this->clientID_var = 0;
    this->requiredMIPS_var = 0;
}

FognetMsgTask::FognetMsgTask(const FognetMsgTask& other) : ::cPacket(other)
{
    copy(other);
}

FognetMsgTask::~FognetMsgTask()
{
}

FognetMsgTask& FognetMsgTask::operator=(const FognetMsgTask& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void FognetMsgTask::copy(const FognetMsgTask& other)
{
    this->requestID_var = other.requestID_var;
    this->requiredTime_var = other.requiredTime_var;
    this->clientID_var = other.clientID_var;
    this->requiredMIPS_var = other.requiredMIPS_var;
}

void FognetMsgTask::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->requestID_var);
    doPacking(b,this->requiredTime_var);
    doPacking(b,this->clientID_var);
    doPacking(b,this->requiredMIPS_var);
}

void FognetMsgTask::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->requestID_var);
    doUnpacking(b,this->requiredTime_var);
    doUnpacking(b,this->clientID_var);
    doUnpacking(b,this->requiredMIPS_var);
}

const char * FognetMsgTask::getRequestID() const
{
    return requestID_var.c_str();
}

void FognetMsgTask::setRequestID(const char * requestID)
{
    this->requestID_var = requestID;
}

double FognetMsgTask::getRequiredTime() const
{
    return requiredTime_var;
}

void FognetMsgTask::setRequiredTime(double requiredTime)
{
    this->requiredTime_var = requiredTime;
}

const char * FognetMsgTask::getClientID() const
{
    return clientID_var.c_str();
}

void FognetMsgTask::setClientID(const char * clientID)
{
    this->clientID_var = clientID;
}

int FognetMsgTask::getRequiredMIPS() const
{
    return requiredMIPS_var;
}

void FognetMsgTask::setRequiredMIPS(int requiredMIPS)
{
    this->requiredMIPS_var = requiredMIPS;
}

class FognetMsgTaskDescriptor : public cClassDescriptor
{
  public:
    FognetMsgTaskDescriptor();
    virtual ~FognetMsgTaskDescriptor();

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

Register_ClassDescriptor(FognetMsgTaskDescriptor);

FognetMsgTaskDescriptor::FognetMsgTaskDescriptor() : cClassDescriptor("inet::FognetMsgTask", "cPacket")
{
}

FognetMsgTaskDescriptor::~FognetMsgTaskDescriptor()
{
}

bool FognetMsgTaskDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<FognetMsgTask *>(obj)!=NULL;
}

const char *FognetMsgTaskDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int FognetMsgTaskDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount(object) : 4;
}

unsigned int FognetMsgTaskDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *FognetMsgTaskDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "requestID",
        "requiredTime",
        "clientID",
        "requiredMIPS",
    };
    return (field>=0 && field<4) ? fieldNames[field] : NULL;
}

int FognetMsgTaskDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='r' && strcmp(fieldName, "requestID")==0) return base+0;
    if (fieldName[0]=='r' && strcmp(fieldName, "requiredTime")==0) return base+1;
    if (fieldName[0]=='c' && strcmp(fieldName, "clientID")==0) return base+2;
    if (fieldName[0]=='r' && strcmp(fieldName, "requiredMIPS")==0) return base+3;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *FognetMsgTaskDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "double",
        "string",
        "int",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : NULL;
}

const char *FognetMsgTaskDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int FognetMsgTaskDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    FognetMsgTask *pp = (FognetMsgTask *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string FognetMsgTaskDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    FognetMsgTask *pp = (FognetMsgTask *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getRequestID());
        case 1: return double2string(pp->getRequiredTime());
        case 2: return oppstring2string(pp->getClientID());
        case 3: return long2string(pp->getRequiredMIPS());
        default: return "";
    }
}

bool FognetMsgTaskDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    FognetMsgTask *pp = (FognetMsgTask *)object; (void)pp;
    switch (field) {
        case 0: pp->setRequestID((value)); return true;
        case 1: pp->setRequiredTime(string2double(value)); return true;
        case 2: pp->setClientID((value)); return true;
        case 3: pp->setRequiredMIPS(string2long(value)); return true;
        default: return false;
    }
}

const char *FognetMsgTaskDescriptor::getFieldStructName(void *object, int field) const
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

void *FognetMsgTaskDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    FognetMsgTask *pp = (FognetMsgTask *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

} // namespace inet

