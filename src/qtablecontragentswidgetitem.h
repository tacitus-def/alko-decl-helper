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

#ifndef QTABLECONTRAGENTSWIDGETITEM_H
#define QTABLECONTRAGENTSWIDGETITEM_H

#include <QTableWidgetItem>
#include "contragent.h"

class QTableContragentsWidgetItem : public QTableWidgetItem
{
public:
    QTableContragentsWidgetItem();
    QTableContragentsWidgetItem(Contragent *value);
    Contragent *getContragent() const;
    void setContragent(Contragent *value);

private:
    Contragent *contragent;
};

#endif // QTABLECONTRAGENTSWIDGETITEM_H
