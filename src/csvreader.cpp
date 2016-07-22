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

#include "csvreader.h"

CSVReader::CSVReader()
{
    init(0, -1);
}

CSVReader::CSVReader(QString file)
{
    init(0, -1);
    load(file);
}

CSVReader::CSVReader(QString file, int seek, int limit)
{
    init(seek, limit);
    load(file);
}

void CSVReader::load(QString filePath)
{
    load(filePath, seek, limit);
}

void CSVReader::init(int seek, int limit)
{
    this->seek = seek;
    this->limit = limit;
}

QVector<ushort> CSVReader::getFields() {
    return tableFields;
}

void CSVReader::detectFields(QString line)
{
    QMap<QString,ushort> fields;

    fields.insert("HIDE", (ushort) COLUMN_HIDE);
    fields.insert("PRODUCT_TYPE", (ushort) COLUMN_PRODUCT_TYPE);
    fields.insert("PRODUCER_NAME", (ushort) COLUMN_PRODUCER_NAME);
    fields.insert("PRODUCER_INN", (ushort) COLUMN_PRODUCER_INN);
    fields.insert("PRODUCER_KPP", (ushort) COLUMN_PRODUCER_KPP);
    fields.insert("SUPPLIER_NAME", (ushort) COLUMN_SUPPLIER_NAME);
    fields.insert("SUPPLIER_INN", (ushort) COLUMN_SUPPLIER_INN);
    fields.insert("SUPPLIER_KPP", (ushort) COLUMN_SUPPLIER_KPP);
    fields.insert("LICENSE_NUMBER", (ushort) COLUMN_LICENSE_NUMBER);
    fields.insert("LICENSE_SDATE", (ushort) COLUMN_LICENSE_SDATE);
    fields.insert("LICENSE_EDATE", (ushort) COLUMN_LICENSE_EDATE);
    fields.insert("LICENSE_DEPARTMENT", (ushort) COLUMN_LICENSE_DEPARTMENT);
    fields.insert("TTN_DATE", (ushort) COLUMN_TTN_DATE);
    fields.insert("TTN_NUMBER", (ushort) COLUMN_TTN_NUMBER);
    fields.insert("TD_NUMBER", (ushort) COLUMN_TD_NUMBER);
    fields.insert("NUMBER_DKL", (ushort) COLUMN_NUMBER_DKL);

    tableFields.clear();

    QStringList columns = parseRow(line);
    for (int i = 0; i < columns.length(); i ++) {
        QString column = columns[i].trimmed().toUpper();
        if (fields.contains(column)) {
            tableFields.append(fields[column]);
        }
        else {
            tableFields.append((ushort) COLUMN_HIDE);
        }
    }
}

QStringList CSVReader::parseRow(QString line)
{
    int length = line.length();
    bool isValue = false;
    bool isDelimiter = false;
    bool isQuote = false;
    bool quoteIn = false;
    QStringList columns;
    columns.clear();

    QString value = "";
    for (int j = 0; j < length; j ++) {
        QChar symbol = line.at(j);
        if (symbol == '"') {
            isDelimiter = false;
            if (isValue) {
                if (isQuote) {
                    quoteIn = !quoteIn;
                    if (!quoteIn) {
                        value += "\"";
                    }
                }
                else {
                    value += symbol;
                }
            }
            else {
                isQuote = true;
                isValue = true;
                quoteIn = false;
            }
        }
        else if (!isQuote) {
            if (symbol == ';' && (delimiters & SEPARATOR_SEMICOLON)) {
                    isValue = false;
                    isQuote = false;
                    columns.append(value);
                    value = "";
                    isDelimiter = true;
            }
            else if (symbol == ',' && (delimiters & SEPARATOR_COMMA)) {
                    isValue = false;
                    isQuote = false;
                    columns.append(value);
                    value = "";
                    isDelimiter = true;
            }
            else if (symbol == '\t' && (delimiters & SEPARATOR_TABULATION)) {
                    isValue = false;
                    isQuote = false;
                    columns.append(value);
                    value = "";
                    isDelimiter = true;
            }
            else if (symbol == '\n' || symbol == '\r') {
                value += " ";
            }
            else {
                isValue = true;
                value += symbol;
                isDelimiter = false;
            }
        }
        else {
            isDelimiter = false;
            if (isValue) {
                if (quoteIn) {
                    isValue = false;
                    isQuote = false;
                    columns.append(value);
                    value = "";
                }
                else {
                    value += symbol;
                }
            }
            else {
                isValue = true;
                value += symbol;
            }
        }
    }
    if (isValue || isDelimiter) {
        columns.append(value);
    }

    return columns;
}

void CSVReader::load(QString filePath, int seek, int limit)
{
    int i_seek = 1;
    int i_limit = 0;

    this->init(seek, limit);

    lines.clear();
    QFile f(filePath);
    if (f.open(QIODevice::ReadOnly | QIODevice::Text)) {
        while (!f.atEnd()) {
            QString line = f.readLine();
            if (this->seek < i_seek) {
                if (this->limit < 0 || i_limit < this->limit) {
                    lines.append(line);
                    i_limit ++;
                }
                else {
                    break;
                }
            }
            else {
                i_seek ++;
            }
        }
        f.close();
    }
}

void CSVReader::setDelimiters(ushort value)
{
    delimiters = value;
}

void CSVReader::parse() {
    data.clear();
    int start = 0;
    QStringList markers = parseRow (lines.at(0));
    if (markers[0] == "#") {
        start = 2;
        detectFields(lines.at(1));
    }

    for (int i = start; i < lines.size(); i++) {
        QString line = lines.at(i);

        data.append(parseRow(line));
    }
}

QVector<QStringList> CSVReader::getData()
{
    return data;
}

