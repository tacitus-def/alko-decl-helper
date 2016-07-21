#include "wizardpagedeclproperties.h"
#include "ui_wizardpagedeclproperties.h"

WizardPageDeclProperties::WizardPageDeclProperties(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::WizardPageDeclProperties)
{
    ui->setupUi(this);

    ui->declType->addItem(QIcon(), "Форма №11. Декларация об объемах розничной продажи алкогольной и спиртосодержащей продукции", QVariant(11));
    ui->declType->addItem(QIcon(), "Форма №12. Декларация об объемах продажи пива и пивных напитков", QVariant(12));

    loadSettings();
}

void WizardPageDeclProperties::loadSettings()
{
    Settings *settings = Settings::getInstance();

    ui->licSerial->setText(settings->getLicSerial());
    ui->licNumber->setText(settings->getLicNumber());
    ui->licStart->setDate(settings->getLicStart());
    ui->licEnd->setDate(settings->getLicEnd());
    ui->licType->setCurrentIndex(settings->getLicType());
}

void WizardPageDeclProperties::saveSettings()
{
    Settings *settings = Settings::getInstance();

    settings->setLicSerial(ui->licSerial->text());
    settings->setLicNumber(ui->licNumber->text());
    settings->setLicStart(ui->licStart->date());
    settings->setLicEnd(ui->licEnd->date());
    settings->setLicType(ui->licType->currentIndex());

    settings->saveIniFile();
}

WizardPageDeclProperties::~WizardPageDeclProperties()
{
    delete ui;
}

int WizardPageDeclProperties::getDeclType()
{
    return ui->declType->itemData(ui->declType->currentIndex()).toInt();
}

int WizardPageDeclProperties::getDeclDocType()
{
    return ui->declDocType->currentIndex();
}

QString WizardPageDeclProperties::getDeclCorrNumber()
{
    return ui->declCorrNumber->text();
}

int WizardPageDeclProperties::getDeclQuarter()
{
    return ui->declQuarter->currentIndex() + 1;
}

int WizardPageDeclProperties::getDeclYear()
{
    return ui->declYear->date().year();
}

QString WizardPageDeclProperties::getProvidedFor()
{
    return ui->declProvidedFor->text();
}

int WizardPageDeclProperties::getDeclSign()
{
    return ui->declSign->currentIndex();
}

int WizardPageDeclProperties::getLicType()
{
    return ui->licType->currentIndex();
}

QString WizardPageDeclProperties::getLicSerial()
{
    return ui->licSerial->text();
}

QString WizardPageDeclProperties::getLicNumber()
{
    return ui->licNumber->text();
}

QDate WizardPageDeclProperties::getLicStart()
{
    return ui->licStart->date();
}

QDate WizardPageDeclProperties::getLicEnd()
{
    return ui->licEnd->date();
}

bool WizardPageDeclProperties::validatePage()
{
    bool valid = true;
    bool condition;
    int idx;

    idx = ui->declDocType->currentIndex();
    condition = false;
    if (idx == 0) {
        condition |= ui->declCorrNumber->text().isEmpty();
    }
    else
    if (idx == 1) {
        condition |= ! ui->declCorrNumber->text().isEmpty();
    }
    AlkoHelperInput::highlightError(ui->declCorrNumber, !condition);
    valid &= condition;

    valid &= condition = ui->declProvidedFor->text().length() > 0;
    AlkoHelperInput::highlightError(ui->declProvidedFor, !condition);


    idx = ui->declType->itemData(ui->declType->currentIndex()).toInt();

    if (idx == 11) {
        valid &= condition = ui->licSerial->text().length() > 0;
        AlkoHelperInput::highlightError(ui->licSerial, !condition);

        valid &= condition = ui->licNumber->text().length() > 0;
        AlkoHelperInput::highlightError(ui->licNumber, !condition);
    }
    else if (idx == 12) {
        AlkoHelperInput::highlightError(ui->licSerial, false);
        AlkoHelperInput::highlightError(ui->licNumber, false);
    }

    if (valid) {
        saveSettings();
    }

    return valid;
}
