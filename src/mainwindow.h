#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include <QLocale>
#include <QMessageBox>

#include "dialogsettings.h"
#include "dialogimport.h"
#include "dialognewcontragent.h"
#include "dialognewsummary.h"
#include "wizardexport.h"
#include "productcode.h"
#include "processdata.h"
#include "contragent.h"
#include "settings.h"
#include "license.h"
#include "product.h"
#include "db.h"
#include "exportcontragents.h"
#include "nonedittablecolumndelegate.h"
#include "qtablecontragentswidgetitem.h"
#include "qtablesummarywidgetitem.h"
#include "qtablefloatwidgetitem.h"
#include "calculator.h"
#include "alkodata.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_action_exit_triggered();

    void on_action_import_triggered();

    void on_action_clear_triggered();

    void on_action_params_triggered();

    void on_action_export_alko_triggered();

    void changeContragentTableCellValue(int row, int column);
    void changeSummaryTableCellValue(int row, int column);
    void on_action_export_contragents_triggered();

    void on_btnNewContragent_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_action_triggered();

    void on_action_save_triggered();

    void on_action_load_triggered();

    void on_action_save_as_triggered();

    void on_action_close_triggered();

private:
    DB db;
    AlkoData alkoData;

    QHash<QPair<ushort,Contragent*>,Summary*> summary;
    Oborot oborot;

    QHash<Contragent::qpair, Contragent*> contragents;
    QHash<QString,License*> licenses;
    QVector<Product*> products;

    QVector<InputData> inputData;

    Ui::MainWindow *ui;

    void fillSummary();
    void fillDetail();
    void fillContragents();
    void fillLicenses();

    void setupTables();
    void setupTableContragents();
    void setupTableDetail();
    void setupTableSummary();
    void setupTableLicenses();
    double calculateValue(QString value);
    void connectTableSignals();
    void disconnectTableSignals();
    void filterSummaryTable();
    void resetFilterSummaryTable();
    uint getContragentNextId();
};

#endif // MAINWINDOW_H
