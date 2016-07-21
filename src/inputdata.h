#ifndef INPUTDATA_H
#define INPUTDATA_H

#include <QDate>

class InputData
{
public:
    InputData();

    QString SupplierName;
    QString SupplierInn;
    QString SupplierKpp;
    QString ProducerName;
    QString ProducerInn;
    QString ProducerKpp;
    QString LicenseNumber;
    QDate LicenseSdate;
    QDate LicenseEdate;
    QString LicenseDepartment;
    ushort ProductType;
    QString TtnNumber;
    QDate TtnDate;
    QString TdNumber;
    double NumberDkl;
};

#endif // INPUTDATA_H
