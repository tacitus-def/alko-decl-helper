#ifndef WIZARDEXPORT_H
#define WIZARDEXPORT_H

#include <QWizard>
#include <QFile>
#include <QHash>
#include <QPair>
#include <QUuid>
#include <QVector>
#include <QVariant>
#include <QDomDocument>
#include <QFileDialog>
#include <QMessageBox>
#include "contragent.h"
#include "settings.h"
#include "product.h"
#include "oborot.h"
#include "export/wizardpageorganization.h"
#include "export/wizardpagedeclproperties.h"
#include "summary.h"

namespace Ui {
class WizardExport;
}

class WizardExport : public QWizard
{
    Q_OBJECT

public:
    explicit WizardExport(QWidget *parent = 0);
    ~WizardExport();

    QHash<QPair<ushort, Contragent*>, Summary*> getSummary() const;
    void setSummary(const QHash<QPair<ushort, Contragent *>, Summary *> &value);

    QHash<Contragent::qpair, Contragent*> getContragents() const;
    void setContragents(const QHash<Contragent::qpair, Contragent*> value);

    QHash<QString, License*> getLicenses() const;
    void setLicenses(const QHash<QString, License*> &value);

    QVector<Product*> getProducts();
    void setProducts(const QVector<Product*> &value);

    enum { Page_Organization, Page_Declaration };

    Oborot getOborot() const;
    void setOborot(Oborot &value);

    static bool sortContragents(Contragent *a, Contragent *b);
public slots:
    void wizardFinish(int result);

private:
    Ui::WizardExport *ui;

    Settings *settings;

    QHash<QPair<ushort,Contragent*>,Summary*> summary;
    Oborot oborot;

    QHash<Contragent::qpair, Contragent*> contragents;
    QHash<QString,License*> licenses;
    QVector<Product*> products;

    WizardPageOrganization* pageOrg;
    WizardPageDeclProperties* pageDecl;

    void init();
    void addPages();

    void setDirectory(QDomDocument doc, QDomElement directory);
    void setAddrOrg(QDomDocument doc, QDomElement addrOrg);
    void setOrgOtvLitso(QDomDocument doc, QDomElement orgOtvLitso);
    void createOborot(QDomDocument doc, QDomElement root);
    void setOrgDeyatelnost(QDomDocument doc, QDomElement root);

    bool isNotAlcohol(ushort code);
    void saveToFile(QDomDocument doc, QString dir);
    QDomDocument createXml();
};

#endif // WIZARDEXPORT_H
