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

#include <QDebug>
#include "db.h"

DB::DB()
{
    sqlite = QSqlDatabase::addDatabase("QSQLITE", "dbCodes");
    sqlite.setDatabaseName("db.sqlite");

    if (sqlite.open()) {
        loadProductCodes();
    }
    else {
        qDebug() << "Could not open db.sqlite";
    }
}

DB::~DB()
{
    if (sqlite.isOpen()) {
        sqlite.close();
    }
    QSqlDatabase::removeDatabase("dbCodes");
}

void DB::loadProductCodes()
{
    productCodes.clear();

    QSqlQuery query(sqlite);
    if (query.exec("SELECT * FROM codes")) {
        while (query.next()) {
            ushort code = query.value("code").toUInt();
            ushort declaration = query.value("declaration").toUInt();
            bool licensed = query.value("licensed").toBool();
            QString title = query.value("title").toString();

            ProductCode pcode(code,declaration,licensed,title);

            productCodes.insert(code,pcode);
        }
    }
}

QHash<ushort, ProductCode> DB::getProductCodes() const
{
    return productCodes;
}

void DB::setProductCodes(const QHash<ushort, ProductCode> &value)
{
    productCodes = value;
}
