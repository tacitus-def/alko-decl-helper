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
