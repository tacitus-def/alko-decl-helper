#include "dialogimport.h"
#include "ui_dialogimport.h"

DialogImport::DialogImport(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogImport)
{
    ui->setupUi(this);

    connect(ui->sepTab, SIGNAL(clicked()), this, SLOT(changeSeparator()));
    connect(ui->sepComma, SIGNAL(clicked()), this, SLOT(changeSeparator()));
    connect(ui->sepSemicolon, SIGNAL(clicked()), this, SLOT(changeSeparator()));
    connect(ui->tblFields, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(tblCtxMenu(const QPoint &)));
    connect(ui->tblFields->horizontalHeader(), SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(tblCtxMenu(const QPoint &)));

    initDefaults();
    resetAllowedTypes();
    initForm();
}

DialogImport::~DialogImport()
{
    delete ui;
}

void DialogImport::initDefaults() {
    // CSVReader::COLUMN_HIDE
    typeLabels [CSVReader::COLUMN_HIDE] = "Скрыть";
    // CSVReader::COLUMN_PRODUCT_TYPE
    typeLabels [CSVReader::COLUMN_PRODUCT_TYPE] = "Код продукции";
    // CSVReader::COLUMN_SUPPLIER_NAME
    typeLabels [CSVReader::COLUMN_SUPPLIER_NAME] = "Наименование поставщика/импортёра";
    // CSVReader::COLUMN_SUPPLIER_INN
    typeLabels [CSVReader::COLUMN_SUPPLIER_INN] = "ИНН поставщика/импортёра";
    // CSVReader::COLUMN_SUPPLIER_KPP
    typeLabels [CSVReader::COLUMN_SUPPLIER_KPP] = "КПП поставщика/импортёра";
    // CSVReader::COLUMN_PRODUCER_NAME
    typeLabels [CSVReader::COLUMN_PRODUCER_NAME] = "Наименование производителя";
    // CSVReader::COLUMN_PRODUCER_INN
    typeLabels [CSVReader::COLUMN_PRODUCER_INN] = "ИНН производителя";
    // CSVReader::COLUMN_PRODUCER_KPP
    typeLabels [CSVReader::COLUMN_PRODUCER_KPP] = "КПП производителя";
    // CSVReader::COLUMN_LICENSE_NUMBER
    typeLabels [CSVReader::COLUMN_LICENSE_NUMBER] = "Номер лицензии";
    // CSVReader::COLUMN_LICENSE_SDATE
    typeLabels [CSVReader::COLUMN_LICENSE_SDATE] = "Дата выдачи лицензии";
    // CSVReader::COLUMN_LICENSE_EDATE
    typeLabels [CSVReader::COLUMN_LICENSE_EDATE] = "Дата окончания лицензии";
    // CSVReader::COLUMN_LICENSE_DEPARTMENT
    typeLabels [CSVReader::COLUMN_LICENSE_DEPARTMENT] = "Лицензиар";
    // CSVReader::COLUMN_TTN_NUMBER
    typeLabels [CSVReader::COLUMN_TTN_NUMBER] = "Номер ТТН";
    // CSVReader::COLUMN_TTN_DATE
    typeLabels [CSVReader::COLUMN_TTN_DATE] = "Дата ТТН";
    // CSVReader::COLUMN_TD_NUMBER
    typeLabels [CSVReader::COLUMN_TD_NUMBER] = "Номер ТД";
    // CSVReader::COLUMN_NUMBER_DKL
    typeLabels [CSVReader::COLUMN_NUMBER_DKL] = "ДКЛ";

    separators = CSVReader::SEPARATOR_COMMA;
    lineStart  = 1;

    table.clear();
}

void DialogImport::resetAllowedTypes() {
    allowedTypes.clear();
    allowedTypes.append((ushort) CSVReader::COLUMN_HIDE);
    allowedTypes.append((ushort) CSVReader::COLUMN_PRODUCT_TYPE);
    allowedTypes.append((ushort) CSVReader::COLUMN_PRODUCER_NAME);
    allowedTypes.append((ushort) CSVReader::COLUMN_PRODUCER_INN);
    allowedTypes.append((ushort) CSVReader::COLUMN_PRODUCER_KPP);
    allowedTypes.append((ushort) CSVReader::COLUMN_SUPPLIER_NAME);
    allowedTypes.append((ushort) CSVReader::COLUMN_SUPPLIER_INN);
    allowedTypes.append((ushort) CSVReader::COLUMN_SUPPLIER_KPP);
    allowedTypes.append((ushort) CSVReader::COLUMN_LICENSE_NUMBER);
    allowedTypes.append((ushort) CSVReader::COLUMN_LICENSE_SDATE);
    allowedTypes.append((ushort) CSVReader::COLUMN_LICENSE_EDATE);
    allowedTypes.append((ushort) CSVReader::COLUMN_LICENSE_DEPARTMENT);
    allowedTypes.append((ushort) CSVReader::COLUMN_TTN_DATE);
    allowedTypes.append((ushort) CSVReader::COLUMN_TTN_NUMBER);
    allowedTypes.append((ushort) CSVReader::COLUMN_TD_NUMBER);
    allowedTypes.append((ushort) CSVReader::COLUMN_NUMBER_DKL);
}

void DialogImport::setAllowedTypes(QList<ushort> types) {
    allowedTypes = types;
}

void DialogImport::checkboxStates() {
    if (ui->sepTab->checkState())
        separators = separators | CSVReader::SEPARATOR_TABULATION;
    else
        separators = separators & (CSVReader::SEPARATOR_ALL ^ CSVReader::SEPARATOR_TABULATION);
    if (ui->sepSemicolon->checkState())
        separators = separators | CSVReader::SEPARATOR_SEMICOLON;
    else
        separators = separators & (CSVReader::SEPARATOR_ALL ^ CSVReader::SEPARATOR_SEMICOLON);
    if (ui->sepComma->checkState())
        separators = separators | CSVReader::SEPARATOR_COMMA;
    else
        separators = separators & (CSVReader::SEPARATOR_ALL ^ CSVReader::SEPARATOR_COMMA);
}

void DialogImport::initForm() {
    ui->lineStart->setValue(lineStart);
    ui->sepTab->setChecked(separators & CSVReader::SEPARATOR_TABULATION);
    ui->sepComma->setChecked(separators & CSVReader::SEPARATOR_COMMA);
    ui->sepSemicolon->setChecked(separators & CSVReader::SEPARATOR_SEMICOLON);
}

void DialogImport::on_btnBrowse_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this,"Выбор файла","","*.csv *.txt");
    QFileInfo* fileInfo = new QFileInfo(filePath);
    if (fileInfo->exists()) {
        this->filePath = fileInfo->absoluteFilePath();
        ui->labelFileName->setText(fileInfo->fileName());
        csvReader.load(this->filePath, 0, 10);

        csvReader.setDelimiters(separators);
        csvReader.parse();

        table = csvReader.getData();

        columnTypes = csvReader.getFields();
        if (columnTypes.length() == 0) {
            resizeTable();
        }
        fillTable();
    }

    delete fileInfo;
}

void DialogImport::changeSeparator()
{
    checkboxStates();
    csvReader.setDelimiters(separators);
    csvReader.parse();
    table = csvReader.getData();

    columnTypes = csvReader.getFields();
    if (columnTypes.length() == 0) {
        resizeTable();
    }
    fillTable();
}

void DialogImport::resizeTable() {
    if (table.size()) {
        columnTypes.clear();
        for (int i = 0; i < table.at(0).size(); i++) {
            columnTypes.append((ushort) CSVReader::COLUMN_HIDE);
        }
    }
}

void DialogImport::horizontalHeader() {
    QStringList headers;
    headers.clear();
    for (int i = 0; i < columnTypes.size(); i++) {
        headers.append(typeLabels[columnTypes.at(i)]);
    }
    ui->tblFields->setColumnCount(headers.size());
    ui->tblFields->setRowCount(table.size());
    ui->tblFields->setHorizontalHeaderLabels(headers);
    for (int i = 0; i < headers.size(); i++) {
        ui->tblFields->horizontalHeaderItem(i)->setTextAlignment(Qt::AlignLeft);
    }
    ui->tblFields->horizontalHeader()->setContextMenuPolicy(Qt::CustomContextMenu);
}

void DialogImport::fillTable() {
    ui->tblFields->clear();
    if (table.size() > 0) {
        horizontalHeader();
        for (int r = 0; r < table.size(); r++) {

            QStringList row = table.at(r);
            for (int c = 0; c < row.size(); c ++) {
                QTableWidgetItem *column = new QTableWidgetItem();
                column->setText(row.at(c));
                if (r < lineStart-1)
                    column->setData(Qt::BackgroundRole, QVariant(QBrush(Qt::gray)));

                ui->tblFields->setItem(r, c, column);
            }
        }
    }
}

void DialogImport::on_lineStart_valueChanged(int arg1)
{
    lineStart = arg1;
    fillTable();
}

QVector<InputData> DialogImport::parseLines(QVector<QStringList> table) {
    QVector<InputData> data;
    data.clear();
    for (int r=0; r < table.size(); r++) {
        InputData inputData;

        QStringList row = table.at(r);
        for (int c=0; c < row.size(); c++) {
            QString value = row.at(c).trimmed();
            switch (columnTypes.at(c)) {
            case CSVReader::COLUMN_SUPPLIER_NAME:
                inputData.SupplierName = value;
                break;
            case CSVReader::COLUMN_SUPPLIER_INN:
                inputData.SupplierInn = value;
                break;
            case CSVReader::COLUMN_SUPPLIER_KPP:
                inputData.SupplierKpp = value;
                break;
            case CSVReader::COLUMN_PRODUCER_NAME:
                inputData.ProducerName = value;
                break;
            case CSVReader::COLUMN_PRODUCER_INN:
                inputData.ProducerInn = value;
                break;
            case CSVReader::COLUMN_PRODUCER_KPP:
                inputData.ProducerKpp = value;
                break;
            case CSVReader::COLUMN_LICENSE_NUMBER:
                inputData.LicenseNumber = value;
                break;
            case CSVReader::COLUMN_LICENSE_SDATE:
                inputData.LicenseSdate = parseDate(value);
                break;
            case CSVReader::COLUMN_LICENSE_EDATE:
                inputData.LicenseEdate = parseDate(value);
                break;
            case CSVReader::COLUMN_LICENSE_DEPARTMENT:
                inputData.LicenseDepartment = value;
                break;
            case CSVReader::COLUMN_PRODUCT_TYPE:
                inputData.ProductType = value.toUShort();
                break;
            case CSVReader::COLUMN_TTN_NUMBER:
                inputData.TtnNumber = value;
                break;
            case CSVReader::COLUMN_TTN_DATE:
                inputData.TtnDate = parseDate(value);
                break;
            case CSVReader::COLUMN_TD_NUMBER:
                inputData.TdNumber = value;
                break;
            case CSVReader::COLUMN_NUMBER_DKL:
                inputData.NumberDkl = value.replace(',', '.').toDouble();
                break;
            }
        }

        data.append(inputData);
    }

    return data;
}

void DialogImport::tblCtxMenu(const QPoint &pos)
{
    QMenu *menu = new QMenu(this);

    QListIterator<ushort> iter(allowedTypes);
    while (iter.hasNext()) {
        ushort type = iter.next();
        switch (type) {
        case CSVReader::COLUMN_HIDE:
            menu->addAction(typeLabels[CSVReader::COLUMN_HIDE], this, SLOT(cctHide()));
            break;
        case CSVReader::COLUMN_PRODUCT_TYPE:
            menu->addAction(typeLabels[CSVReader::COLUMN_PRODUCT_TYPE], this, SLOT(cctProductType()));
            break;
        case CSVReader::COLUMN_PRODUCER_NAME:
            menu->addAction(typeLabels[CSVReader::COLUMN_PRODUCER_NAME], this, SLOT(cctProducerName()));
            break;
        case CSVReader::COLUMN_PRODUCER_INN:
            menu->addAction(typeLabels[CSVReader::COLUMN_PRODUCER_INN], this, SLOT(cctProducerInn()));
            break;
        case CSVReader::COLUMN_PRODUCER_KPP:
            menu->addAction(typeLabels[CSVReader::COLUMN_PRODUCER_KPP], this, SLOT(cctProducerKpp()));
            break;
        case CSVReader::COLUMN_SUPPLIER_NAME:
            menu->addAction(typeLabels[CSVReader::COLUMN_SUPPLIER_NAME], this, SLOT(cctSupplierName()));
            break;
        case CSVReader::COLUMN_SUPPLIER_INN:
            menu->addAction(typeLabels[CSVReader::COLUMN_SUPPLIER_INN], this, SLOT(cctSupplierInn()));
            break;
        case CSVReader::COLUMN_SUPPLIER_KPP:
            menu->addAction(typeLabels[CSVReader::COLUMN_SUPPLIER_KPP], this, SLOT(cctSupplierKpp()));
            break;
        case CSVReader::COLUMN_LICENSE_NUMBER:
            menu->addAction(typeLabels[CSVReader::COLUMN_LICENSE_NUMBER], this, SLOT(cctLicenseNumber()));
            break;
        case CSVReader::COLUMN_LICENSE_SDATE:
            menu->addAction(typeLabels[CSVReader::COLUMN_LICENSE_SDATE], this, SLOT(cctLicenseSDate()));
            break;
        case CSVReader::COLUMN_LICENSE_EDATE:
            menu->addAction(typeLabels[CSVReader::COLUMN_LICENSE_EDATE], this, SLOT(cctLicenseEDate()));
            break;
        case CSVReader::COLUMN_LICENSE_DEPARTMENT:
            menu->addAction(typeLabels[CSVReader::COLUMN_LICENSE_DEPARTMENT], this, SLOT(cctLicenseDepartment()));
            break;
        case CSVReader::COLUMN_TTN_DATE:
            menu->addAction(typeLabels[CSVReader::COLUMN_TTN_DATE], this, SLOT(cctTtnDate()));
            break;
        case CSVReader::COLUMN_TTN_NUMBER:
            menu->addAction(typeLabels[CSVReader::COLUMN_TTN_NUMBER], this, SLOT(cctTtnNumber()));
            break;
        case CSVReader::COLUMN_TD_NUMBER:
            menu->addAction(typeLabels[CSVReader::COLUMN_TD_NUMBER], this, SLOT(cctTdNumber()));
            break;
        case CSVReader::COLUMN_NUMBER_DKL:
            menu->addAction(typeLabels[CSVReader::COLUMN_NUMBER_DKL], this, SLOT(cctNumberDkl()));
            break;
        }
    }

    menu->exec(ui->tblFields->mapToGlobal(pos));
}

void DialogImport::changeColumnType(int column, int type) {
    columnTypes.replace(column, type);
    ui->tblFields->horizontalHeaderItem(column)->setText(typeLabels[type]);
}

QDate DialogImport::parseDate(QString value)
{
    QDate date;
    if (value.length() == 10) {
        date = QDate::fromString(value, "dd.MM.yyyy");
    }

    if (value.length() == 8) {
        date = QDate::fromString(value, "dd.MM.yy").addYears(100);
    }

    return date;
}

QVector<InputData> DialogImport::getData()
{
    csvReader.load(this->filePath, lineStart-1, -1);
    csvReader.setDelimiters(separators);
    csvReader.parse();

    return parseLines(csvReader.getData());
}

void DialogImport::cctHide() {
    int column = ui->tblFields->currentColumn();
    changeColumnType(column, CSVReader::COLUMN_HIDE);
}
void DialogImport::cctSupplierName() {
    int column = ui->tblFields->currentColumn();
    changeColumnType(column, CSVReader::COLUMN_SUPPLIER_NAME);
}
void DialogImport::cctSupplierInn() {
    int column = ui->tblFields->currentColumn();
    changeColumnType(column, CSVReader::COLUMN_SUPPLIER_INN);
}
void DialogImport::cctSupplierKpp() {
    int column = ui->tblFields->currentColumn();
    changeColumnType(column, CSVReader::COLUMN_SUPPLIER_KPP);
}
void DialogImport::cctProducerName() {
    int column = ui->tblFields->currentColumn();
    changeColumnType(column, CSVReader::COLUMN_PRODUCER_NAME);
}
void DialogImport::cctProducerInn() {
    int column = ui->tblFields->currentColumn();
    changeColumnType(column, CSVReader::COLUMN_PRODUCER_INN);
}
void DialogImport::cctProducerKpp() {
    int column = ui->tblFields->currentColumn();
    changeColumnType(column, CSVReader::COLUMN_PRODUCER_KPP);
}
void DialogImport::cctLicenseNumber() {
    int column = ui->tblFields->currentColumn();
    changeColumnType(column, CSVReader::COLUMN_LICENSE_NUMBER);
}
void DialogImport::cctLicenseSDate() {
    int column = ui->tblFields->currentColumn();
    changeColumnType(column, CSVReader::COLUMN_LICENSE_SDATE);
}
void DialogImport::cctLicenseEDate() {
    int column = ui->tblFields->currentColumn();
    changeColumnType(column, CSVReader::COLUMN_LICENSE_EDATE);
}

void DialogImport::cctLicenseDepartment()
{
    int column = ui->tblFields->currentColumn();
    changeColumnType(column, CSVReader::COLUMN_LICENSE_DEPARTMENT);
}
void DialogImport::cctProductType() {
    int column = ui->tblFields->currentColumn();
    changeColumnType(column, CSVReader::COLUMN_PRODUCT_TYPE);
}
void DialogImport::cctTtnNumber() {
    int column = ui->tblFields->currentColumn();
    changeColumnType(column, CSVReader::COLUMN_TTN_NUMBER);
}
void DialogImport::cctTtnDate() {
    int column = ui->tblFields->currentColumn();
    changeColumnType(column, CSVReader::COLUMN_TTN_DATE);
}
void DialogImport::cctTdNumber() {
    int column = ui->tblFields->currentColumn();
    changeColumnType(column, CSVReader::COLUMN_TD_NUMBER);
}
void DialogImport::cctNumberDkl() {
    int column = ui->tblFields->currentColumn();
    changeColumnType(column, CSVReader::COLUMN_NUMBER_DKL);
}

