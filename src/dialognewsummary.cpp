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

#include "dialognewsummary.h"
#include "ui_dialognewsummary.h"

DialogNewSummary::DialogNewSummary(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogNewSummary)
{
    ui->setupUi(this);
}

DialogNewSummary::~DialogNewSummary()
{
    delete ui;
}

void DialogNewSummary::setContragents(QHash<Contragent::qpair, Contragent *> contragents)
{
    list.clear();
    ui->inputProducer->clear();
    QHashIterator<Contragent::qpair, Contragent*> iter(contragents);
    while(iter.hasNext()) {
        iter.next();
        Contragent* row = iter.value();
        if (row->getProducer()) {
            list.insert(row->getId(), row);
            ui->inputProducer->addItem(QString("%1 — (ИНН %2/КПП %3)")
                                           .arg(row->getName())
                                           .arg(row->getInn())
                                           .arg(row->getKpp()),
                                       row->getId());
        }
    }
}

QPair<ushort, Contragent *> DialogNewSummary::getSummaryPair()
{
    uint code = ui->inputCode->text().toUInt();
    uint producer = ui->inputProducer->currentData().toUInt();

    QPair<ushort,Contragent*> pair;

    if (! list.isEmpty() && list.find(producer) != list.end()) {
        pair = QPair<ushort,Contragent*>(code, list.find(producer).value());
    }
    else {
        pair = QPair<ushort,Contragent*>(code, NULL);
    }
    return pair;
}
