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

#ifndef ALKODB_H
#define ALKODB_H

#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QHash>
#include <QVector>
#include <QFileInfo>
#include "contragent.h"
#include "oborot.h"
#include "summary.h"
#include "license.h"
#include "product.h"

class ALkoDB
{
public:
    ALkoDB(QString filename);
    ~ALkoDB();

    QHash<QPair<ushort, Contragent *>, Summary *> getSummary() const;
    void setSummary(const QHash<QPair<ushort, Contragent *>, Summary *> &value);

    Oborot getOborot() const;
    void setOborot(const Oborot &value);

    QHash<Contragent::qpair, Contragent *> getContragents() const;
    void setContragents(const QHash<Contragent::qpair, Contragent *> &value);

    QHash<QString, License *> getLicenses() const;
    void setLicenses(const QHash<QString, License *> &value);

    QVector<Product *> getProducts() const;
    void setProducts(const QVector<Product *> &value);

private:
    QSqlDatabase db;

    QSqlTableModel *tSummary;
    QSqlTableModel *tOborot;
    QSqlTableModel *tContragents;
    QSqlTableModel *tLicenses;
    QSqlTableModel *tProducts;

    QHash<QPair<ushort,Contragent*>,Summary*> summary;
    Oborot oborot;

    QHash<Contragent::qpair, Contragent*> contragents;
    QHash<QString,License*> licenses;
    QVector<Product*> products;

};

#endif // ALKODB_H
