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

#ifndef PROCESSDATA_H
#define PROCESSDATA_H

#include <QVector>
#include <QPair>
#include <QHash>
#include <cmath>
#include "contragent.h"
#include "product.h"
#include "license.h"
#include "csvreader.h"
#include "inputdata.h"
#include "oborot.h"
#include "summary.h"

class ProcessData
{
public:
    ProcessData(QVector<InputData> data);

    QHash<QPair<ushort, Contragent *>, Summary *> getSummary();
    Oborot getOborot();
    QHash<Contragent::qpair, Contragent*> getContragents();
    QHash<QString,License*> getLicenses();
    QVector<Product*> getProducts();

private:
    QHash<QPair<ushort,Contragent*>,Summary*> summary;
    Oborot oborot;

    QHash<Contragent::qpair, Contragent*> contragents;
    QHash<QString,License*> licenses;
    QVector<Product*> products;

    void process(QVector<InputData> data);

    Contragent* newContragent(uint id, QString name, QString inn, QString kpp, bool producer, bool carrier);
};

#endif // PROCESSDATA_H
