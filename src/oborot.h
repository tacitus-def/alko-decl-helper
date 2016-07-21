#ifndef OBOROT_H
#define OBOROT_H

#include<QVector>
#include "contragent.h"
#include "product.h"

class Oborot
{
public:
    typedef QPair<Contragent*, License*> pairContragentLicense;
    typedef QHash<pairContragentLicense, QList<Product*>* > hashProductList;
    typedef QHash<Contragent*, hashProductList*> hashContragentProductList;
    typedef QHash<ushort,hashContragentProductList*> hashCodeList;

    Oborot();
    ~Oborot();

    hashCodeList &getItems();
    void clear();
    void insert(ushort type, Contragent * producer, Contragent * supplier, Product * product);

    void insert(ushort type, Contragent *producer);
private:

    hashCodeList items;
};

#endif // OBOROT_H
