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
    this->isAccepted_var = 0;
    payload_arraysize = 0;
    this->payload_var = 0;
}

Package::Package(const Package& other) : cPacket()
{
    setName(other.getName());
    payload_arraysize = 0;
    this->payload_var = 0;
    operator=(other);
}

Package::~Package()
{
    delete [] payload_var;
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
    this->isAccepted_var = other.isAccepted_var;
    delete [] this->payload_var;
    this->payload_var = (other.payload_arraysize==0) ? NULL : new bool[other.payload_arraysize];
    payload_arraysize = other.payload_arraysize;
    for (unsigned int i=0; i<payload_arraysize; i++)
        this->payload_var[i] = other.payload_var[i];
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
    doPacking(b,this->isAccepted_var);
    b->pack(payload_arraysize);
    doPacking(b,this->payload_var,payload_arraysize);
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
    doUnpacking(b,this->isAccepted_var);
    delete [] this->payload_var;
    b->unpack(payload_arraysize);
    if (payload_arraysize==0) {
        this->payload_var = 0;
    } else {
        this->payload_var = new bool[payload_arraysize];
        doUnpacking(b,this->payload_var,payload_arraysize);
    }
}

int Package::getDestination() const
{
    return destination_var;
}

void Package::setDestination(int destination_var)
{
    this->destination_var = destination_var;
}

int Package::getSource() const
{
    return source_var;
}

void Package::setSource(int source_var)
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

bool Package::getIsAccepted() const
{
    return isAccepted_var;
}

void Package::setIsAccepted(bool isAccepted_var)
{
    this->isAccepted_var = isAccepted_var;
}

void Package::setPayloadArraySize(unsigned int size)
{
    bool *payload_var2 = (size==0) ? NULL : new bool[size];
    unsigned int sz = payload_arraysize < size ? payload_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        payload_var2[i] = this->payload_var[i];
    for (unsigned int i=sz; i<size; i++)
        payload_var2[i] = 0;
    payload_arraysize = size;
    delete [] this->payload_var;
    this->payload_var = payload_var2;
}

unsigned int Package::getPayloadArraySize() const
{
    return payload_arraysize;
}

bool Package::getPayload(unsigned int k) const
{
    if (k>=payload_arraysize) throw cRuntimeError("Array of size %d indexed by %d", payload_arraysize, k);
    return payload_var[k];
}

void Package::setPayload(unsigned int k, bool payload_var)
{
    if (k>=payload_arraysize) throw cRuntimeError("Array of size %d indexed by %d", payload_arraysize, k);
    this->payload_var[k]=payload_var;
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
    return basedesc ? 8+basedesc->getFieldCount(object) : 8;
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
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<8) ? fieldTypeFlags[field] : 0;
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
        "isAccepted",
        "payload",
    };
    return (field>=0 && field<8) ? fieldNames[field] : NULL;
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
    if (fieldName[0]=='i' && strcmp(fieldName, "isAccepted")==0) return base+6;
    if (fieldName[0]=='p' && strcmp(fieldName, "payload")==0) return base+7;
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
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "bool",
        "bool",
    };
    return (field>=0 && field<8) ? fieldTypeStrings[field] : NULL;
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
        case 7: return pp->getPayloadArraySize();
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
        case 0: return long2string(pp->getDestination());
        case 1: return long2string(pp->getSource());
        case 2: return long2string(pp->getSessionId());
        case 3: return long2string(pp->getPacketId());
        case 4: return long2string(pp->getPriority());
        case 5: return long2string(pp->getSize());
        case 6: return bool2string(pp->getIsAccepted());
        case 7: return bool2string(pp->getPayload(i));
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
        case 0: pp->setDestination(string2long(value)); return true;
        case 1: pp->setSource(string2long(value)); return true;
        case 2: pp->setSessionId(string2long(value)); return true;
        case 3: pp->setPacketId(string2long(value)); return true;
        case 4: pp->setPriority(string2long(value)); return true;
        case 5: pp->setSize(string2long(value)); return true;
        case 6: pp->setIsAccepted(string2bool(value)); return true;
        case 7: pp->setPayload(i,string2bool(value)); return true;
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
        NULL,
        NULL,
    };
    return (field>=0 && field<8) ? fieldStructNames[field] : NULL;
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


