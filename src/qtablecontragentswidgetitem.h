#ifndef QTABLECONTRAGENTSWIDGETITEM_H
#define QTABLECONTRAGENTSWIDGETITEM_H

#include <QTableWidgetItem>
#include "contragent.h"

class QTableContragentsWidgetItem : public QTableWidgetItem
{
public:
    QTableContragentsWidgetItem();
    QTableContragentsWidgetItem(Contragent *value);
    Contragent *getContragent() const;
    void setContragent(Contragent *value);

private:
    Contragent *contragent;
};

#endif // QTABLECONTRAGENTSWIDGETITEM_H
