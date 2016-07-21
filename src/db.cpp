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
