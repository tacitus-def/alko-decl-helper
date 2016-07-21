#include "exportcontragents.h"

ExportContragents::ExportContragents() {
}

ExportContragents::ExportContragents(const QHash<Contragent::qpair, Contragent *> &value)
{
    setContragents(value);
}

void ExportContragents::setContragents(const QHash<Contragent::qpair, Contragent *> &value)
{
    contragents = value;
}

QDomDocument ExportContragents::process() {
    QDomDocument doc;
    QDomNode xmlNode = doc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"windows-1251\"");
    doc.insertBefore(xmlNode, doc.firstChild());

    /* /Справочники */
    QDomElement el_root = doc.createElement("Справочники");
    doc.appendChild(el_root);

    QDomElement el_contragents = doc.createElement("Контрагенты");
    el_root.appendChild(el_contragents);

    QHashIterator<QPair<QString,QString>,Contragent*> iter(contragents);
    while(iter.hasNext()) {
        iter.next();
        Contragent* row = iter.value();
        bool fromRussia = (row->getCountry() == 643);
        QDomElement el_contragent = doc.createElement(fromRussia ? "Резидент" : "Иностр");
        el_contragents.appendChild(el_contragent);

        QDomAttr attrContragentId = doc.createAttribute("ИдКонтр");
        attrContragentId.setValue(QString::number(row->getId()));
        el_contragent.setAttributeNode(attrContragentId);

        QDomAttr attrContragentName = doc.createAttribute("П000000000007");
        attrContragentName.setValue(row->getName());
        el_contragent.setAttributeNode(attrContragentName);

        if (fromRussia) {
        }
        else {
            QDomAttr attrCountryCode = doc.createAttribute("П000000000081");
            el_contragent.setAttributeNode(attrCountryCode);

            QDomAttr attrAddress = doc.createAttribute("П000000000082");
            el_contragent.setAttributeNode(attrAddress);
        }
    }

    return doc;
}
