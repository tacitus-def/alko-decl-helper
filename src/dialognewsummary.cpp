#include "dialognewsummary.h"
#include "ui_dialognewsummary.h"

DialogNewSummary::DialogNewSummary(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogNewSummary)
{
    ui->setupUi(this);
}

DialogNewSummary::~DialogNewSummary()
{
    delete ui;
}

void DialogNewSummary::setContragents(QHash<Contragent::qpair, Contragent *> contragents)
{
    list.clear();
    ui->inputProducer->clear();
    QHashIterator<Contragent::qpair, Contragent*> iter(contragents);
    while(iter.hasNext()) {
        iter.next();
        Contragent* row = iter.value();
        if (row->getProducer()) {
            list.insert(row->getId(), row);
            ui->inputProducer->addItem(QString("%1 — (ИНН %2/КПП %3)")
                                           .arg(row->getName())
                                           .arg(row->getInn())
                                           .arg(row->getKpp()),
                                       row->getId());
        }
    }
}

QPair<ushort, Contragent *> DialogNewSummary::getSummaryPair()
{
    uint code = ui->inputCode->text().toUInt();
    uint producer = ui->inputProducer->currentData().toUInt();

    QPair<ushort,Contragent*> pair;

    if (! list.isEmpty() && list.find(producer) != list.end()) {
        pair = QPair<ushort,Contragent*>(code, list.find(producer).value());
    }
    else {
        pair = QPair<ushort,Contragent*>(code, NULL);
    }
    return pair;
}
