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

#ifndef SUMMARY_H
#define SUMMARY_H

#include <cmath>
#include "contragent.h"

class Summary
{
public:
    Summary(uint code, Contragent *contragent);

    double getBalanceBegin() const;
    void setBalanceBegin(double value);

    double getBalanceEnd() const;
    void setBalanceEnd(double value);

    double getReceiptFromProducers() const;
    void setReceiptFromProducers(double value);

    double getReceiptFromWholesalers() const;
    void setReceiptFromWholesalers(double value);

    double getReceiptImport() const;
    void setReceiptImport(double value);

    double getReceiptConsumption() const;
    void setReceiptConsumption(double value);

    double getReceiptOther() const;
    void setReceiptOther(double value);

    double getReceiptMove() const;
    void setReceiptMove(double value);

    double getConsumptionRetail() const;
    void setConsumptionRetail(double value);

    double getConsumptionOther() const;
    void setConsumptionOther(double value);

    double getConsumptionReturn() const;
    void setConsumptionReturn(double value);

    double getConsumptionMove() const;
    void setConsumptionMove(double value);

    void calculateBalanceEnd();
    double getReceiptPurchase() const;
    double getReceiptTotal() const;
    double getConsumptionTotal() const;

    Contragent *getContragent() const;
    void setContragent(Contragent *value);

    uint getCode() const;
    void setCode(const uint &value);

private:
    uint code;
    Contragent *contragent;

    double balance_begin;

    double receipt_from_producers;
    double receipt_from_wholesalers;
    double receipt_import;
    double receipt_consumption;
    double receipt_other;
    double receipt_move;

    double consumption_retail;
    double consumption_other;
    double consumption_return;
    double consumption_move;

    double balance_end;
    double roundValue(double value);
};

#endif // SUMMARY_H
