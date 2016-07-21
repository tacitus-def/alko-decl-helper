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
