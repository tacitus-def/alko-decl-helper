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

#include "alkodb.h"

ALkoDB::ALkoDB(QString filename)
{
    tOborot = NULL;
    tSummary = NULL;
    tLicenses = NULL;
    tProducts = NULL;
    tContragents = NULL;

    QFileInfo info(filename);
    bool newFile = ! info.exists();

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(filename);
    if (db.open()) {
        if (newFile) {

        }
        tOborot = new QSqlTableModel();
        tSummary = new QSqlTableModel();
        tLicenses = new QSqlTableModel();
        tProducts = new QSqlTableModel();
        tContragents = new QSqlTableModel();

        tOborot->setTable("oborot");
        tSummary->setTable("summary");
        tLicenses->setTable("licenses");
        tProducts->setTable("products");
        tContragents->setTable("contragents");
    }
}

ALkoDB::~ALkoDB()
{
    delete tOborot;
    delete tSummary;
    delete tLicenses;
    delete tProducts;
    delete tContragents;
}

QHash<QPair<ushort, Contragent *>, Summary *> ALkoDB::getSummary() const
{
    return summary;
}

void ALkoDB::setSummary(const QHash<QPair<ushort, Contragent *>, Summary *> &value)
{
    summary = value;
}
Oborot ALkoDB::getOborot() const
{
    return oborot;
}

void ALkoDB::setOborot(const Oborot &value)
{
    oborot = value;
}
QHash<Contragent::qpair, Contragent *> ALkoDB::getContragents() const
{
    return contragents;
}

void ALkoDB::setContragents(const QHash<Contragent::qpair, Contragent *> &value)
{
    contragents = value;
}
QHash<QString, License *> ALkoDB::getLicenses() const
{
    return licenses;
}

void ALkoDB::setLicenses(const QHash<QString, License *> &value)
{
    licenses = value;
}
QVector<Product *> ALkoDB::getProducts() const
{
    return products;
}

void ALkoDB::setProducts(const QVector<Product *> &value)
{
    products = value;
}





