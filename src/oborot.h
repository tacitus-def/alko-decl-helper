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
