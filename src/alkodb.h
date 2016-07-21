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
