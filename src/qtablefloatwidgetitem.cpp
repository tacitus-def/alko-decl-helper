#include "qtablefloatwidgetitem.h"

QTableFloatWidgetItem::QTableFloatWidgetItem() : QTableWidgetItem()
{
    format = 'f';
    precision = 5;
}

void QTableFloatWidgetItem::setFormat(char format, int precision)
{
    this->format = format;
    this->precision = precision;
}

QString QTableFloatWidgetItem::text() const
{
    return QString::number (data(Qt::DisplayRole).toDouble(), format, precision);
}
