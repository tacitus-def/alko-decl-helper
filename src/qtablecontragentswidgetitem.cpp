#include "qtablecontragentswidgetitem.h"

QTableContragentsWidgetItem::QTableContragentsWidgetItem() : QTableWidgetItem ()
{
}

QTableContragentsWidgetItem::QTableContragentsWidgetItem(Contragent *value) : QTableWidgetItem ()
{
    setContragent(value);
}

Contragent *QTableContragentsWidgetItem::getContragent() const
{
    return contragent;
}

void QTableContragentsWidgetItem::setContragent(Contragent *value)
{
    contragent = value;
}

