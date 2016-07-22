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

#ifndef ALKOSAVEDATA_H
#define ALKOSAVEDATA_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFileInfo>
#include <QVariant>
#include "contragent.h"
#include "license.h"
#include "product.h"
#include "oborot.h"
#include "summary.h"

class AlkoData
{
public:
    AlkoData();
    ~AlkoData();
    bool load();
    bool save();
    QString getDatabase() const;
    bool setDatabase(QString file);
    void close();
    bool isOpen();

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
    QSqlDatabase sqlite;
    QString dbFileName;

    QHash<QPair<ushort,Contragent*>,Summary*> summary;
    Oborot oborot;

    QHash<Contragent::qpair, Contragent*> contragents;
    QHash<QString,License*> licenses;
    QVector<Product*> products;

    QHash<uint, Contragent*> idx_contragents;
    QHash<uint, Product*> idx_products;
    QHash<uint, License*> idx_licenses;

    void createTables();
    void createTableContragents();
    void createTableLicenses();
    void createTableOborot();
    void createTableSummary();
    void createTableProducts();

    void storeData();
    void storeContragents();
    void storeLicenses();
    void storeOborot();
    void storeProducts();
    void storeSummary();

    void readTables();
    void readContragents();
    void readLicenses();
    void readOborot();
    void readProducts();
    void readSummary();

    void dropTables();

    Contragent *searchContragent(uint contragent_id);
    License *searchLicense(uint license_id);
    Product *searchProduct(uint product_id);

    bool loadDB();
    bool saveDB();
};

#endif // ALKOSAVEDATA_H
