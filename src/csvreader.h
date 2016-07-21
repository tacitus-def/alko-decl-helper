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
