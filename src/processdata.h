#ifndef PROCESSDATA_H
#define PROCESSDATA_H

#include <QVector>
#include <QPair>
#include <QHash>
#include <cmath>
#include "contragent.h"
#include "product.h"
#include "license.h"
#include "csvreader.h"
#include "inputdata.h"
#include "oborot.h"
#include "summary.h"

class ProcessData
{
public:
    ProcessData(QVector<InputData> data);

    QHash<QPair<ushort, Contragent *>, Summary *> getSummary();
    Oborot getOborot();
    QHash<Contragent::qpair, Contragent*> getContragents();
    QHash<QString,License*> getLicenses();
    QVector<Product*> getProducts();

private:
    QHash<QPair<ushort,Contragent*>,Summary*> summary;
    Oborot oborot;

    QHash<Contragent::qpair, Contragent*> contragents;
    QHash<QString,License*> licenses;
    QVector<Product*> products;

    void process(QVector<InputData> data);

    Contragent* newContragent(uint id, QString name, QString inn, QString kpp, bool producer, bool carrier);
};

#endif // PROCESSDATA_H
