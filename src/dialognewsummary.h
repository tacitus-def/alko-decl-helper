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

#ifndef DIALOGNEWSUMMARY_H
#define DIALOGNEWSUMMARY_H

#include <QDialog>
#include <QHash>
#include "contragent.h"
#include "summary.h"

namespace Ui {
class DialogNewSummary;
}

class DialogNewSummary : public QDialog
{
    Q_OBJECT

public:
    explicit DialogNewSummary(QWidget *parent = 0);
    ~DialogNewSummary();

    void setContragents(QHash<Contragent::qpair, Contragent*> contragents);
    QPair<ushort, Contragent *> getSummaryPair();
private:
    Ui::DialogNewSummary *ui;
    QHash<uint, Contragent*> list;
};

#endif // DIALOGNEWSUMMARY_H
