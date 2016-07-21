#ifndef DB_H
#define DB_H

#include <QHash>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include "productcode.h"

class DB
{
public:
    DB();
    ~DB();
    QHash<ushort, ProductCode> getProductCodes() const;
    void setProductCodes(const QHash<ushort, ProductCode> &value);

private:
    QSqlDatabase sqlite;
    QHash<ushort, ProductCode> productCodes;

    void loadProductCodes();
};

#endif // DB_H
