#ifndef WIZARDPAGEDECLPROPERTIES_H
#define WIZARDPAGEDECLPROPERTIES_H

#include <QWizardPage>
#include "../helpers/alkohelperinput.h"
#include "../settings.h"

namespace Ui {
class WizardPageDeclProperties;
}

class WizardPageDeclProperties : public QWizardPage
{
    Q_OBJECT
    
public:
    explicit WizardPageDeclProperties(QWidget *parent = 0);
    ~WizardPageDeclProperties();
    
    bool validatePage();

    int getDeclDocType();
    QString getDeclCorrNumber();
    QString getProvidedFor();
    int getDeclType();
    QString getLicSerial();
    QString getLicNumber();
    int getDeclQuarter();
    int getDeclYear();
    int getDeclSign();
    int getLicType();
    QDate getLicStart();
    QDate getLicEnd();
private:
    Ui::WizardPageDeclProperties *ui;
    void loadSettings();
    void saveSettings();
};

#endif // WIZARDPAGEDECLPROPERTIES_H
