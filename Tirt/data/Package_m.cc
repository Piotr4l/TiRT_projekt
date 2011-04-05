//
// Generated file, do not edit! Created by opp_msgc 4.1 from data/Package.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "Package_m.h"

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




Register_Class(Package);

Package::Package(const char *name, int kind) : cPacket(name,kind)
{
    this->destination_var = 0;
    this->source_var = 0;
    this->sessionId_var = 0;
    this->packetId_var = 0;
    this->priority_var = 0;
    this->size_var = 0;
}

Package::Package(const Package& other) : cPacket()
{
    setName(other.getName());
    operator=(other);
}

Package::~Package()
{
}

Package& Package::operator=(const Package& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    this->destination_var = other.destination_var;
    this->source_var = other.source_var;
    this->sessionId_var = other.sessionId_var;
    this->packetId_var = other.packetId_var;
    this->priority_var = other.priority_var;
    this->size_var = other.size_var;
    return *this;
}

void Package::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->destination_var);
    doPacking(b,this->source_var);
    doPacking(b,this->sessionId_var);
    doPacking(b,this->packetId_var);
    doPacking(b,this->priority_var);
    doPacking(b,this->size_var);
}

void Package::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->destination_var);
    doUnpacking(b,this->source_var);
    doUnpacking(b,this->sessionId_var);
    doUnpacking(b,this->packetId_var);
    doUnpacking(b,this->priority_var);
    doUnpacking(b,this->size_var);
}

const char * Package::getDestination() const
{
    return destination_var.c_str();
}

void Package::setDestination(const char * destination_var)
{
    this->destination_var = destination_var;
}

const char * Package::getSource() const
{
    return source_var.c_str();
}

void Package::setSource(const char * source_var)
{
    this->source_var = source_var;
}

int Package::getSessionId() const
{
    return sessionId_var;
}

void Package::setSessionId(int sessionId_var)
{
    this->sessionId_var = sessionId_var;
}

int Package::getPacketId() const
{
    return packetId_var;
}

void Package::setPacketId(int packetId_var)
{
    this->packetId_var = packetId_var;
}

int Package::getPriority() const
{
    return priority_var;
}

void Package::setPriority(int priority_var)
{
    this->priority_var = priority_var;
}

int Package::getSize() const
{
    return size_var;
}

void Package::setSize(int size_var)
{
    this->size_var = size_var;
}

class PackageDescriptor : public cClassDescriptor
{
  public:
    PackageDescriptor();
    virtual ~PackageDescriptor();

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

Register_ClassDescriptor(PackageDescriptor);

PackageDescriptor::PackageDescriptor() : cClassDescriptor("Package", "cPacket")
{
}

PackageDescriptor::~PackageDescriptor()
{
}

bool PackageDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<Package *>(obj)!=NULL;
}

const char *PackageDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int PackageDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount(object) : 6;
}

unsigned int PackageDescriptor::getFieldTypeFlags(void *object, int field) const
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
    };
    return (field>=0 && field<6) ? fieldTypeFlags[field] : 0;
}

const char *PackageDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "destination",
        "source",
        "sessionId",
        "packetId",
        "priority",
        "size",
    };
    return (field>=0 && field<6) ? fieldNames[field] : NULL;
}

int PackageDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destination")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "source")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "sessionId")==0) return base+2;
    if (fieldName[0]=='p' && strcmp(fieldName, "packetId")==0) return base+3;
    if (fieldName[0]=='p' && strcmp(fieldName, "priority")==0) return base+4;
    if (fieldName[0]=='s' && strcmp(fieldName, "size")==0) return base+5;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *PackageDescriptor::getFieldTypeString(void *object, int field) const
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
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : NULL;
}

const char *PackageDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int PackageDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    Package *pp = (Package *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string PackageDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    Package *pp = (Package *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getDestination());
        case 1: return oppstring2string(pp->getSource());
        case 2: return long2string(pp->getSessionId());
        case 3: return long2string(pp->getPacketId());
        case 4: return long2string(pp->getPriority());
        case 5: return long2string(pp->getSize());
        default: return "";
    }
}

bool PackageDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    Package *pp = (Package *)object; (void)pp;
    switch (field) {
        case 0: pp->setDestination((value)); return true;
        case 1: pp->setSource((value)); return true;
        case 2: pp->setSessionId(string2long(value)); return true;
        case 3: pp->setPacketId(string2long(value)); return true;
        case 4: pp->setPriority(string2long(value)); return true;
        case 5: pp->setSize(string2long(value)); return true;
        default: return false;
    }
}

const char *PackageDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<6) ? fieldStructNames[field] : NULL;
}

void *PackageDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    Package *pp = (Package *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


