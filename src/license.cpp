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
