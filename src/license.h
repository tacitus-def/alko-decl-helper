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

#ifndef LICENSE_H
#define LICENSE_H

#include <QDate>

class Contragent;

class License
{
public:
    License();
    ~License();
    License(Contragent* contragent, QString number, QDate startDate, QDate endDate, QString department);
    License(uint id, Contragent* contragent, QString number, QDate startDate, QDate endDate, QString department);

    bool isEmpty() const;

    QString getNumber() const;
    void setNumber(const QString &value);

    QDate getStartDate() const;
    void setStartDate(const QDate &value);

    QString getDepartment() const;
    void setDepartment(const QString &value);

    uint getId() const;
    void setId(const uint &value);

    QDate getEndDate() const;
    void setEndDate(const QDate &value);

    Contragent* getContragent() const;
    void setContragent(Contragent *value);

private:
    uint id;

    Contragent* contragent;
    QString number;
    QDate startDate;
    QDate endDate;
    QString department;
};

#endif // LICENSE_H
