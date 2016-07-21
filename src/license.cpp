#include "contragent.h"
#include "license.h"

License::License() { }

License::~License()
{
//    delete contragent;
    contragent = NULL;
}

License::License(Contragent* contragent, QString number, QDate startDate, QDate endDate, QString department)
{
    this->number = number;
    this->contragent = contragent;
    this->startDate = startDate;
    this->endDate = endDate;
    this->department = department;
}

License::License(uint id, Contragent *contragent, QString number, QDate startDate, QDate endDate, QString department)
{
    this->id = id;
    this->contragent = contragent;
    this->number = number;
    this->startDate = startDate;
    this->endDate = endDate;
    this->department = department;
}

bool License::isEmpty() const
{
    return number.isEmpty();
}

QString License::getNumber() const
{
    return number;
}

void License::setNumber(const QString &value)
{
    number = value;
}
QDate License::getStartDate() const
{
    return startDate;
}

void License::setStartDate(const QDate &value)
{
    startDate = value;
}
QString License::getDepartment() const
{
    return department;
}

void License::setDepartment(const QString &value)
{
    department = value;
}
uint License::getId() const
{
    return id;
}

void License::setId(const uint &value)
{
    id = value;
}
QDate License::getEndDate() const
{
    return endDate;
}

void License::setEndDate(const QDate &value)
{
    endDate = value;
}

Contragent *License::getContragent() const
{
    return contragent;
}

void License::setContragent(Contragent *value)
{
    contragent = value;
}
