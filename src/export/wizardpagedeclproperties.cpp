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
