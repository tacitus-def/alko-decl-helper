//
//  Copyright (c) 2016 Petr Sleptsov <spetr@bk.ru>
//
//  This file is part of Alko-decl-helper.
//
//  Alko-decl-helper is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  Alko-decl-helper is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with Alko-decl-helper.  If not, see <http://www.gnu.org/licenses/>.
//

#include "product.h"

Product::Product() { }

Product::~Product()
{
    license = NULL;

    supplier = NULL;
    producer = NULL;

}

Product::Product(Contragent* producer, Contragent* supplier, ushort type, QString number, QDate date, QString td_number, double value)
{
    setValues(producer, supplier, type, number, date, td_number, value);
}

Product::Product(uint id, Contragent* producer, Contragent* supplier,  ushort type, QString number, QDate date, QString td_number, double value)
{
    this->id = id;
    setValues(producer, supplier, type, number, date, td_number, value);
}

void Product::setValues(Contragent* producer, Contragent* supplier, ushort type, QString number, QDate date, QString td_number, double value) {
    this->type = type;
    this->date = date;
    this->value = value;
    this->number = number;
    this->supplier = supplier;
    this->producer = producer;
    this->tdNumber = td_number;

    setLicense();
}

void Product::setLicense() {
    license = supplier->findLicense(date);
}

void Product::setTTN(QString number, QDate date)
{
    this->number = number;
    this->date = date;
}

void Product::setContragents(Contragent* producer, Contragent* supplier)
{
    this->supplier = supplier;
    this->producer = producer;
}

void Product::setType(const ushort &value)
{
    this->type = value;
}

double Product::getValue() const
{
    return value;
}

void Product::setValue(const double &value)
{
    this->value = value;
}

License* Product::getLicense() const
{
    return this->license;
}

void Product::setLicense(License *value)
{
    this->license = value;
}

Contragent* Product::getProducer() const
{
    return producer;
}

void Product::setProducer(Contragent* value)
{
    producer = value;
}
Contragent* Product::getSupplier() const
{
    return supplier;
}

void Product::setSupplier(Contragent* value)
{
    supplier = value;
}
QString Product::getTdNumber() const
{
    return tdNumber;
}

void Product::setTdNumber(const QString &value)
{
    tdNumber = value;
}
QString Product::getNumber() const
{
    return number;
}

void Product::setNumber(const QString &value)
{
    number = value;
}
QDate Product::getDate() const
{
    return date;
}

void Product::setDate(const QDate &value)
{
    date = value;
}
uint Product::getId() const
{
    return id;
}

void Product::setId(const uint &value)
{
    this->id = value;
}

ushort Product::getType() const
{
    return type;
}

