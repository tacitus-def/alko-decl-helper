#include "qtablesummarywidgetitem.h"

QTableSummaryWidgetItem::QTableSummaryWidgetItem() : QTableWidgetItem ()
{
}

QTableSummaryWidgetItem::QTableSummaryWidgetItem(Summary *value) : QTableWidgetItem ()
{
    setSummary(value);
}

Summary *QTableSummaryWidgetItem::getSummary() const
{
    return summary;
}

void QTableSummaryWidgetItem::setSummary(Summary *value)
{
    summary = value;
}

bool QTableSummaryWidgetItem::operator <(const QTableWidgetItem &other) const
{
    return text().toDouble() < other.text().toDouble();
}
