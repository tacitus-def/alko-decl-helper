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

#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setupTables();
    connectTableSignals();
    Settings::getInstance()->readIniFile();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectTableSignals() {
    connect(ui->contragentsTable, SIGNAL(cellChanged(int, int)), this, SLOT(changeContragentTableCellValue(int, int)));
    connect(ui->summaryTable, SIGNAL(cellChanged(int, int)), this, SLOT(changeSummaryTableCellValue(int, int)));
}

void MainWindow::disconnectTableSignals() {
    disconnect(ui->contragentsTable, SIGNAL(cellChanged(int, int)), this, SLOT(changeContragentTableCellValue(int, int)));
    disconnect(ui->summaryTable, SIGNAL(cellChanged(int, int)), this, SLOT(changeSummaryTableCellValue(int, int)));
}

void MainWindow::on_action_exit_triggered()
{
    exit(0);
}

void MainWindow::setupTableContragents() {
    QStringList headers;

    headers.append("#");
    headers.append("Наименование");
    headers.append("ИНН");
    headers.append("КПП");
    headers.append("Код страны");
    headers.append("Код региона");
    headers.append("Производитель/импортер");
    headers.append("Поставщик");
    headers.append("Количество лицензий");
    ui->contragentsTable->setColumnCount(headers.size());
    ui->contragentsTable->setHorizontalHeaderLabels(headers);
    for (int i = 0; i < headers.size(); i ++) {
        ui->contragentsTable->horizontalHeaderItem(i)->setTextAlignment(Qt::AlignLeft);
    }
    ui->contragentsTable->setItemDelegateForColumn(0, new NonEditTableColumnDelegate());
    ui->contragentsTable->setItemDelegateForColumn(6, new NonEditTableColumnDelegate());
    ui->contragentsTable->setItemDelegateForColumn(7, new NonEditTableColumnDelegate());
    ui->contragentsTable->setItemDelegateForColumn(8, new NonEditTableColumnDelegate());
    ui->contragentsTable->setSortingEnabled(true);
}

void MainWindow::setupTableDetail() {
    QStringList headers;

    headers.append("Код продукта");
    headers.append("Тип продукта");
    headers.append("Производитель");
    headers.append("Поставщик/импортёр");
    headers.append("Номер ТТН");
    headers.append("Дата ТТН");
    headers.append("Номер ТД");
    headers.append("ДКЛ");

    ui->detailTable->setColumnCount(8);
    ui->detailTable->setHorizontalHeaderLabels(headers);
    for (int i = 0; i < headers.size(); i ++) {
        ui->detailTable->horizontalHeaderItem(i)->setTextAlignment(Qt::AlignLeft);
    }
    ui->detailTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->detailTable->setSortingEnabled(true);
}

void MainWindow::setupTableSummary() {
    QStringList headers;

    headers.append("Код");
    headers.append("Производитель");
    headers.append("Остаток на начало периода");
    headers.append("Поступление от производителей");
    headers.append("Поступление от оптовиков");
    headers.append("Поступление по импорту");
    headers.append("Возврат от покупателей");
    headers.append("Прочее поступление");
    headers.append("Перемещение");
    headers.append("Розничная продажа");
    headers.append("Прочий расход");
    headers.append("Возврат поставщику");
    headers.append("Расход перемещение");
    headers.append("Остаток на конец периода");

    ui->summaryTable->setColumnCount(headers.size());
    ui->summaryTable->setHorizontalHeaderLabels(headers);
    for (int i = 0; i < headers.size(); i ++) {
        ui->summaryTable->horizontalHeaderItem(i)->setTextAlignment(Qt::AlignLeft);
    }
    ui->summaryTable->setItemDelegateForColumn(0, new NonEditTableColumnDelegate());
    ui->summaryTable->setItemDelegateForColumn(1, new NonEditTableColumnDelegate());
    ui->summaryTable->setItemDelegateForColumn(13, new NonEditTableColumnDelegate());
    ui->summaryTable->setSortingEnabled(true);
}

void MainWindow::setupTableLicenses() {
    QStringList headers;

    headers.append("Поставщик/импортёр");
    headers.append("Серия и номер");
    headers.append("Дата выдачи");
    headers.append("Дата окончания действия");
    headers.append("Лицензиар");

    ui->licensesTable->setColumnCount(5);
    ui->licensesTable->setHorizontalHeaderLabels(headers);
    for (int i = 0; i < headers.size(); i ++) {
        ui->licensesTable->horizontalHeaderItem(i)->setTextAlignment(Qt::AlignLeft);
    }
    ui->licensesTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->licensesTable->setSortingEnabled(true);
}

void MainWindow::setupTables() {
    setupTableContragents();
    setupTableDetail();
    setupTableLicenses();
    setupTableSummary();
}

void MainWindow::fillContragents() {
    ui->contragentsTable->clearContents();
    ui->contragentsTable->setRowCount(contragents.size());
    ui->contragentsTable->setSortingEnabled(false);
    QHashIterator<QPair<QString,QString>,Contragent*> iter(contragents);
    uint i = 0;
    while(iter.hasNext()) {
        iter.next();
        Contragent* row = iter.value();
        QTableContragentsWidgetItem *cid = new QTableContragentsWidgetItem(row);
        QTableContragentsWidgetItem *cname = new QTableContragentsWidgetItem(row);
        QTableContragentsWidgetItem *cinn  = new QTableContragentsWidgetItem(row);
        QTableContragentsWidgetItem *ckpp  = new QTableContragentsWidgetItem(row);
        QTableContragentsWidgetItem *ccountry = new QTableContragentsWidgetItem(row);
        QTableContragentsWidgetItem *carea    = new QTableContragentsWidgetItem(row);
        QTableContragentsWidgetItem *cproducer = new QTableContragentsWidgetItem(row);
        QTableContragentsWidgetItem *ccarrier  = new QTableContragentsWidgetItem(row);
        QTableContragentsWidgetItem *lcount   = new QTableContragentsWidgetItem();

        // cid->setText(QString::number(row->getId()));
        cid->setData(Qt::DisplayRole, row->getId());
        cname->setText(row->getName());
        cinn->setText(row->getInn());
        ckpp->setText(row->getKpp());
        // ccountry->setText(QString::number(row->getCountry()));
        ccountry->setData(Qt::DisplayRole, row->getCountry());
        // carea->setText(QString::number(row->getArea()));
        carea->setData(Qt::DisplayRole, row->getArea());
        cproducer->setCheckState(row->getProducer() ? Qt::Checked : Qt::Unchecked);
        ccarrier->setCheckState(row->getCarrier() ? Qt::Checked : Qt::Unchecked);
        //lcount->setText(QString::number(row->getLicenses().size()));
        lcount->setData(Qt::DisplayRole, row->getLicenses().size());

        cid     ->setTextAlignment(Qt::AlignRight);
        cinn    ->setTextAlignment(Qt::AlignRight);
        ckpp    ->setTextAlignment(Qt::AlignRight);
        ccountry->setTextAlignment(Qt::AlignRight);
        carea   ->setTextAlignment(Qt::AlignRight);
        lcount  ->setTextAlignment(Qt::AlignRight);

        ui->contragentsTable->setItem(i, 0, cid);
        ui->contragentsTable->setItem(i, 1, cname);
        ui->contragentsTable->setItem(i, 2, cinn);
        ui->contragentsTable->setItem(i, 3, ckpp);
        ui->contragentsTable->setItem(i, 4, ccountry);
        ui->contragentsTable->setItem(i, 5, carea);
        ui->contragentsTable->setItem(i, 6, cproducer);
        ui->contragentsTable->setItem(i, 7, ccarrier);
        ui->contragentsTable->setItem(i, 8, lcount);

        i ++;
    }
    ui->contragentsTable->setSortingEnabled(true);
}

void MainWindow::fillDetail() {
    QHash<ushort,ProductCode> productCodes = db.getProductCodes();
    ui->detailTable->setSortingEnabled(false);
    ui->detailTable->clearContents();
    ui->detailTable->setRowCount(products.size());

    for (int i=0; i < products.size(); i++) {
        QTableWidgetItem *ccode = new QTableWidgetItem();
        QTableWidgetItem *ctype = new QTableWidgetItem();
        QTableWidgetItem *cproducer = new QTableWidgetItem();
        QTableWidgetItem *csupplier = new QTableWidgetItem();
        QTableWidgetItem *cnumberttn = new QTableWidgetItem();
        QTableWidgetItem *cdatettn = new QTableWidgetItem();
        QTableWidgetItem *cnumbertd = new QTableWidgetItem();
        QTableWidgetItem *cnumberdkl = new QTableWidgetItem();

        Product* product = products.at(i);

        ccode->setText(QString::number(product->getType()));
        QHash<ushort,ProductCode>::iterator iter = productCodes.find(product->getType());
        if (iter != productCodes.end()) {
            ctype->setText(iter.value().getTitle());
            License *product_license = product->getLicense();
            QDate product_date = product->getDate();
            /*
             * Поставщик выделяется красным цветом в случае, если требуется
             * лицензия для данного типа продукта и лицензия отсутствует или просрочена
             */
            if (iter.value().getLicensed() && (
                        ! product_license  ||
                        product_license->isEmpty() ||
                        (
                            product_date < product_license->getStartDate() ||
                            product_license->getEndDate() < product_date
                        )
                    )
                )
            {
                csupplier->setData(Qt::BackgroundRole, QVariant(QBrush(Qt::red)));
            }
        }

        cproducer->setText(product->getProducer()->getName());
        csupplier->setText(product->getSupplier()->getName());
        cnumberttn->setText(product->getNumber());
        cdatettn->setText(product->getDate().toString("dd.MM.yyyy"));
        cnumbertd->setText(product->getTdNumber());
        cnumberdkl->setText(QString::number(product->getValue(), 'f', 5));
        cnumberdkl->setTextAlignment(Qt::AlignRight);

        ui->detailTable->setItem(i, 0, ccode);
        ui->detailTable->setItem(i, 1, ctype);
        ui->detailTable->setItem(i, 2, cproducer);
        ui->detailTable->setItem(i, 3, csupplier);
        ui->detailTable->setItem(i, 4, cnumberttn);
        ui->detailTable->setItem(i, 5, cdatettn);
        ui->detailTable->setItem(i, 6, cnumbertd);
        ui->detailTable->setItem(i, 7, cnumberdkl);
    }
    ui->detailTable->setSortingEnabled(true);
}

void MainWindow::fillSummary() {
    ui->summaryTable->setSortingEnabled(false);
    ui->summaryTable->clearContents();
    ui->summaryTable->setRowCount(summary.size());
    QHashIterator<QPair<ushort,Contragent*>,Summary*> iter(summary);
    uint r = 0;
    while(iter.hasNext()) {
        iter.next();

        Summary *value = iter.value();
        QTableSummaryWidgetItem *ccode = new QTableSummaryWidgetItem(value);
        QTableSummaryWidgetItem *cproducer = new QTableSummaryWidgetItem(value);

        QTableSummaryWidgetItem *cbalance_begin = new QTableSummaryWidgetItem(value);
        QTableSummaryWidgetItem *creceipt_from_producers = new QTableSummaryWidgetItem(value);
        QTableSummaryWidgetItem *creceipt_from_wholesalers = new QTableSummaryWidgetItem(value);
        QTableSummaryWidgetItem *creceipt_import = new QTableSummaryWidgetItem(value);
        QTableSummaryWidgetItem *creceipt_consumption = new QTableSummaryWidgetItem(value);
        QTableSummaryWidgetItem *creceipt_other = new QTableSummaryWidgetItem(value);
        QTableSummaryWidgetItem *creceipt_move = new QTableSummaryWidgetItem(value);
        QTableSummaryWidgetItem *cconsumption_retail = new QTableSummaryWidgetItem(value);
        QTableSummaryWidgetItem *cconsumption_other = new QTableSummaryWidgetItem(value);
        QTableSummaryWidgetItem *cconsumption_return = new QTableSummaryWidgetItem(value);
        QTableSummaryWidgetItem *cconsumption_move = new QTableSummaryWidgetItem(value);
        QTableSummaryWidgetItem *cbalance_end = new QTableSummaryWidgetItem(value);


        ccode->setText(QString::number(iter.key().first));

        cproducer->setText(iter.key().second->getName());

        cbalance_begin
                ->setText(QString::number(value->getBalanceBegin(), 'f', 5));
        creceipt_from_producers
                ->setText(QString::number(value->getReceiptFromProducers(), 'f', 5));
        creceipt_from_wholesalers
                ->setText(QString::number(value->getReceiptFromWholesalers(), 'f', 5));
        creceipt_import
                ->setText(QString::number(value->getReceiptImport(), 'f', 5));
        creceipt_consumption
                ->setText(QString::number(value->getReceiptConsumption(), 'f', 5));
        creceipt_other
                ->setText(QString::number(value->getReceiptOther(), 'f', 5));
        creceipt_move
                ->setText(QString::number(value->getReceiptMove(), 'f', 5));
        cconsumption_retail
                ->setText(QString::number(value->getConsumptionRetail(), 'f', 5));
        cconsumption_other
                ->setText(QString::number(value->getConsumptionOther(), 'f', 5));
        cconsumption_return
                ->setText(QString::number(value->getConsumptionReturn(), 'f', 5));
        cconsumption_move
                ->setText(QString::number(value->getConsumptionMove(), 'f', 5));
        cbalance_end
                ->setText(QString::number(value->getBalanceEnd(), 'f', 5));

        cbalance_begin
                ->setTextAlignment(Qt::AlignRight | Qt::AlignCenter);
        creceipt_from_producers
                ->setTextAlignment(Qt::AlignRight | Qt::AlignCenter);
        creceipt_from_wholesalers
                ->setTextAlignment(Qt::AlignRight | Qt::AlignCenter);
        creceipt_import
                ->setTextAlignment(Qt::AlignRight | Qt::AlignCenter);
        creceipt_consumption
                ->setTextAlignment(Qt::AlignRight | Qt::AlignCenter);
        creceipt_other
                ->setTextAlignment(Qt::AlignRight | Qt::AlignCenter);
        creceipt_move
                ->setTextAlignment(Qt::AlignRight | Qt::AlignCenter);
        cconsumption_retail
                ->setTextAlignment(Qt::AlignRight | Qt::AlignCenter);
        cconsumption_other
                ->setTextAlignment(Qt::AlignRight | Qt::AlignCenter);
        cconsumption_return
                ->setTextAlignment(Qt::AlignRight | Qt::AlignCenter);
        cconsumption_move
                ->setTextAlignment(Qt::AlignRight | Qt::AlignCenter);
        cbalance_end
                ->setTextAlignment(Qt::AlignRight | Qt::AlignCenter);

        ui->summaryTable->setItem(r, 0, ccode);
        ui->summaryTable->setItem(r, 1, cproducer);
        ui->summaryTable->setItem(r, 2, cbalance_begin);
        ui->summaryTable->setItem(r, 3, creceipt_from_producers);
        ui->summaryTable->setItem(r, 4, creceipt_from_wholesalers);
        ui->summaryTable->setItem(r, 5, creceipt_import);
        ui->summaryTable->setItem(r, 6, creceipt_consumption);
        ui->summaryTable->setItem(r, 7, creceipt_other);
        ui->summaryTable->setItem(r, 8, creceipt_move);
        ui->summaryTable->setItem(r, 9, cconsumption_retail);
        ui->summaryTable->setItem(r, 10, cconsumption_other);
        ui->summaryTable->setItem(r, 11, cconsumption_return);
        ui->summaryTable->setItem(r, 12, cconsumption_move);
        ui->summaryTable->setItem(r, 13, cbalance_end);

        r ++;
    }

    filterSummaryTable();
    ui->summaryTable->setSortingEnabled(true);
}

void MainWindow::fillLicenses()
{
    ui->licensesTable->setSortingEnabled(false);
    ui->licensesTable->clearContents();
    ui->licensesTable->setRowCount(licenses.size());

    QHashIterator<QString,License*> iter(licenses);
    uint r = 0;
    while (iter.hasNext()) {
        iter.next();

        QTableWidgetItem *csupplier = new QTableWidgetItem();
        QTableWidgetItem *cnumber = new QTableWidgetItem();
        QTableWidgetItem *csdate = new QTableWidgetItem();
        QTableWidgetItem *cedate = new QTableWidgetItem();
        QTableWidgetItem *cdepartment = new QTableWidgetItem();

        License* license = iter.value();

        csupplier->setText(license->getContragent()->getName());
        cnumber->setText(license->getNumber());
        csdate->setText(license->getStartDate().toString("dd.MM.yyyy"));
        cedate->setText(license->getEndDate().toString("dd.MM.yyyy"));
        cdepartment->setText(license->getDepartment());

        ui->licensesTable->setItem(r, 0, csupplier);
        ui->licensesTable->setItem(r, 1, cnumber);
        ui->licensesTable->setItem(r, 2, csdate);
        ui->licensesTable->setItem(r, 3, cedate);
        ui->licensesTable->setItem(r, 4, cdepartment);

        r ++;
    }
    ui->licensesTable->setSortingEnabled(true);
}

void MainWindow::on_action_import_triggered()
{
    DialogImport* dialogImport = new DialogImport(this);
    int result = dialogImport->exec();
    if (result == QDialog::Accepted) {
        QVector<InputData> imported = dialogImport->getData();

        inputData << imported;

        ProcessData processor(inputData);

        contragents = processor.getContragents();
        licenses = processor.getLicenses();
        products = processor.getProducts();
        summary = processor.getSummary();
        oborot = processor.getOborot();

        disconnectTableSignals();
        fillSummary();
        fillDetail();
        fillContragents();
        fillLicenses();
        connectTableSignals();
    }

    delete dialogImport;
}

void MainWindow::on_action_clear_triggered()
{
    inputData.clear();

    oborot.clear();
    summary.clear();
    licenses.clear();
    products.clear();
    contragents.clear();

    ui->detailTable->clearContents();
    ui->detailTable->setRowCount(0);

    ui->summaryTable->clearContents();
    ui->summaryTable->setRowCount(0);

    ui->licensesTable->clearContents();
    ui->licensesTable->setRowCount(0);

    ui->contragentsTable->clearContents();
    ui->contragentsTable->setRowCount(0);
}

void MainWindow::on_action_params_triggered()
{
     DialogSettings* dialogSettings = new DialogSettings(this);

     dialogSettings->exec();

    delete dialogSettings;
}

void MainWindow::on_action_export_alko_triggered()
{
    WizardExport* dialogExport = new WizardExport(this);

    dialogExport->setSummary(summary);
    dialogExport->setProducts(products);
    dialogExport->setLicenses(licenses);
    dialogExport->setContragents(contragents);
    dialogExport->setOborot(oborot);

    dialogExport->exec();

    delete dialogExport;
}

void MainWindow::changeContragentTableCellValue(int row, int column)
{
    QTableContragentsWidgetItem *item = (QTableContragentsWidgetItem *) ui->contragentsTable->item(row, column);
    Contragent *contragent = item->getContragent();
    QString value = item->text();

    switch (column) {
    case 1:
        contragent->setName(value);
        disconnectTableSignals();
        fillSummary();
        fillDetail();
        fillLicenses();
        connectTableSignals();
        break;
    case 2:
        contragent->setInn(value);
        break;
    case 3:
        contragent->setKpp(value);
        break;
    case 4:
        contragent->setCountry(value.toUInt());
        break;
    case 5:
        contragent->setArea(value.toUInt());
        break;
    case 6:
        contragent->setProducer(item->checkState() == Qt::Checked);
        break;
    case 7:
        contragent->setCarrier(item->checkState() == Qt::Checked);
        break;
    }
}

double MainWindow::calculateValue(QString value) {
    double result = 0;

    QRegExp re("\\d*(\\.\\d+)?");
    if (! re.exactMatch(value)) {
        Calculator calc;
        try {
            result = calc.execute(value);
        }
        catch(QString s) {

        }

    }
    else {
        result = value.toDouble();
    }

    return result;
}

void MainWindow::changeSummaryTableCellValue(int row, int column)
{
    QTableSummaryWidgetItem *item = (QTableSummaryWidgetItem *) ui->summaryTable->item(row, column);
    QTableSummaryWidgetItem *balance_end = (QTableSummaryWidgetItem *) ui->summaryTable->item(row, 13);

    Summary *summary = item->getSummary();
    QString value = item->text();
    double result = 0;

    disconnectTableSignals();
    switch (column) {
    case 2:
        result = calculateValue(value);
        summary->setBalanceBegin(result);
        item->setText(QString::number(result, 'f', 5));
        balance_end->setText(QString::number(summary->getBalanceEnd(), 'f', 5));
        break;
    case 3:
        result = calculateValue(value);
        summary->setReceiptFromProducers(result);
        item->setText(QString::number(result, 'f', 5));
        balance_end->setText(QString::number(summary->getBalanceEnd(), 'f', 5));
        break;
    case 4:
        result = calculateValue(value);
        summary->setReceiptFromWholesalers(result);
        item->setText(QString::number(result, 'f', 5));
        balance_end->setText(QString::number(summary->getBalanceEnd(), 'f', 5));
        break;
    case 5:
        result = calculateValue(value);
        summary->setReceiptImport(result);
        item->setText(QString::number(result, 'f', 5));
        balance_end->setText(QString::number(summary->getBalanceEnd(), 'f', 5));
        break;
    case 6:
        result = calculateValue(value);
        summary->setReceiptConsumption(result);
        item->setText(QString::number(result, 'f', 5));
        balance_end->setText(QString::number(summary->getBalanceEnd(), 'f', 5));
        break;
    case 7:
        result = calculateValue(value);
        summary->setReceiptOther(result);
        item->setText(QString::number(result, 'f', 5));
        balance_end->setText(QString::number(summary->getBalanceEnd(), 'f', 5));
        break;
    case 8:
        result = calculateValue(value);
        summary->setReceiptMove(result);
        item->setText(QString::number(result, 'f', 5));
        balance_end->setText(QString::number(summary->getBalanceEnd(), 'f', 5));
        break;
    case 9:
        result = calculateValue(value);
        summary->setConsumptionRetail(result);
        item->setText(QString::number(result, 'f', 5));
        balance_end->setText(QString::number(summary->getBalanceEnd(), 'f', 5));
        break;
    case 10:
        result = calculateValue(value);
        summary->setConsumptionOther(result);
        item->setText(QString::number(result, 'f', 5));
        balance_end->setText(QString::number(summary->getBalanceEnd(), 'f', 5));
        break;
    case 11:
        result = calculateValue(value);
        summary->setConsumptionReturn(result);
        item->setText(QString::number(result, 'f', 5));
        balance_end->setText(QString::number(summary->getBalanceEnd(), 'f', 5));
        break;
    case 12:
        result = calculateValue(value);
        summary->setConsumptionMove(result);
        item->setText(QString::number(result, 'f', 5));
        balance_end->setText(QString::number(summary->getBalanceEnd(), 'f', 5));
        break;
    }
    connectTableSignals();
}

void MainWindow::on_action_export_contragents_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Экспорт контрагентов", "", "XML-файлы (*.xml)");

    if (! fileName.isEmpty()) {
        ExportContragents exportContragents;

        exportContragents.process();
    }
}

void MainWindow::on_btnNewContragent_clicked()
{
    DialogNewContragent dialog(this);

    if (dialog.exec() == QDialog::Accepted) {
        Contragent *contragent = dialog.getContragent();
        Contragent::qpair kContragent(contragent->getInn(), contragent->getKpp());
        Contragent::iterator iContragent = contragents.find(kContragent);
        if (iContragent == contragents.end()) {
            uint id = getContragentNextId();
            contragent->setId(id + 1);
            contragents.insert(kContragent, contragent);

            disconnectTableSignals();
            fillContragents();
            connectTableSignals();
        }
    }

    //    delete dialogNewContragent;
}


void MainWindow::on_pushButton_clicked()
{
    DialogNewSummary dialog(this);
    dialog.setContragents(contragents);
    if (dialog.exec() == QDialog::Accepted) {
        try {
            QPair<ushort, Contragent *> pair = dialog.getSummaryPair();
            if (pair.second != NULL && summary.find(pair) == summary.end()) {
                Summary *summaryItem = new Summary(pair.first, pair.second);

                summary.insert(pair, summaryItem);
                oborot.insert(pair.first, pair.second);

                disconnectTableSignals();
                fillSummary();
                connectTableSignals();
            }
        }
        catch (QString s) {

        }
    }
}

void MainWindow::filterSummaryTable() {
    bool ok;
    uint searchCode  = ui->searchCode->text().toUInt(&ok);
    QString searchInn = ui->searchInn->text();
    QString searchKpp = ui->searchKpp->text();
    int rowCount = ui->summaryTable->rowCount();

    for (int i = 0; i < rowCount; i ++) {
        QTableSummaryWidgetItem *item = (QTableSummaryWidgetItem *) ui->summaryTable->item( i, 0 );
        Summary *summaryItem = item->getSummary();
        Contragent *contragent = summaryItem->getContragent();
        bool match = (searchCode > 0 ? searchCode == summaryItem->getCode() : true)
                  && (searchInn.isEmpty() ? true : searchInn == contragent->getInn())
                  && (searchKpp.isEmpty() ? true : searchKpp == contragent->getKpp());
        ui->summaryTable->setRowHidden(i, ! match);
    }
}

void MainWindow::resetFilterSummaryTable() {
    ui->searchCode->setText("");
    ui->searchInn->setText("");
    ui->searchKpp->setText("");

    for (int i = 0; i < ui->summaryTable->rowCount(); i ++) {
        ui->summaryTable->setRowHidden(i, false);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    filterSummaryTable();
}

void MainWindow::on_pushButton_3_clicked()
{
    resetFilterSummaryTable();
}

uint MainWindow::getContragentNextId() {
    QHashIterator<Contragent::qpair,Contragent*> iter(contragents);
    uint id = 0;
    while(iter.hasNext()) {
        iter.next();
        Contragent* row = iter.value();
        if (id < row->getId()) {
            id = row->getId();
        }
    }

    return id;
}

void MainWindow::on_action_triggered()
{
    QList<ushort> types;
    types.append((ushort) CSVReader::COLUMN_HIDE);
    types.append((ushort) CSVReader::COLUMN_PRODUCT_TYPE);
    types.append((ushort) CSVReader::COLUMN_PRODUCER_NAME);
    types.append((ushort) CSVReader::COLUMN_PRODUCER_INN);
    types.append((ushort) CSVReader::COLUMN_PRODUCER_KPP);
    types.append((ushort) CSVReader::COLUMN_NUMBER_DKL);

    DialogImport* dialogImport = new DialogImport(this);
    dialogImport->setAllowedTypes(types);
    int result = dialogImport->exec();
    if (result == QDialog::Accepted) {
        QVector<InputData> imported = dialogImport->getData();

        QVectorIterator<InputData> iter(imported);
        while (iter.hasNext()) {
            Contragent *contragent;
            InputData row = iter.next();
            Contragent::qpair kContragent(row.ProducerInn, row.ProducerKpp);
            Contragent::iterator iContragent = contragents.find(kContragent);
            if (iContragent == contragents.end()) {
                uint id = getContragentNextId();
                contragent = new Contragent(row.ProducerName, row.ProducerInn, row.ProducerKpp);
                contragent->setId(id + 1);
                contragent->setProducer(true);
                contragents.insert(kContragent, contragent);
            }
            else {
                contragent = iContragent.value();
            }

            QPair<ushort, Contragent *> pair(row.ProductType, contragent);
            QHash<QPair<ushort,Contragent*>,Summary*>::iterator iter = summary.find(pair);
            Summary *summaryItem;
            if (iter == summary.end()) {
                summaryItem = new Summary(pair.first, pair.second);

                iter = summary.insert(pair, summaryItem);
                oborot.insert(pair.first, pair.second);
            }
            else {
                summaryItem = iter.value();
            }
            summaryItem->setBalanceBegin(summaryItem->getBalanceBegin() + row.NumberDkl);
        }

        disconnectTableSignals();
        fillSummary();
        fillContragents();
        connectTableSignals();
    }

    delete dialogImport;
}

void MainWindow::on_action_save_triggered()
{
    bool ok = true;
    if (! alkoData.isOpen()) {
        QString filename = QFileDialog::getSaveFileName(this, tr("Сохранить"), "", tr("Alko (*.alko)"));
        if (! filename.isEmpty()) {
            alkoData.close();
            alkoData.setDatabase(filename);
        }
        ok = false;
    }
    if (ok) {
        alkoData.setContragents(contragents);
        alkoData.setLicenses(licenses);
        alkoData.setOborot(oborot);
        alkoData.setProducts(products);
        alkoData.setSummary(summary);

        alkoData.save();
    }
}

void MainWindow::on_action_load_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Открыть"), "", tr("Alko (*.alko)"));
    if (! filename.isEmpty()) {
        alkoData.close();

        alkoData.setDatabase(filename);
        alkoData.load();

        contragents = alkoData.getContragents();
        licenses = alkoData.getLicenses();
        products = alkoData.getProducts();
        oborot = alkoData.getOborot();
        summary = alkoData.getSummary();

        disconnectTableSignals();
        fillSummary();
        fillDetail();
        fillContragents();
        fillLicenses();
        connectTableSignals();
    }
}

void MainWindow::on_action_save_as_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, tr("Сохранить как…"), "", tr("Alko (*.alko)"));
    if (! filename.isEmpty()) {
        alkoData.close();
        alkoData.setDatabase(filename);

        alkoData.setContragents(contragents);
        alkoData.setLicenses(licenses);
        alkoData.setOborot(oborot);
        alkoData.setProducts(products);
        alkoData.setSummary(summary);

        alkoData.save();
    }
}

void MainWindow::on_action_close_triggered()
{
    alkoData.close();
    alkoData.setDatabase("");
}
