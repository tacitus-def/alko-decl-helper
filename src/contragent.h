#ifndef CONTRAGENT_H
#define CONTRAGENT_H

#include <QDate>
#include <QHash>

class License;

class Contragent
{
public:
    typedef QPair<QString,QString> qpair;
    typedef QHash<qpair, Contragent*>::iterator iterator;

    Contragent();
    ~Contragent();

    Contragent(QString name, QString inn, QString kpp);
    Contragent(uint id, QString name, QString inn, QString kpp);

    void setCodes(uint country, uint area);

    void setCarrier(bool carrier);
    bool getCarrier();

    void setProducer(bool producer);
    bool getProducer();

    License* addLicense(License *license);

    License* findLicense(QDate date);
    QHash<QString,License*> getLicenses();

    bool hasLicense(QString number);

    uint getOrgType();
    void setOrgType(uint orgType);

    uint getId();
    void setId(const uint &value);

    QString getInn() const;
    void setInn(const QString &value);

    QString getKpp() const;
    void setKpp(const QString &value);

    QString getName() const;
    void setName(const QString &value);

    uint getCountry() const;
    void setCountry(const uint &value);

    uint getArea() const;
    void setArea(const uint &value);

private:
    uint id;
    QString name;
    QString inn;
    QString kpp;
    uint orgType;

    uint country;
    uint area;

    bool producer;
    bool carrier;

    QHash<QString,License*> licenses;

    void init();
};

inline uint qHash(const Contragent &key)
{
    QString k = key.getInn() + "_" + key.getKpp();
    return qHash(k);
}

inline bool operator==(const Contragent &a, const Contragent &b)
{
    return a.getInn() == b.getInn() && a.getKpp() == b.getKpp();
}

#endif // CONTRAGENT_H
