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

    ui->filePathEdit->setText(Settings::getInstance()->getDbFilePath());
    ui->pswEdit->setText(Settings::getInstance()->getDbPassword());
}

DialogSettings::~DialogSettings()
{
    delete ui;
}

void DialogSettings::on_btnBrowse_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this,"Выбор файла","","*.sdf");
    QFileInfo* fileInfo = new QFileInfo(filePath);
    if (fileInfo->exists()) {
        ui->filePathEdit->setText(filePath);
    }

    delete fileInfo;
}

void DialogSettings::on_buttonBox_accepted()
{
    Settings::getInstance()->setDbFilePath(ui->filePathEdit->text());
    Settings::getInstance()->setDbPassword(ui->pswEdit->text());

    Settings::getInstance()->saveIniFile();
}
