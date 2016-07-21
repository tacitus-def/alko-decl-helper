#ifndef LICENSE_H
#define LICENSE_H

#include <QDate>

class Contragent;

class License
{
public:
    License();
    ~License();
    License(Contragent* contragent, QString number, QDate startDate, QDate endDate, QString department);
    License(uint id, Contragent* contragent, QString number, QDate startDate, QDate endDate, QString department);

    bool isEmpty() const;

    QString getNumber() const;
    void setNumber(const QString &value);

    QDate getStartDate() const;
    void setStartDate(const QDate &value);

    QString getDepartment() const;
    void setDepartment(const QString &value);

    uint getId() const;
    void setId(const uint &value);

    QDate getEndDate() const;
    void setEndDate(const QDate &value);

    Contragent* getContragent() const;
    void setContragent(Contragent *value);

private:
    uint id;

    Contragent* contragent;
    QString number;
    QDate startDate;
    QDate endDate;
    QString department;
};

#endif // LICENSE_H
