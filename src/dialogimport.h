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

#ifndef DIALOGIMPORT_H
#define DIALOGIMPORT_H

#include <QDialog>
#include <QFileDialog>
#include <QFileInfo>
#include <QFile>
#include <QRegularExpression>
#include <QMenu>
#include <QDebug>
#include <cmath>
#include "csvreader.h"
#include "inputdata.h"

namespace Ui {
class DialogImport;
}

class DialogImport : public QDialog
{
    Q_OBJECT
    
public:

    explicit DialogImport(QWidget *parent = 0);
    ~DialogImport();
    
    QVector<InputData> getData();

    void resetAllowedTypes();
    void setAllowedTypes(QList<ushort> types);
private slots:
    void on_btnBrowse_clicked();
    void changeSeparator();

    void on_lineStart_valueChanged(int arg1);
    void tblCtxMenu(const QPoint &pos);

    void cctHide();
    void cctSupplierName();
    void cctSupplierInn();
    void cctSupplierKpp();
    void cctProducerName();
    void cctProducerInn();
    void cctProducerKpp();
    void cctLicenseNumber();
    void cctLicenseSDate();
    void cctLicenseEDate();
    void cctLicenseDepartment();
    void cctProductType();
    void cctTtnNumber();
    void cctTtnDate();
    void cctTdNumber();
    void cctNumberDkl();

    void changeColumnType(int column, int type);

private:
    QString filePath;
    QDate parseDate(QString value);

    CSVReader csvReader;
    QString typeLabels [16];
    QVector<ushort> columnTypes;
    QList<ushort> allowedTypes;
    ushort separators;
    ushort lineStart;

    QVector<QStringList> table;

    Ui::DialogImport *ui;

    void initDefaults();
    void initForm();
    void readFromFile(QString filePath);
    void checkboxStates();
    void resizeTable();
    void fillTable();
    void horizontalHeader();

    QVector<InputData> parseLines(QVector<QStringList> table);
};

#endif // DIALOGIMPORT_H
