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
