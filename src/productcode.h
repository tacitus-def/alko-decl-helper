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

#ifndef PRODUCTCODE_H
#define PRODUCTCODE_H

#include <QString>

class ProductCode
{
public:
    ProductCode(ushort code, ushort declaration, bool licensed, QString title);

    ushort getCode() const;
    void setCode(const ushort &value);

    ushort getDeclaration() const;
    void setDeclaration(const ushort &value);

    bool getLicensed() const;
    void setLicensed(bool value);

    QString getTitle() const;
    void setTitle(const QString &value);

private:
    ushort code;
    ushort declaration;
    bool licensed;
    QString title;
};

#endif // PRODUCTCODE_H
