#ifndef QTABLESUMMARYWIDGETITEM_H
#define QTABLESUMMARYWIDGETITEM_H

#include <QTableWidgetItem>
#include "summary.h"

class QTableSummaryWidgetItem : public QTableWidgetItem
{
public:
    QTableSummaryWidgetItem();
    QTableSummaryWidgetItem(Summary *value);
    Summary *getSummary() const;
    void setSummary(Summary *value);
    bool operator <(const QTableWidgetItem &other) const;
private:
    Summary *summary;
};

#endif // QTABLESUMMARYWIDGETITEM_H
