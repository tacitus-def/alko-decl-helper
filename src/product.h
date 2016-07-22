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

#ifndef PRODUCT_H
#define PRODUCT_H

#include "contragent.h"
#include "license.h"

class Product
{
public:
    Product();
    ~Product();
    Product(Contragent* producer, Contragent* supplier, ushort type, QString number, QDate date, QString tdNumber, double value);
    Product(uint id, Contragent* producer, Contragent* supplier, ushort type, QString number, QDate date, QString tdNumber, double value);

    void setTTN(QString number, QDate date);
    void setContragents(Contragent *producer, Contragent *supplier);

    Contragent* getProducer() const;
    void setProducer(Contragent *value);

    Contragent* getSupplier() const;
    void setSupplier(Contragent *value);

    QString getTdNumber() const;
    void setTdNumber(const QString &value);

    QString getNumber() const;
    void setNumber(const QString &value);

    QDate getDate() const;
    void setDate(const QDate &value);

    uint getId() const;
    void setId(const uint &value);

    ushort getType() const;
    void setType(const ushort &value);

    double getValue() const;
    void setValue(const double &value);

    License* getLicense() const;
    void setLicense(License *value);

private:
    uint id;
    ushort type;

    License* license;

    Contragent* supplier;
    Contragent* producer;

    QString tdNumber;
    QString number;

    QDate date;
    double value;

    void setLicense();
    void setValues(Contragent* producer, Contragent* supplier, ushort type, QString number, QDate date, QString td_number, double value);
};

#endif // PRODUCT_H
