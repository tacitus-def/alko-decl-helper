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

#ifndef CSVREADER_H
#define CSVREADER_H

#include <stdio.h>
#include <iostream>

#include <QStringList>
#include <QVector>
#include <QFile>
#include <QMap>

class CSVReader
{
public:
    static const ushort SEPARATOR_COMMA = 1;
    static const ushort SEPARATOR_TABULATION = 2;
    static const ushort SEPARATOR_SEMICOLON = 4;
    static const ushort SEPARATOR_ALL = SEPARATOR_COMMA | SEPARATOR_SEMICOLON | SEPARATOR_TABULATION;

    static const ushort COLUMN_HIDE = 0;
    static const ushort COLUMN_PRODUCT_TYPE = 1;
    static const ushort COLUMN_SUPPLIER_NAME = 2;
    static const ushort COLUMN_SUPPLIER_INN = 3;
    static const ushort COLUMN_SUPPLIER_KPP = 4;
    static const ushort COLUMN_PRODUCER_NAME = 5;
    static const ushort COLUMN_PRODUCER_INN = 6;
    static const ushort COLUMN_PRODUCER_KPP = 7;
    static const ushort COLUMN_LICENSE_NUMBER = 8;
    static const ushort COLUMN_LICENSE_SDATE = 9;
    static const ushort COLUMN_LICENSE_EDATE = 10;
    static const ushort COLUMN_LICENSE_DEPARTMENT = 11;
    static const ushort COLUMN_TTN_DATE = 12;
    static const ushort COLUMN_TTN_NUMBER = 13;
    static const ushort COLUMN_TD_NUMBER = 14;
    static const ushort COLUMN_NUMBER_DKL = 15;

    CSVReader();
    CSVReader(QString file);
    CSVReader(QString file, int seek, int limit);

    void load(QString filePath);
    void load(QString filePath, int seek, int limit);
    void parse();

    void setDelimiters(ushort value);

    QVector<QStringList> getData();
    QVector<ushort> getFields();
private:
    QVector<QStringList> data;
    ushort delimiters;
    QStringList lines;
    QVector<ushort> tableFields;

    int limit;
    int seek;

    void init(int seek, int limit);
    QStringList parseRow(QString line);
    void detectFields(QString line);
};


#endif // CSVREADER_H
