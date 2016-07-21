#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <QString>
#include <sstream>

class Calculator {
public:
    Calculator();

    double execute(QString value);
private:
    std::istringstream stream;

    double expr();
    double number();
    double factor();
    double brackets();
};

#endif // CALCULATOR_H
