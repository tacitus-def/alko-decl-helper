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
    void load();
    void save();
    void setDatabase(QString file);
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

    void loadDB();
    void saveDB();
};

#endif // ALKOSAVEDATA_H
