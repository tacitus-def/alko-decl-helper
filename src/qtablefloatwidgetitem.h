#ifndef QTABLEFLOATWIDGETITEM_H
#define QTABLEFLOATWIDGETITEM_H

#include <QTableWidgetItem>

class QTableFloatWidgetItem : public QTableWidgetItem
{
public:
    QTableFloatWidgetItem();
    void setFormat(char format = 'f', int precision = 5);
    QString text() const;

private:
    char format;
    int  precision;

};

#endif // QTABLEFLOATWIDGETITEM_H
