//
//  Copyright (c) 2016 Petr Sleptsov <spetr@bk.ru>
//
//  This file is part of Alko-decl-helper.
//
//  Alko-decl-helper is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  Alko-decl-helper is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with Alko-decl-helper.  If not, see <http://www.gnu.org/licenses/>.
//

#include "wizardexport.h"
#include "ui_wizardexport.h"
#include "qdebug.h"

WizardExport::WizardExport(QWidget *parent) :
    QWizard(parent),
    ui(new Ui::WizardExport)
{
    ui->setupUi(this);

    connect(this, SIGNAL(finished(int)), this, SLOT(wizardFinish(int)));

    init();
    addPages();
}

WizardExport::~WizardExport()
{
    delete ui;
//    delete pageOrg;
    delete pageDecl;
}

QHash<QPair<ushort, Contragent *>, Summary*> WizardExport::getSummary() const
{
    return summary;
}

void WizardExport::setSummary(const QHash<QPair<ushort, Contragent *>, Summary*> &value)
{
    summary = value;
}

QHash<Contragent::qpair, Contragent *> WizardExport::getContragents() const
{
    return contragents;
}

void WizardExport::setContragents(const QHash<Contragent::qpair, Contragent *> value)
{
    contragents = value;
}

QHash<QString, License *> WizardExport::getLicenses() const
{
    return licenses;
}
Oborot WizardExport::getOborot() const
{
    return oborot;
}

void WizardExport::setOborot(Oborot &value)
{
    oborot = value;
}


void WizardExport::setLicenses(const QHash<QString, License *> &value)
{
    licenses = value;
}

QVector<Product*> WizardExport::getProducts()
{
    return products;
}

void WizardExport::setProducts(const QVector<Product *> &value)
{
    products = value;
}

void WizardExport::init()
{
    settings = Settings::getInstance();
}

void WizardExport::addPages()
{
//    pageOrg  = new WizardPageOrganization();
    pageDecl = new WizardPageDeclProperties();

//    setPage(Page_Organization, pageOrg);
    setPage(Page_Declaration, pageDecl);
}

QDomDocument WizardExport::createXml() {
    QDate currentDate = QDate::currentDate();

    QDomDocument doc;
    QDomNode xmlNode = doc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"windows-1251\"");
    doc.insertBefore(xmlNode, doc.firstChild());

    /* /Файл */
    QDomElement root = doc.createElement("Файл");
    doc.appendChild(root);

    /* ДатаДок="10.10.2013" ВерсФорм="4.30" НаимПрог="Декларант Алко версия 4.30.03" */
    QDomAttr rootAttrDate = doc.createAttribute("ДатаДок");
    rootAttrDate.setValue(currentDate.toString("dd.MM.yyyy"));
    root.setAttributeNode(rootAttrDate);

    QDomAttr rootAttrVersion = doc.createAttribute("ВерсФорм");
    rootAttrVersion.setValue("4.31");
    root.setAttributeNode(rootAttrVersion);

    QDomAttr rootAttrName = doc.createAttribute("НаимПрог");
    rootAttrName.setValue("Декларант Алко версия 4.31.04");
    root.setAttributeNode(rootAttrName);

    /* /Файл/ФормаОтч */
    QDomElement otchForm = doc.createElement("ФормаОтч");
    root.appendChild(otchForm);
    /* <ФормаОтч НомФорм="12" ПризПериодОтч="3" ГодПериодОтч="2013"> */
    int declType = pageDecl->getDeclType();

    {
        QDomAttr attrOFNumber = doc.createAttribute("НомФорм");

        attrOFNumber.setValue(QString::number(declType));

        //    switch (declType) {
        //    case 11:
        //        attrOFNumber.setValue("11");
        //        break;
        //    case 12:
        //        attrOFNumber.setValue("12");
        //        break;
        //    }
        otchForm.setAttributeNode(attrOFNumber);

        QDomAttr attrOFYear = doc.createAttribute("ГодПериодОтч");
        attrOFYear.setValue(QString::number(pageDecl->getDeclYear()));
        otchForm.setAttributeNode(attrOFYear);

        QDomAttr attrOFQuarter = doc.createAttribute("ПризПериодОтч");
        attrOFQuarter.setValue(QString::number(pageDecl->getDeclQuarter()*3%12));
        otchForm.setAttributeNode(attrOFQuarter);

        if (pageDecl->getDeclDocType() == 0)
        {
            /* /Файл/ФормаОтч/Первичная */
            QDomElement docType = doc.createElement("Первичная");
            otchForm.appendChild(docType);
        }
        else {
            /* /Файл/ФормаОтч/Корректирующая */
            QDomAttr domAttr = doc.createAttribute("НомерКорр");
            domAttr.setValue(pageDecl->getDeclCorrNumber());

            QDomElement docType = doc.createElement("Корректирующая");
            docType.setAttributeNode(domAttr);

            otchForm.appendChild(docType);
        }
    }
    /* /Файл/Справочники */
    QDomElement directory = doc.createElement("Справочники");
    root.appendChild(directory);

    setDirectory(doc, directory);

    /* /Файл/Документ */
    QDomElement document = doc.createElement("Документ");
    root.appendChild(document);
    /* /Файл/Документ/Организация */
    QDomElement org = doc.createElement("Организация");
    document.appendChild(org);
    /* /Файл/Документ/Организация/Реквизиты */
    /* <Реквизиты НаимЮЛ="Северпеноплекс" ИННЮЛ="1435151800" КППЮЛ="143501001" ТелОрг="8 (924) 661-32-11" EmailОтпр="spetr@bk.ru"> */
    QDomElement rekv = doc.createElement("Реквизиты");
    org.appendChild(rekv);
    {
        QDomAttr attrULName;
//        if (declType != 12) {
            attrULName = doc.createAttribute("Наим");
//        }
//        else {
//            attrULName = doc.createAttribute("НаимОрг");
//        }
        attrULName.setValue(settings->getOrgName());
        rekv.setAttributeNode(attrULName);

        QDomAttr attrULTel = doc.createAttribute("ТелОрг");
        attrULTel.setValue(settings->getOrgTel());
        rekv.setAttributeNode(attrULTel);

        QDomAttr attrULEmail = doc.createAttribute("EmailОтпр");
        attrULEmail.setValue(settings->getOrgEmail());
        rekv.setAttributeNode(attrULEmail);
        /* /Файл/Документ/Организация/Реквизиты/АдрОрг */
        QDomElement addrOrg = doc.createElement("АдрОрг");
        rekv.appendChild(addrOrg);

        setAddrOrg(doc, addrOrg);

        QDomAttr attrULInn = doc.createAttribute("ИННЮЛ");
        attrULInn.setValue(settings->getOrgINN());
        QDomAttr attrULKpp = doc.createAttribute("КППЮЛ");
        attrULKpp.setValue(settings->getOrgKPP());
//        if (declType == 12) {
            QDomElement ul = doc.createElement("ЮЛ");
            rekv.appendChild(ul);

            ul.setAttributeNode(attrULInn);
            ul.setAttributeNode(attrULKpp);
//        }
//        else {
//            rekv.setAttributeNode(attrULInn);
//            rekv.setAttributeNode(attrULKpp);
//        }

    }
    /* /Файл/Документ/Организация/ОтветЛицо */
    QDomElement orgOtvLitso = doc.createElement("ОтветЛицо");
    org.appendChild(orgOtvLitso);

    setOrgOtvLitso(doc, orgOtvLitso);

    if (declType != 12) {
        /* /Файл/Документ/Организация/Деятельность */
        QDomElement orgDeyatelnost = doc.createElement("Деятельность");
        org.appendChild(orgDeyatelnost);

        setOrgDeyatelnost(doc, orgDeyatelnost);
    }

    /* /Файл/Документ/ОбъемОборота */
    QDomElement orgObiemOborota = doc.createElement("ОбъемОборота");
    document.appendChild(orgObiemOborota);
    /*  */
    {
        QDomAttr attrULName = doc.createAttribute("Наим");
        attrULName.setValue(settings->getOrgName());
        orgObiemOborota.setAttributeNode(attrULName);

        QDomAttr attrULKpp = doc.createAttribute("КППЮЛ");
        attrULKpp.setValue(settings->getOrgKPP());
        orgObiemOborota.setAttributeNode(attrULKpp);

        QDomAttr attrNalichOborota = doc.createAttribute("НаличиеОборота");
        attrNalichOborota.setValue(oborot.getItems().count() > 0 ? "true" : "false");
        orgObiemOborota.setAttributeNode(attrNalichOborota);

        /* /Файл/Документ/ОбъемОборота/АдрОрг */
        QDomElement addrOrg = doc.createElement("АдрОрг");
        orgObiemOborota.appendChild(addrOrg);

        setAddrOrg(doc, addrOrg);

        createOborot(doc, orgObiemOborota);
    }

    return doc;
}

void WizardExport::saveToFile(QDomDocument doc, QString dir) {
    QString fileName = QString("%1_%2_0%3%4_%5_%6.XML")
                        .arg(pageDecl->getDeclType() == 11 ? "R1" : "R2")
                        .arg(settings->getOrgINN())
                        .arg(QString::number(pageDecl->getDeclQuarter() * 3 % 12))
                        .arg(QString::number(pageDecl->getDeclYear()).mid(3))
                        .arg(QDate::currentDate().toString("ddMMyyyy"))
                        .arg(QUuid::createUuid().toString().toUpper().mid(1,36));
    QFile outFile( dir + "/" + fileName );
    if( outFile.open( QIODevice::WriteOnly | QIODevice::Text ) )
    {
        QTextStream stream( &outFile );
        stream.setCodec("windows-1251");
        stream << doc.toString();

        outFile.close();

        QMessageBox::information(0, "Экспорт декларации", "Экспорт декларации успешно завершен");
    }
}

bool WizardExport::checkDates()
{
    QVectorIterator<Product*> iter(products);
    QDate sdate, edate;
    int quarter = pageDecl->getDeclQuarter();
    int year = pageDecl->getDeclYear();
    sdate.setDate(year, quarter * 3 - 2, 1);
    edate.setDate(year, quarter * 3 + 1, 1);
    edate = edate.addDays(-1);
    while (iter.hasNext()) {
        Product* product = iter.next();
        QDate pdate = product->getDate();
        if ( pdate < sdate || pdate > edate) {
            return false;
        }
    }

    return true;
}

void WizardExport::wizardFinish(int result)
{
    if (! result) {
        return;
    }

    if (! checkDates()) {
        QMessageBox::warning(0, "Экспорт декларации", "Экспорт декларации отменен. Обнаружены ТТН с датой, не соответствующей отчетному периоду.");
        return;
    }

    QString dir = QFileDialog::getExistingDirectory(0, "Выбор директории для сохранения", "", QFileDialog::ShowDirsOnly);
    if (! dir.isEmpty()) {
        QDomDocument doc = createXml();
        saveToFile(doc, dir);
    }
    else {
        QMessageBox::warning(0, "Экспорт декларации", "Экспорт декларации отменен");
    }
}

void WizardExport::setOrgDeyatelnost(QDomDocument doc, QDomElement root) {
    /* /Файл/Документ/Деятельность/Лицензируемая */
    QDomElement licensed = doc.createElement("Лицензируемая");
    root.appendChild(licensed);

    QDomElement lic = doc.createElement("Лицензия");
    licensed.appendChild(lic);

    /* ВидДеят="06" СерНомЛиц="14.2007.Л 0001328" ДатаНачЛиц="26.12.2012" ДатаОконЛиц="25.12.2013" */
    QDomAttr attrVD = doc.createAttribute("ВидДеят");
    attrVD.setValue("06");
    lic.setAttributeNode(attrVD);

    QDomAttr attrSN = doc.createAttribute("СерНомЛиц");
    attrSN.setValue(settings->getLicSerial() + "," + settings->getLicNumber());
    lic.setAttributeNode(attrSN);

    QDomAttr attrSD = doc.createAttribute("ДатаНачЛиц");
    attrSD.setValue(settings->getLicStart().toString("dd.MM.yyyy"));
    lic.setAttributeNode(attrSD);

    QDomAttr attrED = doc.createAttribute("ДатаОконЛиц");
    attrED.setValue(settings->getLicEnd().toString("dd.MM.yyyy"));
    lic.setAttributeNode(attrED);
}

bool WizardExport::isNotAlcohol(ushort code)
{
    return (code == 500 || code == 520 || code == 260 || code == 261 || code ==262 || code == 263);
}

void WizardExport::createOborot(QDomDocument doc, QDomElement root) {
    int tnum = 0;

    Oborot::hashCodeList oborotItems = oborot.getItems();
    QList<ushort> typeKeys = oborotItems.keys();
    int declType = pageDecl->getDeclType();

    for (int i = 0; i < typeKeys.length(); i++) {
        if (declType != 12 && isNotAlcohol(typeKeys[i])) {
            continue;
        }
        if (declType == 12 && ! isNotAlcohol(typeKeys[i])) {
            continue;
        }
        tnum ++;
        QDomElement domOborot = doc.createElement("Оборот");
        root.appendChild(domOborot);

        QDomAttr attrPN = doc.createAttribute("ПN");
        attrPN.setValue(QString::number(tnum));
        domOborot.setAttributeNode(attrPN);

        QDomAttr attrP3 = doc.createAttribute("П000000000003");
        attrP3.setValue(QString::number(typeKeys[i]));
        domOborot.setAttributeNode(attrP3);

        Oborot::hashCodeList::iterator iter1 = oborotItems.find(typeKeys[i]);

        Oborot::hashContragentProductList* key2 = iter1.value();
        QList<Contragent*> producerKeys = key2->keys();
        for (int j = 0; j < producerKeys.length(); j++) {
            QDomElement domProducer = doc.createElement("СведПроизвИмпорт");
            domOborot.appendChild(domProducer);

            QDomAttr attrPN = doc.createAttribute("ПN");
            attrPN.setValue(QString::number(j + 1));
            domProducer.setAttributeNode(attrPN);

            QDomAttr attrIdProducer = doc.createAttribute("ИдПроизвИмп");
            attrIdProducer.setValue(QString::number(producerKeys[j]->getId()));
            domProducer.setAttributeNode(attrIdProducer);

            Oborot::hashContragentProductList::iterator iter2 = key2->find(producerKeys[j]);
            Oborot::hashProductList* value = iter2.value();
            QList<QPair<Contragent*, License*> > valueKeys = value->keys();
            for (int k = 0; k < valueKeys.length(); k++) {
                Oborot::hashProductList::iterator iterValue = value->find(valueKeys[k]);
                QList<Product*>* products = iterValue.value();

                QDomElement domSupplier = doc.createElement("Поставщик");
                domProducer.appendChild(domSupplier);

                QDomAttr attrPN = doc.createAttribute("ПN");
                attrPN.setValue(QString::number(k + 1));
                domSupplier.setAttributeNode(attrPN);

                QDomAttr attrIdSupplier = doc.createAttribute("ИдПоставщика");
                attrIdSupplier.setValue(QString::number(valueKeys[k].first->getId()));
                domSupplier.setAttributeNode(attrIdSupplier);

                if (declType != 12) {
                    if (valueKeys[k].second != NULL) {
                        QDomAttr attrIdLicense = doc.createAttribute("ИдЛицензии");
                        attrIdLicense.setValue(QString::number(valueKeys[k].second->getId()));
                        domSupplier.setAttributeNode(attrIdLicense);
                    }
                }

                for (int l = 0; l < products->length(); l ++) {
                    Product* pr = products->at(l);
                    QDomElement domProduct = doc.createElement("Продукция");
                    domSupplier.appendChild(domProduct);
                    /* П200000000013="10.10.2013" П200000000014=" №001/003034" П200000000015="" П200000000016="1.00000" */
                    QDomAttr attrP2013 = doc.createAttribute("П200000000013");
                    QDomAttr attrP2014 = doc.createAttribute("П200000000014");
                    QDomAttr attrP2015 = doc.createAttribute("П200000000015");
                    QDomAttr attrP2016 = doc.createAttribute("П200000000016");

                    attrP2013.setValue(pr->getDate().toString("dd.MM.yyyy"));
                    attrP2014.setValue(pr->getNumber());
                    attrP2015.setValue(pr->getTdNumber());
                    attrP2016.setValue(QString::number(pr->getValue(), 'f', 5));

                    domProduct.setAttributeNode(attrP2013);
                    domProduct.setAttributeNode(attrP2014);
                    domProduct.setAttributeNode(attrP2015);
                    domProduct.setAttributeNode(attrP2016);

                }
            }

            QPair<ushort,Contragent*> moveId(typeKeys[i], producerKeys[j]);
            Summary *summaryRow = summary.find(moveId).value();

            QDomElement domMove = doc.createElement("Движение");
            domProducer.appendChild(domMove);
            QDomAttr attrPMN = doc.createAttribute("ПN");
            attrPMN.setValue("1");
            QDomAttr attrP1006 = doc.createAttribute("П100000000006");
            attrP1006.setValue(QString::number(summaryRow->getBalanceBegin(), 'f', 5));
            QDomAttr attrP1007 = doc.createAttribute("П100000000007");
            attrP1007.setValue(QString::number(summaryRow->getReceiptFromProducers(), 'f', 5));
            QDomAttr attrP1009 = doc.createAttribute("П100000000009");
            attrP1009.setValue(QString::number(summaryRow->getReceiptImport(), 'f', 5));
            QDomAttr attrP1011 = doc.createAttribute("П100000000011");
            attrP1011.setValue(QString::number(summaryRow->getReceiptConsumption(), 'f', 5));
            QDomAttr attrP1012 = doc.createAttribute("П100000000012");
            attrP1012.setValue(QString::number(summaryRow->getReceiptOther(), 'f', 5));

            QDomAttr attrP1008, attrP1010, attrP1013, attrP1014, attrP1015, attrP1016, attrP1017, attrP1018;
            QDomAttr attrP1019, attrP1020, attrP1021;
            if (declType == 12) {
                attrP1008 = doc.createAttribute("П100000000008");
                attrP1008.setValue(QString::number(summaryRow->getReceiptFromWholesalers(), 'f', 5));
                attrP1010 = doc.createAttribute("П100000000010");
                attrP1010.setValue(QString::number(summaryRow->getReceiptPurchase(), 'f', 5));
                attrP1013 = doc.createAttribute("П100000000013");
                attrP1013.setValue(QString::number(summaryRow->getReceiptTotal(), 'f', 5));
                attrP1014 = doc.createAttribute("П100000000014");
                attrP1014.setValue(QString::number(summaryRow->getConsumptionRetail(), 'f', 5));
                attrP1015 = doc.createAttribute("П100000000015");
                attrP1015.setValue(QString::number(summaryRow->getConsumptionOther(), 'f', 5));
                attrP1016 = doc.createAttribute("П100000000016");
                attrP1016.setValue(QString::number(summaryRow->getConsumptionReturn(), 'f', 5));
                attrP1017 = doc.createAttribute("П100000000017");
                attrP1017.setValue(QString::number(summaryRow->getConsumptionTotal(), 'f', 5));
                attrP1018 = doc.createAttribute("П100000000018");
                attrP1018.setValue(QString::number(summaryRow->getBalanceEnd(), 'f', 5));
            }
            else {
                attrP1008 = doc.createAttribute("П100000000008");
                attrP1008.setValue(QString::number(summaryRow->getReceiptFromWholesalers(), 'f', 5));
                attrP1010 = doc.createAttribute("П100000000010");
                attrP1010.setValue(QString::number(summaryRow->getReceiptPurchase(), 'f', 5));
                attrP1013 = doc.createAttribute("П100000000013");
                attrP1013.setValue(QString::number(summaryRow->getReceiptMove(), 'f', 5));
                attrP1014 = doc.createAttribute("П100000000014");
                attrP1014.setValue(QString::number(summaryRow->getReceiptTotal(), 'f', 5));
                attrP1015 = doc.createAttribute("П100000000015");
                attrP1015.setValue(QString::number(summaryRow->getConsumptionRetail(), 'f', 5));
                attrP1016 = doc.createAttribute("П100000000016");
                attrP1016.setValue(QString::number(summaryRow->getConsumptionOther(), 'f', 5));
                attrP1017 = doc.createAttribute("П100000000017");
                attrP1017.setValue(QString::number(summaryRow->getConsumptionReturn(), 'f', 5));
                attrP1018 = doc.createAttribute("П100000000018");
                attrP1018.setValue(QString::number(summaryRow->getConsumptionMove(), 'f', 5));
                attrP1019 = doc.createAttribute("П100000000019");
                attrP1019.setValue(QString::number(summaryRow->getConsumptionTotal(), 'f', 5));
                attrP1020 = doc.createAttribute("П100000000020");
                attrP1020.setValue(QString::number(summaryRow->getBalanceEnd(), 'f', 5));
                attrP1021 = doc.createAttribute("П100000000021");
                attrP1021.setValue("0.00000");
            }

            domMove.setAttributeNode(attrPMN);
            domMove.setAttributeNode(attrP1006);
            domMove.setAttributeNode(attrP1007);
            domMove.setAttributeNode(attrP1008);
            domMove.setAttributeNode(attrP1009);
            domMove.setAttributeNode(attrP1010);
            domMove.setAttributeNode(attrP1011);
            domMove.setAttributeNode(attrP1012);
            domMove.setAttributeNode(attrP1013);
            domMove.setAttributeNode(attrP1014);
            domMove.setAttributeNode(attrP1015);
            domMove.setAttributeNode(attrP1016);
            domMove.setAttributeNode(attrP1017);
            domMove.setAttributeNode(attrP1018);
            if (declType != 12) {
                domMove.setAttributeNode(attrP1019);
                domMove.setAttributeNode(attrP1020);
                domMove.setAttributeNode(attrP1021);
            }
        }
    }
}

bool WizardExport::sortContragents (Contragent* a, Contragent * b) {
    bool ret = (a->getId() < b->getId());
    if (a->getProducer() && ! b->getProducer())
        ret = true;
    if (!a->getProducer() && b->getProducer())
        ret = false;
    return ret;
}

void WizardExport::setDirectory(QDomDocument doc, QDomElement directory) {
    QList<Contragent*> listContragents;
    QHashIterator<QPair<QString,QString>,Contragent*> iter(contragents);
    while (iter.hasNext()) {
        iter.next();
        listContragents.append(iter.value());
    }
    qSort(listContragents.begin(), listContragents.end(), WizardExport::sortContragents);

    int declType = pageDecl->getDeclType();

//    while (iter.hasNext()) {
//        iter.next();
//        Contragent* row = iter.value();
    QList<Contragent*>::const_iterator ii = listContragents.constBegin();
    for (; ii != listContragents.constEnd(); ++ii) {
        Contragent* row = *ii;
        if (row->getProducer()) {
            /* /Файл/Справочники/ПроизводителиИмпортеры */
            QDomElement producer = doc.createElement("ПроизводителиИмпортеры");
            directory.appendChild(producer);

            QDomAttr attrId = doc.createAttribute("ИДПроизвИмп");
            attrId.setValue(QString::number(row->getId()));
            producer.setAttributeNode(attrId);

            QDomAttr attrP4 = doc.createAttribute("П000000000004");
            attrP4.setValue(row->getName());
            producer.setAttributeNode(attrP4);

            QDomAttr attrP5 = doc.createAttribute("П000000000005");
            attrP5.setValue(row->getInn());
            QDomAttr attrP6 = doc.createAttribute("П000000000006");
            attrP6.setValue(row->getKpp());

            bool nonResident = row->getKpp().isEmpty() || row->getKpp() == " ";
            if (declType == 12) {
                QDomElement ul = doc.createElement("ЮЛ");
                producer.appendChild(ul);

                if (nonResident) {
                    attrP5.setValue("0");
                    ul.setAttributeNode(attrP5);
                }
                else {
                    ul.setAttributeNode(attrP5);
                    ul.setAttributeNode(attrP6);
                }
            }
            else {
                if (nonResident) {
                    attrP5.setValue("0");
                    producer.setAttributeNode(attrP5);
                }
                else {
                    producer.setAttributeNode(attrP5);
                    producer.setAttributeNode(attrP6);
                }
            }
        }
        else {
            /* /Файл/Справочники/Поставщики */
            QDomElement carrier = doc.createElement("Поставщики");
            directory.appendChild(carrier);

            QDomAttr attrId = doc.createAttribute("ИдПостав");
            attrId.setValue(QString::number(row->getId()));
            carrier.setAttributeNode(attrId);

            QDomAttr attrP7 = doc.createAttribute("П000000000007");
            attrP7.setValue(row->getName());
            carrier.setAttributeNode(attrP7);

            if (declType != 12) {
                QHashIterator<QString,License*> iterLicenses(row->getLicenses());

                if (iterLicenses.hasNext()) {
                    while (iterLicenses.hasNext()) {
                        /* /Файл/Справочники/Поставщики/Лицензии */
                        QDomElement licenses = doc.createElement("Лицензии");
                        carrier.appendChild(licenses);

                        /* /Файл/Справочники/Поставщики/Лицензии/Лицензия */

                        QDomElement lic = doc.createElement("Лицензия");
                        licenses.appendChild(lic);

                        /* Лицензия ИдЛицензии="7" П000000000011="А,604495" П000000000012="26.06.2012" П000000000013="26.06.2017" П000000000014="ФС по регулированию алкогольного рынка" /> */
                        iterLicenses.next();
                        License* rowLicense = iterLicenses.value();

                        QDomAttr attrId = doc.createAttribute("ИдЛицензии");
                        attrId.setValue(QString::number(rowLicense->getId()));
                        lic.setAttributeNode(attrId);

                        QDomAttr attrP11 = doc.createAttribute("П000000000011");
                        attrP11.setValue(rowLicense->getNumber());
                        lic.setAttributeNode(attrP11);

                        QDomAttr attrP12 = doc.createAttribute("П000000000012");
                        attrP12.setValue(rowLicense->getStartDate().toString("dd.MM.yyyy"));
                        lic.setAttributeNode(attrP12);

                        QDomAttr attrP13 = doc.createAttribute("П000000000013");
                        attrP13.setValue(rowLicense->getEndDate().toString("dd.MM.yyyy"));
                        lic.setAttributeNode(attrP13);

                        QDomAttr attrP14 = doc.createAttribute("П000000000014");
                        attrP14.setValue(rowLicense->getDepartment());
                        lic.setAttributeNode(attrP14);
                    }
                }
            }
            /* /Файл/Справочники/Поставщики/ЮЛ */
            /* <ЮЛ П000000000009="1435237751" П000000000010="143541001" /> */
            QDomElement ul = doc.createElement("ЮЛ");
            carrier.appendChild(ul);

            bool nonResident = row->getKpp().isEmpty() || row->getKpp() == " ";

            if (nonResident) {
                QDomAttr attrP9 = doc.createAttribute("П000000000009");
                attrP9.setValue("0");
                ul.setAttributeNode(attrP9);
            }
            else {
                QDomAttr attrP9 = doc.createAttribute("П000000000009");
                attrP9.setValue(row->getInn());
                ul.setAttributeNode(attrP9);

                QDomAttr attrP10 = doc.createAttribute("П000000000010");
                attrP10.setValue(row->getKpp().isEmpty() || row->getKpp() == " " ? "0" : row->getKpp());
                ul.setAttributeNode(attrP10);
            }
        }
    }
}

void WizardExport::setOrgOtvLitso(QDomDocument doc, QDomElement orgOtvLitso) {
    /* /Файл/Документ/Организация/ОтветЛицо/Руководитель */
    QDomElement orgHead = doc.createElement("Руководитель");
    orgOtvLitso.appendChild(orgHead);

    /* /Файл/Документ/Организация/ОтветЛицо/Руководитель/Фамилия */
    QDomElement orgHeadSurname = doc.createElement("Фамилия");
    if (!settings->getHeadSurName().isEmpty())
        orgHeadSurname.appendChild(doc.createTextNode(settings->getHeadSurName()));
    orgHead.appendChild(orgHeadSurname);

    /* /Файл/Документ/Организация/ОтветЛицо/Руководитель/Имя */
    QDomElement orgHeadName = doc.createElement("Имя");
    if (!settings->getHeadName().isEmpty())
        orgHeadName.appendChild(doc.createTextNode(settings->getHeadName()));
    orgHead.appendChild(orgHeadName);

    /* /Файл/Документ/Организация/ОтветЛицо/Руководитель/Отчество */
    QDomElement orgHeadMiddleName = doc.createElement("Отчество");
    if (!settings->getHeadMiddleName().isEmpty())
        orgHeadMiddleName.appendChild(doc.createTextNode(settings->getHeadMiddleName()));
    orgHead.appendChild(orgHeadMiddleName);

    /* /Файл/Документ/Организация/ОтветЛицо/Главбух */
    QDomElement orgAcc = doc.createElement("Главбух");
    orgOtvLitso.appendChild(orgAcc);

    /* /Файл/Документ/Организация/ОтветЛицо/Главбух/Фамилия */
    QDomElement orgAccSurname = doc.createElement("Фамилия");
    if (!settings->getAccSurName().isEmpty())
        orgAccSurname.appendChild(doc.createTextNode(settings->getAccSurName()));
    orgAcc.appendChild(orgAccSurname);

    /* /Файл/Документ/Организация/ОтветЛицо/Главбух/Имя */
    QDomElement orgAccName = doc.createElement("Имя");
    if (!settings->getAccName().isEmpty())
        orgAccName.appendChild(doc.createTextNode(settings->getAccName()));
    orgAcc.appendChild(orgAccName);

    /* /Файл/Документ/Организация/ОтветЛицо/Главбух/Отчество */
    QDomElement orgAccMiddleName = doc.createElement("Отчество");
    if (!settings->getAccMiddleName().isEmpty())
        orgAccMiddleName.appendChild(doc.createTextNode(settings->getAccMiddleName()));
    orgAcc.appendChild(orgAccMiddleName);
}

void WizardExport::setAddrOrg(QDomDocument doc, QDomElement addrOrg) {
    /* /Файл/Документ/Организация/Реквизиты/АдрОрг/КодСтраны */
    QDomElement orgCountryCode = doc.createElement("КодСтраны");
    orgCountryCode.appendChild(doc.createTextNode(QString::number(settings->getAddrCountryCode())));
    addrOrg.appendChild(orgCountryCode);

    /* /Файл/Документ/Организация/Реквизиты/АдрОрг/Индекс */
    QDomElement orgPostalCode = doc.createElement("Индекс");
    if (!settings->getAddrPostalCode().isEmpty())
        orgPostalCode.appendChild(doc.createTextNode(settings->getAddrPostalCode()));
    addrOrg.appendChild(orgPostalCode);

    /* /Файл/Документ/Организация/Реквизиты/АдрОрг/КодРегион */
    QDomElement orgRegionCode = doc.createElement("КодРегион");
    orgRegionCode.appendChild(doc.createTextNode(QString::number(settings->getAddrRegionCode())));
    addrOrg.appendChild(orgRegionCode);

    /* /Файл/Документ/Организация/Реквизиты/АдрОрг/Район */
    QDomElement orgDistrict = doc.createElement("Район");
    //orgDistrict.setNodeValue();
    addrOrg.appendChild(orgDistrict);

    /* /Файл/Документ/Организация/Реквизиты/АдрОрг/Город */
    QDomElement orgCity = doc.createElement("Город");
    orgCity.appendChild(doc.createTextNode(settings->getAddrCity()));
    addrOrg.appendChild(orgCity);

    /* /Файл/Документ/Организация/Реквизиты/АдрОрг/НаселПункт */
    QDomElement orgTown = doc.createElement("НаселПункт");
    //orgTown.setNodeValue();
    addrOrg.appendChild(orgTown);

    /* /Файл/Документ/Организация/Реквизиты/АдрОрг/Улица */
    QDomElement orgStreet = doc.createElement("Улица");
    orgStreet.appendChild(doc.createTextNode(settings->getAddrStreet()));
    addrOrg.appendChild(orgStreet);

    /* /Файл/Документ/Организация/Реквизиты/АдрОрг/Дом */
    QDomElement orgBuilding = doc.createElement("Дом");
    orgBuilding.appendChild(doc.createTextNode(settings->getAddrBuilding()));
    addrOrg.appendChild(orgBuilding);

    /* /Файл/Документ/Организация/Реквизиты/АдрОрг/Корпус */
    QDomElement orgBuildingIndex = doc.createElement("Корпус");
    orgBuildingIndex.appendChild(doc.createTextNode(settings->getAddrBuildingIndex()));
    addrOrg.appendChild(orgBuildingIndex);

    /* /Файл/Документ/Организация/Реквизиты/АдрОрг/Литера */
    QDomElement orgBuildingLitera = doc.createElement("Литера");
    //orgBuildingLitera.setNodeValue();
    addrOrg.appendChild(orgBuildingLitera);

    /* /Файл/Документ/Организация/Реквизиты/АдрОрг/Кварт */
    QDomElement orgApartment = doc.createElement("Кварт");
    orgApartment.appendChild(doc.createTextNode(settings->getAddrApartment()));
    addrOrg.appendChild(orgApartment);
}
