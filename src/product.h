#ifndef PRODUCT_H
#define PRODUCT_H

#include "contragent.h"
#include "license.h"

class Product
{
public:
    Product();
    ~Product();
    Product(Contragent* producer, Contragent* supplier, ushort type, QString number, QDate date, QString tdNumber, double value);
    Product(uint id, Contragent* producer, Contragent* supplier, ushort type, QString number, QDate date, QString tdNumber, double value);

    void setTTN(QString number, QDate date);
    void setContragents(Contragent *producer, Contragent *supplier);

    Contragent* getProducer() const;
    void setProducer(Contragent *value);

    Contragent* getSupplier() const;
    void setSupplier(Contragent *value);

    QString getTdNumber() const;
    void setTdNumber(const QString &value);

    QString getNumber() const;
    void setNumber(const QString &value);

    QDate getDate() const;
    void setDate(const QDate &value);

    uint getId() const;
    void setId(const uint &value);

    ushort getType() const;
    void setType(const ushort &value);

    double getValue() const;
    void setValue(const double &value);

    License* getLicense() const;
    void setLicense(License *value);

private:
    uint id;
    ushort type;

    License* license;

    Contragent* supplier;
    Contragent* producer;

    QString tdNumber;
    QString number;

    QDate date;
    double value;

    void setLicense();
    void setValues(Contragent* producer, Contragent* supplier, ushort type, QString number, QDate date, QString td_number, double value);
};

#endif // PRODUCT_H
