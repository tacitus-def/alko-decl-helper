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

#include "dialogsettings.h"
#include "ui_dialogsettings.h"

DialogSettings::DialogSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSettings)
{
    ui->setupUi(this);

    loadSettings();
}

void DialogSettings::accept()
{
    if (validatePage()) {
        saveSettings();
        QDialog::accept();
    }
}

DialogSettings::~DialogSettings()
{
    delete ui;
}

bool DialogSettings::validatePage()
{
    bool valid = true;
    bool condition;

    valid &= condition = ui->orgName->text().length() > 0;
    AlkoHelperInput::highlightError(ui->orgName, !condition);

    valid &= condition = ui->orgINN->text().length() >= 9 && ui->orgINN->text().length() <= 10;
    AlkoHelperInput::highlightError(ui->orgINN, !condition);

    valid &= condition = ui->orgKPP->text().length() >= 8 && ui->orgKPP->text().length() <= 9;
    AlkoHelperInput::highlightError(ui->orgKPP, !condition);

    valid &= condition = ui->orgTel->text().length() > 0;
    AlkoHelperInput::highlightError(ui->orgTel, !condition);

    valid &= condition = ui->orgEMail->text().length() > 0;
    AlkoHelperInput::highlightError(ui->orgEMail, !condition);

    valid &= condition = ui->headSurname->text().length() > 0;
    AlkoHelperInput::highlightError(ui->headSurname, !condition);

    valid &= condition = ui->headName->text().length() > 0;
    AlkoHelperInput::highlightError(ui->headName, !condition);

    valid &= condition = ui->headMiddleName->text().length() > 0;
    AlkoHelperInput::highlightError(ui->headMiddleName, !condition);
    /*
    valid &= condition = ui->accSurname->text().length() > 0;
    AlkoHelperInput::highlightError(ui->accSurname, !condition);

    valid &= condition = ui->accName->text().length() > 0;
    AlkoHelperInput::highlightError(ui->accName, !condition);

    valid &= condition = ui->accMiddleName->text().length() > 0;
    AlkoHelperInput::highlightError(ui->accMiddleName, !condition);
     */
    valid &= condition = ui->orgCountryCode->text().length() > 0;
    AlkoHelperInput::highlightError(ui->orgCountryCode, !condition);

    valid &= condition = ui->orgRegionCode->text().length() > 0;
    AlkoHelperInput::highlightError(ui->orgRegionCode, !condition);

    valid &= condition = ui->orgCity->text().length() > 0;
    AlkoHelperInput::highlightError(ui->orgCity, !condition);

    return valid;
}

void DialogSettings::loadSettings()
{
    Settings *settings = Settings::getInstance();

    ui->orgName->setText(settings->getOrgName());
    ui->orgINN->setText(settings->getOrgINN());
    ui->orgKPP->setText(settings->getOrgKPP());
    ui->orgTel->setText(settings->getOrgTel());
    ui->orgEMail->setText(settings->getOrgEmail());

    ui->orgCountryCode->setText(QString::number(settings->getAddrCountryCode()));
    ui->orgRegionCode->setText(QString::number(settings->getAddrRegionCode()));
    ui->orgPostalCode->setText(settings->getAddrPostalCode());
    ui->orgCity->setText(settings->getAddrCity());
    ui->orgStreet->setText(settings->getAddrStreet());
    ui->orgBuilding->setText(settings->getAddrBuilding());
    ui->orgBuildingIndex->setText(settings->getAddrBuildingIndex());
    ui->orgApartment->setText(settings->getAddrApartment());

    ui->headSurname->setText(settings->getHeadSurName());
    ui->headName->setText(settings->getHeadName());
    ui->headMiddleName->setText(settings->getHeadMiddleName());

    ui->accSurname->setText(settings->getAccSurName());
    ui->accName->setText(settings->getAccName());
    ui->accMiddleName->setText(settings->getAccMiddleName());

    ui->licSerial->setText(settings->getLicSerial());
    ui->licNumber->setText(settings->getLicNumber());
    ui->licStart->setDate(settings->getLicStart());
    ui->licEnd->setDate(settings->getLicEnd());
    ui->licType->setCurrentIndex(settings->getLicType());
}

void DialogSettings::saveSettings()
{
    Settings *settings = Settings::getInstance();

    settings->setOrgName(ui->orgName->text());
    settings->setOrgINN(ui->orgINN->text());
    settings->setOrgKPP(ui->orgKPP->text());
    settings->setOrgTel(ui->orgTel->text());
    settings->setOrgEmail(ui->orgEMail->text());

    settings->setAddrCountryCode(ui->orgCountryCode->text().toInt());
    settings->setAddrRegionCode(ui->orgRegionCode->text().toInt());
    settings->setAddrPostalCode(ui->orgPostalCode->text());
    settings->setAddrCity(ui->orgCity->text());
    settings->setAddrStreet(ui->orgStreet->text());
    settings->setAddrBuilding(ui->orgBuilding->text());
    settings->setAddrBuildingIndex(ui->orgBuildingIndex->text());
    settings->setAddrApartment(ui->orgApartment->text());

    settings->setHeadSurName(ui->headSurname->text());
    settings->setHeadName(ui->headName->text());
    settings->setHeadMiddleName(ui->headMiddleName->text());

    settings->setAccSurName(ui->accSurname->text());
    settings->setAccName(ui->accName->text());
    settings->setAccMiddleName(ui->accMiddleName->text());

    settings->setLicSerial(ui->licSerial->text());
    settings->setLicNumber(ui->licNumber->text());
    settings->setLicStart(ui->licStart->date());
    settings->setLicEnd(ui->licEnd->date());
    settings->setLicType(ui->licType->currentIndex());

    settings->saveIniFile();
}
