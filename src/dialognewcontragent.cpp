#include "dialognewcontragent.h"
#include "ui_dialognewcontragent.h"

DialogNewContragent::DialogNewContragent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogNewContragent)
{
    ui->setupUi(this);
}

DialogNewContragent::~DialogNewContragent()
{
    delete ui;
}

Contragent *DialogNewContragent::getContragent()
{
    Contragent *contragent = new Contragent(ui->inputName->text(), ui->inputInn->text(), ui->inputKpp->text());

    contragent->setCarrier(ui->inputCarrier->isChecked());
    contragent->setProducer(ui->inputProducer->isChecked());

    return contragent;
}
