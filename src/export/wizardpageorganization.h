#ifndef WIZARDPAGEORGANIZATION_H
#define WIZARDPAGEORGANIZATION_H

#include <QWizardPage>
#include "../helpers/alkohelperinput.h"
#include "../settings.h"

namespace Ui {
class WizardPageOrganization;
}

class WizardPageOrganization : public QWizardPage
{
    Q_OBJECT
    
public:
    explicit WizardPageOrganization(QWidget *parent = 0);
    ~WizardPageOrganization();
    
    bool validatePage();

    QString getOrgName();
    QString getOrgINN();
    QString getOrgKPP();
    QString getOrgTel();
    QString getOrgEMail();
    QString getHeadSurname();
    QString getHeadName();
    QString getHeadMiddleName();
    QString getAccSurname();
    QString getAccName();
    QString getAccMiddleName();
    int getOrgCountryCode();
    int getOrgRegionCode();
    QString getOrgPostalCode();
    QString getOrgCity();
    QString getOrgStreet();
    QString getBuilding();
    QString getBuildingIndex();
    QString getOrgApartment();
private:
    Ui::WizardPageOrganization *ui;

    void loadSettings();
    void saveSettings();
};

#endif // WIZARDPAGEORGANIZATION_H
