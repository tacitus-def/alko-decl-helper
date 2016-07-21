#ifndef DIALOGNEWSUMMARY_H
#define DIALOGNEWSUMMARY_H

#include <QDialog>
#include <QHash>
#include "contragent.h"
#include "summary.h"

namespace Ui {
class DialogNewSummary;
}

class DialogNewSummary : public QDialog
{
    Q_OBJECT

public:
    explicit DialogNewSummary(QWidget *parent = 0);
    ~DialogNewSummary();

    void setContragents(QHash<Contragent::qpair, Contragent*> contragents);
    QPair<ushort, Contragent *> getSummaryPair();
private:
    Ui::DialogNewSummary *ui;
    QHash<uint, Contragent*> list;
};

#endif // DIALOGNEWSUMMARY_H
