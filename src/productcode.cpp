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

#include "productcode.h"

ProductCode::ProductCode(ushort code, ushort declaration, bool licensed, QString title)
{
    this->code = code;
    this->declaration = declaration;
    this->licensed = licensed;
    this->title = title;
}

QString ProductCode::getTitle() const
{
    return title;
}

void ProductCode::setTitle(const QString &value)
{
    title = value;
}

bool ProductCode::getLicensed() const
{
    return licensed;
}

void ProductCode::setLicensed(bool value)
{
    licensed = value;
}

ushort ProductCode::getDeclaration() const
{
    return declaration;
}

void ProductCode::setDeclaration(const ushort &value)
{
    declaration = value;
}

ushort ProductCode::getCode() const
{
    return code;
}

void ProductCode::setCode(const ushort &value)
{
    code = value;
}
