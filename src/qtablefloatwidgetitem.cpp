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

#include "qtablefloatwidgetitem.h"

QTableFloatWidgetItem::QTableFloatWidgetItem() : QTableWidgetItem()
{
    format = 'f';
    precision = 5;
}

void QTableFloatWidgetItem::setFormat(char format, int precision)
{
    this->format = format;
    this->precision = precision;
}

QString QTableFloatWidgetItem::text() const
{
    return QString::number (data(Qt::DisplayRole).toDouble(), format, precision);
}
