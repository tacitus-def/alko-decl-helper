#include "summary.h"

Summary::Summary(uint code, Contragent *contragent)
{
    this->code = code;
    this->contragent = contragent;

    balance_begin = .0;

    receipt_from_producers  = .0;
    receipt_from_wholesalers  = .0;
    receipt_import  = .0;
    receipt_consumption  = .0;
    receipt_other  = .0;
    receipt_move  = .0;

    consumption_retail  = .0;
    consumption_other  = .0;
    consumption_return  = .0;
    consumption_move  = .0;

    balance_end  = .0;
}

double Summary::roundValue(double value) {
     return round (value * 100000) / 100000;
}

void Summary::calculateBalanceEnd() {
    double value = balance_begin
                 + receipt_consumption
                 + receipt_from_producers
                 + receipt_from_wholesalers
                 + receipt_import
                 + receipt_move
                 + receipt_other
                 - consumption_move
                 - consumption_other
                 - consumption_retail
                 - consumption_return;
    setBalanceEnd(value);
}

double Summary::getBalanceBegin() const
{
    return balance_begin;
}

void Summary::setBalanceBegin(double value)
{
    balance_begin = roundValue(value);
    calculateBalanceEnd();
}
double Summary::getBalanceEnd() const
{
    return balance_end;
}

void Summary::setBalanceEnd(double value)
{
    balance_end = roundValue(value);
}

double Summary::getReceiptFromProducers() const
{
    return receipt_from_producers;
}

void Summary::setReceiptFromProducers(double value)
{
    receipt_from_producers = roundValue(value);
    calculateBalanceEnd();
}

double Summary::getReceiptFromWholesalers() const
{
    return receipt_from_wholesalers;
}

void Summary::setReceiptFromWholesalers(double value)
{
    receipt_from_wholesalers = roundValue(value);
    calculateBalanceEnd();
}

double Summary::getReceiptImport() const
{
    return receipt_import;
}

void Summary::setReceiptImport(double value)
{
    receipt_import = roundValue(value);
    calculateBalanceEnd();
}

double Summary::getReceiptConsumption() const
{
    return receipt_consumption;
}

void Summary::setReceiptConsumption(double value)
{
    receipt_consumption = roundValue(value);
    calculateBalanceEnd();
}

double Summary::getReceiptOther() const
{
    return receipt_other;
}

void Summary::setReceiptOther(double value)
{
    receipt_other = roundValue(value);
    calculateBalanceEnd();
}

double Summary::getReceiptMove() const
{
    return receipt_move;
}

void Summary::setReceiptMove(double value)
{
    receipt_move = roundValue(value);
    calculateBalanceEnd();
}

double Summary::getReceiptTotal() const {
    return receipt_consumption
         + receipt_from_producers
         + receipt_from_wholesalers
         + receipt_import
         + receipt_move
         + receipt_other;
}

double Summary::getReceiptPurchase() const {
    return receipt_from_producers
         + receipt_from_wholesalers
         + receipt_import;
}

double Summary::getConsumptionTotal() const
{
    return consumption_move
         + consumption_other
         + consumption_retail
         + consumption_return;
}
Contragent *Summary::getContragent() const
{
    return contragent;
}

void Summary::setContragent(Contragent *value)
{
    contragent = value;
}
uint Summary::getCode() const
{
    return code;
}

void Summary::setCode(const uint &value)
{
    code = value;
}



double Summary::getConsumptionRetail() const
{
    return consumption_retail;
}

void Summary::setConsumptionRetail(double value)
{
    consumption_retail = roundValue(value);
    calculateBalanceEnd();
}

double Summary::getConsumptionOther() const
{
    return consumption_other;
}

void Summary::setConsumptionOther(double value)
{
    consumption_other = roundValue(value);
    calculateBalanceEnd();
}

double Summary::getConsumptionReturn() const
{
    return consumption_return;
}

void Summary::setConsumptionReturn(double value)
{
    consumption_return = roundValue(value);
    calculateBalanceEnd();
}

double Summary::getConsumptionMove() const
{
    return consumption_move;
}

void Summary::setConsumptionMove(double value)
{
    consumption_move = roundValue(value);
    calculateBalanceEnd();
}


