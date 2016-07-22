//
//  Copyright (c) 2016 Petr Sleptsov <spetr@bk.ru>
//
//  This file is part of Alko-decl-helper.
//
//  Alko-decl-helper is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  Alko-decl-helper is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with Alko-decl-helper.  If not, see <http://www.gnu.org/licenses/>.
//

#include "oborot.h"

Oborot::Oborot()
{

}

Oborot::~Oborot()
{
    items.clear();
}

Oborot::hashCodeList &Oborot::getItems()
{
    return items;
}

void Oborot::clear()
{
    items.clear();
}

void Oborot::insert(ushort type, Contragent * producer, Contragent * supplier, Product * product)
{
    Contragent* key2 = producer;
    QPair<Contragent*, License*> key3(supplier, product->getLicense());

    ushort key1 = type;
    Oborot::hashCodeList::iterator iter1 = items.find(key1);
    if (iter1 == items.end()) {
        QList<Product*>* t4 = new QList<Product*>();
        Oborot::hashProductList* t3 = new Oborot::hashProductList();
        Oborot::hashContragentProductList*  t2 = new Oborot::hashContragentProductList();

        t3->insert(key3, t4);
        t2->insert(key2, t3);
        iter1 = items.insert(key1, t2);
    }

    Oborot::hashContragentProductList* value1 = iter1.value();
    Oborot::hashContragentProductList::iterator iter2 = value1->find(key2);
    if (iter2 == value1->end()) {
        QList<Product*>* t4 = new QList<Product*>();
        Oborot::hashProductList* t3 = new Oborot::hashProductList();
        t3->insert(key3, t4);

        iter2 = value1->insert(key2, t3);
    }

    Oborot::hashProductList* value2 = iter2.value();
    Oborot::hashProductList::iterator iter3 = value2->find(key3);

    if (iter3 == value2->end()) {
        iter3 = value2->insert(key3, new QList<Product*>());
    }

    QList<Product*>* products = iter3.value();
    products->append(product);
}

void Oborot::insert(ushort type, Contragent * producer)
{
    Contragent* key2 = producer;

    ushort key1 = type;
    Oborot::hashCodeList::iterator iter1 = items.find(key1);
    if (iter1 == items.end()) {
        Oborot::hashProductList* t3 = new Oborot::hashProductList();
        Oborot::hashContragentProductList*  t2 = new Oborot::hashContragentProductList();

        t2->insert(key2, t3);
        iter1 = items.insert(key1, t2);
    }

    Oborot::hashContragentProductList* value1 = iter1.value();
    Oborot::hashContragentProductList::iterator iter2 = value1->find(key2);
    if (iter2 == value1->end()) {
        Oborot::hashProductList* t3 = new Oborot::hashProductList();

        iter2 = value1->insert(key2, t3);
    }
}
