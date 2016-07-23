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

#ifndef SETTINGS_H
#define SETTINGS_H
#include <QDate>
#include <QString>
#include <QVariant>
#include <QSettings>

class Settings
{
public:
    Settings();
    ~Settings();

    void readIniFile();
    void saveIniFile();

    static Settings* getInstance();

    QString getOrgName() const;
    void setOrgName(const QString &value);

    QString getOrgINN() const;
    void setOrgINN(const QString &value);

    QString getOrgKPP() const;
    void setOrgKPP(const QString &value);

    QString getOrgTel() const;
    void setOrgTel(const QString &value);

    QString getOrgEmail() const;
    void setOrgEmail(const QString &value);

    int getAddrCountryCode() const;
    void setAddrCountryCode(const int &value);

    int getAddrRegionCode() const;
    void setAddrRegionCode(const int &value);

    QString getAddrPostalCode() const;
    void setAddrPostalCode(const QString &value);

    QString getAddrCity() const;
    void setAddrCity(const QString &value);

    QString getAddrStreet() const;
    void setAddrStreet(const QString &value);

    QString getAddrBuilding() const;
    void setAddrBuilding(const QString &value);

    QString getAddrApartment() const;
    void setAddrApartment(const QString &value);

    QString getHeadSurName() const;
    void setHeadSurName(const QString &value);

    QString getHeadName() const;
    void setHeadName(const QString &value);

    QString getHeadMiddleName() const;
    void setHeadMiddleName(const QString &value);

    QString getAddrBuildingIndex() const;
    void setAddrBuildingIndex(const QString &value);

    QString getAccSurName() const;
    void setAccSurName(const QString &value);

    QString getAccName() const;
    void setAccName(const QString &value);

    QString getAccMiddleName() const;
    void setAccMiddleName(const QString &value);

    QString getLicSerial() const;
    void setLicSerial(const QString &value);

    QString getLicNumber() const;
    void setLicNumber(const QString &value);

    QDate getLicStart() const;
    void setLicStart(const QDate &value);

    QDate getLicEnd() const;
    void setLicEnd(const QDate &value);

    int getLicType() const;
    void setLicType(int value);

private:
    QSettings* settings;

    QString orgName;
    QString orgINN;
    QString orgKPP;
    QString orgTel;
    QString orgEmail;

    int addrCountryCode;
    int addrRegionCode;

    QString addrPostalCode;
    QString addrCity;
    QString addrStreet;
    QString addrBuilding;
    QString addrBuildingIndex;
    QString addrApartment;

    QString headSurName;
    QString headName;
    QString headMiddleName;

    QString accSurName;
    QString accName;
    QString accMiddleName;

    QString licSerial;
    QString licNumber;
    QDate licStart;
    QDate licEnd;
    int licType;
};

#endif // SETTINGS_H
