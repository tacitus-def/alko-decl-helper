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

#ifndef QTABLESUMMARYWIDGETITEM_H
#define QTABLESUMMARYWIDGETITEM_H

#include <QTableWidgetItem>
#include "summary.h"

class QTableSummaryWidgetItem : public QTableWidgetItem
{
public:
    QTableSummaryWidgetItem();
    QTableSummaryWidgetItem(Summary *value);
    Summary *getSummary() const;
    void setSummary(Summary *value);
    bool operator <(const QTableWidgetItem &other) const;
private:
    Summary *summary;
};

#endif // QTABLESUMMARYWIDGETITEM_H
