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
