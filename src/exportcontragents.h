#ifndef EXPORTCONTRAGENTS_H
#define EXPORTCONTRAGENTS_H

#include <QDomDocument>
#include <QDomNode>
#include <QHash>
#include "contragent.h"

class ExportContragents
{
public:
    ExportContragents();
    ExportContragents(const QHash<Contragent::qpair, Contragent *> &value);
    void setContragents(const QHash<Contragent::qpair, Contragent *> &value);
    QDomDocument process();

private:
    QHash<Contragent::qpair, Contragent*> contragents;
};

#endif // EXPORTCONTRAGENTS_H
