#include "contragent.h"
#include "license.h"

void Contragent::init()
{
    country = 0;
    area = 0;
    
    orgType = 1;
    inn = "";
    kpp = "0";
    carrier = producer = false;
}

Contragent::Contragent()
{
    init();

//    Contragent::currentId += 1;
    //    this->id = Contragent::currentId;
}

Contragent::~Contragent()
{
//    QHashIterator<QString, License*> i(licenses);
//    while (i.hasNext()) {
//        i.next();
//        i.value() = NULL;
//    }
    licenses.clear();
}

Contragent::Contragent(QString name, QString inn, QString kpp)
{
    init();
    setName(name);
    setInn(inn);
    setKpp(kpp);
}

Contragent::Contragent(uint id, QString name, QString inn, QString kpp)
{
    init();
    this->id = id;
    setName(name);
    setInn(inn);
    setKpp(kpp);
}

void Contragent::setCodes(uint country, uint area)
{
    this->country = country;
    this->area = area;
}

void Contragent::setProducer(bool producer)
{
    this->producer = producer;
}

bool Contragent::getProducer()
{
    return this->producer;
}

void Contragent::setCarrier(bool carrier)
{
    this->carrier = carrier;
}

bool Contragent::getCarrier()
{
    return this->carrier;
}

void Contragent::setOrgType(uint orgType)
{
    this->orgType = orgType;
}

uint Contragent::getId()
{
    return this->id;
}

void Contragent::setId(const uint &value)
{
    this->id = value;
}


QString Contragent::getInn() const
{
    return inn;
}

void Contragent::setInn(const QString &value)
{
    inn = value.trimmed().rightJustified(10, '0');
}

License *Contragent::addLicense(License *license)
{
    if (licenses.find(license->getNumber()) == licenses.end())
    {
        licenses.insert(license->getNumber(), license);
    }
    
    return license;
}

License* Contragent::findLicense(QDate date)
{
    QHashIterator<QString, License*> i(licenses);
    while (i.hasNext()) {
        i.next();
        License* t = i.value();
        if (t->getStartDate() <= date && date <= t->getEndDate()) {
            return t;
        }
    }
    
    return NULL;
}

QHash<QString, License *> Contragent::getLicenses()
{
    return this->licenses;
}

bool Contragent::hasLicense(QString number)
{
    return licenses.find(number) != licenses.end();
}

uint Contragent::getOrgType()
{
    return orgType;
}


QString Contragent::getKpp() const
{
    return kpp;
}

void Contragent::setKpp(const QString &value)
{
    kpp = value.trimmed().rightJustified(9, '0');
}

QString Contragent::getName() const
{
    return name;
}

void Contragent::setName(const QString &value)
{
    name = value.trimmed();
}


uint Contragent::getArea() const
{
    return area;
}

void Contragent::setArea(const uint &value)
{
    area = value;
}

uint Contragent::getCountry() const
{
    return country;
}

void Contragent::setCountry(const uint &value)
{
    country = value;
}
