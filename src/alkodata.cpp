#include "alkodata.h"

AlkoData::AlkoData()
{
    sqlite = QSqlDatabase::addDatabase("QSQLITE", "dbData");
}

AlkoData::~AlkoData()
{
    close();
    QSqlDatabase::removeDatabase("dbData");
}

void AlkoData::load()
{
    if (sqlite.isOpen() || sqlite.open()) {
        loadDB();
    }
}

void AlkoData::save()
{
    if (sqlite.isOpen() || sqlite.open()) {
        saveDB();
    }
}

void AlkoData::setDatabase(QString file)
{
    dbFileName = file;
    sqlite.setDatabaseName(dbFileName);
}

void AlkoData::close()
{
    if (sqlite.isOpen()) {
        sqlite.close();
    }
}

bool AlkoData::isOpen()
{
    return sqlite.isOpen();
}

QHash<QPair<ushort, Contragent *>, Summary *> AlkoData::getSummary() const
{
    return summary;
}

void AlkoData::setSummary(const QHash<QPair<ushort, Contragent *>, Summary *> &value)
{
    summary = value;
}
Oborot AlkoData::getOborot() const
{
    return oborot;
}

void AlkoData::setOborot(const Oborot &value)
{
    oborot = value;
}
QHash<Contragent::qpair, Contragent *> AlkoData::getContragents() const
{
    return contragents;
}

void AlkoData::setContragents(const QHash<Contragent::qpair, Contragent *> &value)
{
    contragents = value;
}
QHash<QString, License *> AlkoData::getLicenses() const
{
    return licenses;
}

void AlkoData::setLicenses(const QHash<QString, License *> &value)
{
    licenses = value;
}
QVector<Product *> AlkoData::getProducts() const
{
    return products;
}

void AlkoData::setProducts(const QVector<Product *> &value)
{
    products = value;
}

void AlkoData::createTables()
{
    createTableContragents();
    createTableLicenses();
    createTableOborot();
    createTableProducts();
    createTableSummary();
}

void AlkoData::createTableContragents()
{
    QSqlQuery query(sqlite);
    query.exec("CREATE TABLE contragents ("
               "id integer primary key not null, "
               "name text not null, "
               "inn varchar(12) not null, "
               "kpp varchar(9) not null, "
               "orgtype integer not null, "
               "country integer not null, "
               "area integer not null, "
               "producer integer not null, "
               "carrier integer not null "
               ")");
}

void AlkoData::createTableLicenses()
{
    QSqlQuery query(sqlite);
    query.exec("CREATE TABLE licenses ("
               "id integer primary key not null, "
               "contragent_id integer not null, "
               "number text not null, "
               "startdate text not null, "
               "enddate text not null, "
               "department text not null "
               ")");
}

void AlkoData::createTableOborot()
{
//    QSqlQuery query(sqlite);
//    query.exec("CREATE TABLE oborot ("
//               "code integer not null, "
//               "supplier_id integer not null, "
//               "producer_id integer not null, "
//               "product_id integer not null, "
//               "license_id integer not null "
//               ")");
}

void AlkoData::createTableSummary()
{
    QSqlQuery query(sqlite);
    query.exec("CREATE TABLE summary ("
               "code integer not null, "
               "contragent_id integer not null, "
               "balance_begin DOUBLE not null, "
               "receipt_from_producers DOUBLE not null, "
               "receipt_from_wholesalers DOUBLE not null, "
               "receipt_import DOUBLE not null, "
               "receipt_consumption DOUBLE not null, "
               "receipt_other DOUBLE not null, "
               "receipt_move DOUBLE not null, "
               "consumption_retail DOUBLE not null, "
               "consumption_other DOUBLE not null, "
               "consumption_return DOUBLE not null, "
               "consumption_move DOUBLE not null, "
               "balance_end DOUBLE not null "
               ")");
}

void AlkoData::createTableProducts()
{
    QSqlQuery query(sqlite);
    query.exec("CREATE TABLE products ("
               "id integer primary key not null, "
               "type integer not null, "
               "license_id integer not null, "
               "supplier_id integer not null, "
               "producer_id integer not null, "
               "tdnumber text not null, "
               "number text not null, "
               "date text not null, "
               "value double not null "
               ")");
}

void AlkoData::storeData()
{
    storeContragents();
    storeLicenses();
    storeOborot();
    storeProducts();
    storeSummary();
}

void AlkoData::storeContragents()
{
    QSqlQuery query(sqlite);
    QHashIterator<QPair<QString,QString>,Contragent*> iter(contragents);
    query.prepare("INSERT INTO contragents "
                  "(id,name,inn,kpp,orgtype,country,area,producer,carrier) VALUES "
                  "(:id,:name,:inn,:kpp,:orgtype,:country,:area,:producer,:carrier)");
    while(iter.hasNext()) {
        iter.next();
        Contragent* row = iter.value();
        query.bindValue(":id", row->getId());
        query.bindValue(":name", row->getName());
        query.bindValue(":inn", row->getInn());
        query.bindValue(":kpp", row->getKpp());
        query.bindValue(":orgtype", row->getOrgType());
        query.bindValue(":country", row->getCountry());
        query.bindValue(":area", row->getArea());
        query.bindValue(":producer", row->getProducer());
        query.bindValue(":carrier", row->getCarrier());
        query.exec();
    }
}

void AlkoData::storeLicenses()
{
    QSqlQuery query(sqlite);
    QHashIterator<QString,License*> iter(licenses);
    query.prepare("INSERT INTO licenses "
                  "(id,contragent_id,number,startdate,enddate,department) VALUES "
                  "(:id,:contragent_id,:number,:startdate,:enddate,:department)");
    while (iter.hasNext()) {
        iter.next();
        License* row = iter.value();
        query.bindValue(":id", row->getId());
        query.bindValue(":contragent_id", row->getContragent()->getId());
        query.bindValue(":number", row->getNumber());
        query.bindValue(":startdate", row->getStartDate());
        query.bindValue(":enddate", row->getEndDate());
        query.bindValue(":department", row->getDepartment());
        query.exec();
    }
}

void AlkoData::storeOborot()
{
//    QSqlQuery query(sqlite);
//    Oborot::hashCodeList items = oborot.getItems();
//    QHashIterator<ushort,Oborot::hashContragentProductList*> iter_items(items);
//    query.prepare("INSERT INTO oborot "
//                  "(code,supplier_id,producer_id,product_id,license_id) VALUES "
//                  "(:code,:supplier_id,:producer_id,:product_id,:license_id)");
//    while (iter_items.hasNext()) {
//        iter_items.next();
//        Oborot::hashContragentProductList* row_items = iter_items.value();
//        uint code = iter_items.key();
//        QHashIterator<Contragent*, Oborot::hashProductList*> iter_contragentProductList(*row_items);
//        while (iter_contragentProductList.hasNext()) {
//            iter_contragentProductList.next();
//            Oborot::hashProductList* row_productList = iter_contragentProductList.value();
//            Contragent* producer = iter_contragentProductList.key();
//            QHashIterator<Oborot::pairContragentLicense, QList<Product*>*> iter_products(*row_productList);
//            while (iter_products.hasNext()) {
//                iter_products.next();
//                QList<Product*>* products = iter_products.value();
//                Oborot::pairContragentLicense product_pair = iter_products.key();
//                Contragent* supplier = product_pair.first;
//                License* license = product_pair.second;

//                QListIterator<Product*> iter_list(*products);
//                while (iter_list.hasNext()) {
//                    Product* product = iter_list.next();
//                    query.bindValue(":code", code);
//                    query.bindValue(":producer_id", producer->getId());
//                    query.bindValue(":supplier_id", supplier->getId());
//                    query.bindValue(":product_id", product->getId());
//                    query.bindValue(":license_id", license ? license->getId() : 0);
//                    query.exec();
//                }
//            }
//        }
//    }
}

void AlkoData::storeProducts()
{
    QSqlQuery query(sqlite);
    QVectorIterator<Product*> iter_products(products);
    query.prepare("INSERT INTO products "
                  "(id,type,license_id,supplier_id,producer_id,tdnumber,number,date,value) VALUES "
                  "(:id,:type,:license_id,:supplier_id,:producer_id,:tdnumber,:number,:date,:value)");
    while (iter_products.hasNext()) {
        Product* product = iter_products.next();
        License* license = product->getLicense();
        query.bindValue(":id", product->getId());
        query.bindValue(":type", product->getType());
        query.bindValue(":license_id", license ? license->getId() : 0);
        query.bindValue(":supplier_id", product->getSupplier()->getId());
        query.bindValue(":producer_id", product->getProducer()->getId());
        query.bindValue(":tdnumber", product->getTdNumber());
        query.bindValue(":number", product->getNumber());
        query.bindValue(":date", product->getDate());
        query.bindValue(":value", product->getValue());
        query.exec();
    }
}

void AlkoData::storeSummary()
{
    QSqlQuery query(sqlite);
    QHashIterator<QPair<ushort,Contragent*>,Summary*> iter_summary(summary);
    query.prepare("INSERT INTO summary "
                  "(code, contragent_id, balance_begin, receipt_from_producers, receipt_from_wholesalers, receipt_import, receipt_consumption, receipt_other, receipt_move, consumption_retail, consumption_other, consumption_return, consumption_move, balance_end) VALUES "
                  "(:code, :contragent_id, :balance_begin, :receipt_from_producers, :receipt_from_wholesalers, :receipt_import, :receipt_consumption, :receipt_other, :receipt_move, :consumption_retail, :consumption_other, :consumption_return, :consumption_move, :balance_end)");
    while (iter_summary.hasNext()) {
        iter_summary.next();
        Summary* summary = iter_summary.value();
        query.bindValue(":code", summary->getCode());
        query.bindValue(":contragent_id", summary->getContragent()->getId());
        query.bindValue(":balance_begin", summary->getBalanceBegin());
        query.bindValue(":receipt_from_producers", summary->getReceiptFromProducers());
        query.bindValue(":receipt_from_wholesalers", summary->getReceiptFromWholesalers());
        query.bindValue(":receipt_import", summary->getReceiptImport());
        query.bindValue(":receipt_consumption", summary->getReceiptConsumption());
        query.bindValue(":receipt_other", summary->getReceiptOther());
        query.bindValue(":receipt_move", summary->getReceiptMove());
        query.bindValue(":consumption_retail", summary->getConsumptionRetail());
        query.bindValue(":consumption_other", summary->getConsumptionOther());
        query.bindValue(":consumption_return", summary->getConsumptionReturn());
        query.bindValue(":consumption_move", summary->getConsumptionMove());
        query.bindValue(":balance_end", summary->getBalanceEnd());

        query.exec();
    }
}

void AlkoData::readTables()
{
    idx_contragents.clear();
    idx_licenses.clear();
    idx_products.clear();

    contragents.clear();
    licenses.clear();
    summary.clear();
    oborot.clear();
    products.clear();

    readContragents();
    readLicenses();
    readProducts();
    readOborot();
    readSummary();
}

void AlkoData::readContragents()
{
    QSqlQuery query(sqlite);
    if (query.exec("SELECT id,name,inn,kpp,orgtype,country,area,producer,carrier FROM contragents")) {
        while(query.next()) {
            if (query.isValid()) {
                uint id = query.value(0).toUInt();
                QString name = query.value(1).toString();
                QString inn = query.value(2).toString();
                QString kpp = query.value(3).toString();
                uint orgtype = query.value(4).toUInt();
                uint country = query.value(5).toUInt();
                uint area = query.value(6).toUInt();
                bool producer = query.value(7).toBool();
                bool carrier = query.value(8).toBool();

                Contragent* contragent = new Contragent(id, name, inn, kpp);
                contragent->setOrgType(orgtype);
                contragent->setCountry(country);
                contragent->setArea(area);
                contragent->setProducer(producer);
                contragent->setCarrier(carrier);

                Contragent::qpair key(inn, kpp);
                contragents.insert(key, contragent);
                idx_contragents.insert(id, contragent);
            }
        }
    }
}

void AlkoData::readLicenses()
{
    QSqlQuery query(sqlite);
    if (query.exec("SELECT id,contragent_id,number,startdate,enddate,department FROM licenses")) {
        while(query.next()) {
            if (query.isValid()) {
                uint id = query.value(0).toUInt();
                uint contragent_id = query.value(1).toUInt();
                QString number = query.value(2).toString();
                QDate startdate = query.value(3).toDate();
                QDate enddate = query.value(4).toDate();
                QString department = query.value(5).toString();

                Contragent* contragent = searchContragent(contragent_id);
                if (contragent) {
                    License* license = new License(id, contragent, number, startdate, enddate, department);
                    contragent->addLicense(license);
                    licenses.insert(number, license);
                    idx_licenses.insert(id, license);
                }
            }
        }
    }
}

void AlkoData::readProducts()
{
     QSqlQuery query(sqlite);
     if (query.exec("SELECT id,type,license_id,supplier_id,producer_id,tdnumber,number,date,value FROM products")) {
         while(query.next()) {
             if (query.isValid()) {
                uint id = query.value(0).toUInt();
                ushort type = query.value(1).toUInt();
//                uint license_id = query.value(2).toUInt();
                uint supplier_id = query.value(3).toUInt();
                uint producer_id = query.value(4).toUInt();
                QString tdnumber = query.value(5).toString();
                QString number = query.value(6).toString();
                QDate date = query.value(7).toDate();
                double value = query.value(8).toDouble();

                Contragent* supplier = searchContragent(supplier_id);
                Contragent* producer = searchContragent(producer_id);
//                License* license = searchLicense(license_id);

                if (supplier && producer) {
                    Product *product = new Product(id, producer, supplier, type, number, date, tdnumber, value);
//                    if (license) {
//                        product->setLicense(license);
//                    }
                    products.append(product);
                    idx_products.insert(id, product);

                    oborot.insert(type, producer, supplier, product);
                }
             }
         }
     }
}

void AlkoData::readOborot()
{
//    QSqlQuery query(sqlite);
//    if (query.exec("SELECT code, contragent_id, balance_begin, receipt_from_producers, receipt_from_wholesalers, receipt_import, receipt_consumption, receipt_other, receipt_move, consumption_retail, consumption_other, consumption_return, consumption_move, balance_end FROM summary")) {
//        while(query.next()) {
//            if (query.isValid()) {

//            }
//        }
//    }
}

void AlkoData::readSummary()
{
    QSqlQuery query(sqlite);
    if (query.exec("SELECT code, contragent_id, balance_begin, receipt_from_producers, receipt_from_wholesalers, receipt_import, receipt_consumption, receipt_other, receipt_move, consumption_retail, consumption_other, consumption_return, consumption_move, balance_end FROM summary")) {
        while(query.next()) {
            if (query.isValid()) {
                ushort code = query.value(0).toUInt();
                uint contragent_id = query.value(1).toUInt();
                double balance_begin = query.value(2).toDouble();
                double receipt_from_producers = query.value(3).toDouble();
                double receipt_from_wholesalers = query.value(4).toDouble();
                double receipt_import = query.value(5).toDouble();
                double receipt_consumption = query.value(6).toDouble();
                double receipt_other = query.value(7).toDouble();
                double receipt_move = query.value(8).toDouble();
                double consumption_retail = query.value(9).toDouble();
                double consumption_other = query.value(10).toDouble();
                double consumption_return = query.value(11).toDouble();
                double consumption_move = query.value(12).toDouble();
                double balance_end = query.value(13).toDouble();

                Contragent* contragent = searchContragent(contragent_id);
                if (contragent) {
                    Summary *s = new Summary(code, contragent);
                    s->setBalanceBegin(balance_begin);
                    s->setBalanceEnd(balance_end);
                    s->setReceiptConsumption(receipt_consumption);
                    s->setReceiptFromProducers(receipt_from_producers);
                    s->setReceiptFromWholesalers(receipt_from_wholesalers);
                    s->setReceiptImport(receipt_import);
                    s->setReceiptMove(receipt_move);
                    s->setReceiptOther(receipt_other);
                    s->setConsumptionMove(consumption_move);
                    s->setConsumptionOther(consumption_other);
                    s->setConsumptionRetail(consumption_retail);
                    s->setConsumptionReturn(consumption_return);

                    QPair<ushort,Contragent*> key(code, contragent);
                    summary.insert(key, s);
                }
            }
        }
    }
}

void AlkoData::dropTables()
{
    QSqlQuery dropContragents("DROP TABLE IF EXISTS contragents", sqlite);
    QSqlQuery dropLicenses("DROP TABLE IF EXISTS licenses", sqlite);
    QSqlQuery dropProducts("DROP TABLE IF EXISTS products", sqlite);
    QSqlQuery dropSummary("DROP TABLE IF EXISTS summary", sqlite);
    QSqlQuery vacuumDB("VACUUM", sqlite);

    dropContragents.exec();
    dropLicenses.exec();
    dropProducts.exec();
    dropSummary.exec();
    vacuumDB.exec();
}

Contragent *AlkoData::searchContragent(uint contragent_id)
{
    QHash<uint,Contragent*>::iterator i = idx_contragents.find(contragent_id);
    if (i != idx_contragents.end() && i.key() == contragent_id) {
        return i.value();
    }

    return NULL;
}

License *AlkoData::searchLicense(uint license_id)
{
    QHash<uint,License*>::iterator i = idx_licenses.find(license_id);
    if (i != idx_licenses.end() && i.key() == license_id) {
        return i.value();
    }

    return NULL;
}

Product* AlkoData::searchProduct(uint product_id)
{
    QHash<uint,Product*>::iterator i = idx_products.find(product_id);
    if (i != idx_products.end() && i.key() == product_id) {
        return i.value();
    }

    return NULL;
}

void AlkoData::loadDB()
{
        readTables();
}

void AlkoData::saveDB()
{
        dropTables();

        createTables();
        storeData();
}
