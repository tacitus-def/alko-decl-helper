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

#include "settings.h"

Settings::Settings()
{
    settings = new QSettings("alko-decl-helper", "settings");
}

Settings::~Settings()
{
    delete settings;
}

void Settings::readIniFile()
{
    dbFilePath = settings->value("AlkoDB/path", "").toString();
    dbPassword = settings->value("AlkoDB/password", "").toString();

    orgName     = settings->value("Organization/name", "").toString();
    orgINN      = settings->value("Organization/inn", "").toString();
    orgKPP      = settings->value("Organization/kpp", "").toString();
    orgTel      = settings->value("Organization/phone", "").toString();
    orgEmail    = settings->value("Organization/email", "").toString();

    addrCountryCode = settings->value("Address/country_code", "").toInt();
    addrRegionCode  = settings->value("Address/region_code", "").toInt();

    addrPostalCode    = settings->value("Address/postal_code", "").toString();
    addrCity          = settings->value("Address/city", "").toString();
    addrStreet        = settings->value("Address/street", "").toString();
    addrBuilding      = settings->value("Address/building", "").toString();
    addrBuildingIndex = settings->value("Address/building_index", "").toString();
    addrApartment     = settings->value("Address/apartment", "").toString();

    headName   = settings->value("Head/name", "").toString();
    headSurName    = settings->value("Head/surname", "").toString();
    headMiddleName     = settings->value("Head/middle_name", "").toString();

    licStart = settings->value("License/start", "").toDate();
    licEnd = settings->value("License/end", "").toDate();
    licSerial = settings->value("License/serial", "").toString();
    licNumber = settings->value("License/number", "").toString();
    licType = settings->value("License/type", "").toInt();
}

void Settings::saveIniFile()
{
    settings->setValue("AlkoDB/path", dbFilePath);
    settings->setValue("AlkoDB/password", dbPassword);

    settings->setValue("Organization/name", orgName);
    settings->setValue("Organization/inn", orgINN);
    settings->setValue("Organization/kpp", orgKPP);
    settings->setValue("Organization/phone", orgTel);
    settings->setValue("Organization/email", orgEmail);

    settings->setValue("Address/country_code", addrCountryCode);
    settings->setValue("Address/region_code", addrRegionCode);

    settings->setValue("Address/postal_code", addrPostalCode);
    settings->setValue("Address/city", addrCity);
    settings->setValue("Address/street", addrStreet);
    settings->setValue("Address/building", addrBuilding);
    settings->setValue("Address/building_index", addrBuildingIndex);
    settings->setValue("Address/apartment", addrApartment);

    settings->setValue("Head/name", headName);
    settings->setValue("Head/surname", headSurName);
    settings->setValue("Head/middle_name", headMiddleName);

    settings->setValue("License/start", licStart);
    settings->setValue("License/end", licEnd);
    settings->setValue("License/serial", licSerial);
    settings->setValue("License/number", licNumber);
    settings->setValue("License/type", licType);
}

Settings *Settings::getInstance()
{
    static Settings *instance = new Settings();

    return instance;
}

QString Settings::getDbFilePath()
{
    return dbFilePath;
}

void Settings::setDbFilePath(const QString &value)
{
    dbFilePath = value;
}
QString Settings::getDbPassword()
{
    return dbPassword;
}

void Settings::setDbPassword(const QString &value)
{
    dbPassword = value;
}
QString Settings::getOrgName() const
{
    return orgName;
}

void Settings::setOrgName(const QString &value)
{
    orgName = value;
}
QString Settings::getOrgINN() const
{
    return orgINN;
}

void Settings::setOrgINN(const QString &value)
{
    orgINN = value;
}
QString Settings::getOrgKPP() const
{
    return orgKPP;
}

void Settings::setOrgKPP(const QString &value)
{
    orgKPP = value;
}
QString Settings::getOrgTel() const
{
    return orgTel;
}

void Settings::setOrgTel(const QString &value)
{
    orgTel = value;
}
QString Settings::getOrgEmail() const
{
    return orgEmail;
}

void Settings::setOrgEmail(const QString &value)
{
    orgEmail = value;
}
int Settings::getAddrCountryCode() const
{
    return addrCountryCode;
}

void Settings::setAddrCountryCode(const int &value)
{
    addrCountryCode = value;
}
int Settings::getAddrRegionCode() const
{
    return addrRegionCode;
}

void Settings::setAddrRegionCode(const int &value)
{
    addrRegionCode = value;
}
QString Settings::getAddrPostalCode() const
{
    return addrPostalCode;
}

void Settings::setAddrPostalCode(const QString &value)
{
    addrPostalCode = value;
}
QString Settings::getAddrCity() const
{
    return addrCity;
}

void Settings::setAddrCity(const QString &value)
{
    addrCity = value;
}
QString Settings::getAddrStreet() const
{
    return addrStreet;
}

void Settings::setAddrStreet(const QString &value)
{
    addrStreet = value;
}
QString Settings::getAddrBuilding() const
{
    return addrBuilding;
}

void Settings::setAddrBuilding(const QString &value)
{
    addrBuilding = value;
}
QString Settings::getAddrApartment() const
{
    return addrApartment;
}

void Settings::setAddrApartment(const QString &value)
{
    addrApartment = value;
}
QString Settings::getHeadMiddleName() const
{
    return headMiddleName;
}

void Settings::setHeadMiddleName(const QString &value)
{
    headMiddleName = value;
}
QString Settings::getHeadName() const
{
    return headName;
}

void Settings::setHeadName(const QString &value)
{
    headName = value;
}
QString Settings::getHeadSurName() const
{
    return headSurName;
}

void Settings::setHeadSurName(const QString &value)
{
    headSurName = value;
}
QString Settings::getAddrBuildingIndex() const
{
    return addrBuildingIndex;
}

void Settings::setAddrBuildingIndex(const QString &value)
{
    addrBuildingIndex = value;
}
QString Settings::getAccSurName() const
{
    return accSurName;
}

void Settings::setAccSurName(const QString &value)
{
    accSurName = value;
}
QString Settings::getAccName() const
{
    return accName;
}

void Settings::setAccName(const QString &value)
{
    accName = value;
}
QString Settings::getAccMiddleName() const
{
    return accMiddleName;
}

void Settings::setAccMiddleName(const QString &value)
{
    accMiddleName = value;
}

int Settings::getLicType() const
{
    return licType;
}

void Settings::setLicType(int value)
{
    licType = value;
}

QDate Settings::getLicEnd() const
{
    return licEnd;
}

void Settings::setLicEnd(const QDate &value)
{
    licEnd = value;
}

QDate Settings::getLicStart() const
{
    return licStart;
}

void Settings::setLicStart(const QDate &value)
{
    licStart = value;
}

QString Settings::getLicNumber() const
{
    return licNumber;
}

void Settings::setLicNumber(const QString &value)
{
    licNumber = value;
}

QString Settings::getLicSerial() const
{
    return licSerial;
}

void Settings::setLicSerial(const QString &value)
{
    licSerial = value;
}





















