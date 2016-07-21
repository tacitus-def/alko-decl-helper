#include "processdata.h"

ProcessData::ProcessData(QVector<InputData> data)
{
    this->process(data);
}

void ProcessData::process(QVector<InputData> data)
{
    uint cid = 0;
    uint lid = 0;
    uint pid = 0;
    contragents.clear();
    licenses.clear();
    summary.clear();
    products.clear();
    oborot.clear();

    for (int r=0; r < data.size(); r++) {

        InputData row = data.at(r);

        Contragent::qpair kProducer(row.ProducerInn, row.ProducerKpp);
        Contragent::qpair kSupplier(row.SupplierInn, row.SupplierKpp);
        Contragent* producer;
        Contragent* supplier;

        Contragent::iterator iProducer = contragents.find(kProducer);
        Contragent::iterator iSupplier = contragents.find(kSupplier);

        // Производитель
        if (iProducer == contragents.end()) {
            cid ++;
            producer = newContragent(cid, row.ProducerName, row.ProducerInn, row.ProducerKpp, true, false);
            contragents.insert(kProducer, producer);
        }
        else {
            producer = iProducer.value();
        }

        QPair<ushort,Contragent*> summaryKey(row.ProductType,producer);
        QHash<QPair<ushort,Contragent*>,Summary *>::iterator summaryIter = summary.find(summaryKey);

        if (summaryIter == summary.end()) {
            summaryIter = summary.insert(summaryKey, new Summary(row.ProductType, producer));
        }
        Summary *s = summaryIter.value();
        s->setReceiptFromWholesalers(s->getReceiptFromWholesalers() + row.NumberDkl);
        // Поставщик
        if (iSupplier == contragents.end()) {
            cid ++;
            supplier = newContragent(cid, row.SupplierName, row.SupplierInn, row.SupplierKpp, false, false);
            contragents.insert(kSupplier, supplier);
        }
        else {
            supplier = iSupplier.value();
        }
        // Лицензия поставщика
        if (!row.LicenseNumber.isEmpty() && licenses.find(row.LicenseNumber) == licenses.end()) {
            lid ++;
            License* license = new License (lid, supplier, row.LicenseNumber, row.LicenseSdate, row.LicenseEdate, row.LicenseDepartment);
            licenses.insert(row.LicenseNumber,license);
            supplier->addLicense(license);
        }
        // Продукция
        pid ++;
        Product* product =  new Product(pid, producer, supplier, row.ProductType, row.TtnNumber, row.TtnDate, row.TdNumber, row.NumberDkl);

        products.append(product);

        oborot.insert(row.ProductType, producer, supplier, product);
    }

    QHashIterator<QPair<ushort,Contragent*>,Summary*> iter(summary);
    while(iter.hasNext()) {
        iter.next();

        Summary *value = iter.value();
        value->setConsumptionRetail(value->getReceiptFromWholesalers());
    }
}


Contragent* ProcessData::newContragent(uint id, QString name, QString inn, QString kpp, bool producer, bool carrier)
{
    Contragent* item = new Contragent(id, name, inn, kpp);
    item->setProducer(producer);
    item->setCarrier(carrier);

    QString c_kpp = item->getKpp();
    QString c_inn = item->getInn();
    // Если КПП больше нуля то считаем, что контрагент из России
    if (c_kpp.toLong() > 0) {
        item->setCodes(643, c_kpp.mid(0, c_kpp.length()-7).toUInt());
    }
    else
    if (c_inn.length() == 12) {
        item->setKpp(0);
        item->setCodes(643, c_kpp.mid(0, 2).toUInt());
    }

    return item;
}

QHash<QPair<ushort, Contragent *>, Summary*> ProcessData::getSummary()
{
    return summary;
}

Oborot ProcessData::getOborot()
{
    return oborot;
}

QHash<Contragent::qpair, Contragent*> ProcessData::getContragents()
{
    return contragents;
}

QHash<QString, License *> ProcessData::getLicenses()
{
    return licenses;
}

QVector<Product*> ProcessData::getProducts()
{
    return products;
}
