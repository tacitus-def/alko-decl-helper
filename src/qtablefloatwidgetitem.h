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

#ifndef QTABLEFLOATWIDGETITEM_H
#define QTABLEFLOATWIDGETITEM_H

#include <QTableWidgetItem>

class QTableFloatWidgetItem : public QTableWidgetItem
{
public:
    QTableFloatWidgetItem();
    void setFormat(char format = 'f', int precision = 5);
    QString text() const;

private:
    char format;
    int  precision;

};

#endif // QTABLEFLOATWIDGETITEM_H
