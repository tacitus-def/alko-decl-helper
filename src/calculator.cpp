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

#include "calculator.h"

Calculator::Calculator() { }

double Calculator::execute(QString value) {
    stream.str(value.toStdString());

    return expr();
}

double Calculator::expr()
{
    double result = factor();
    char c;

    while (true)
    {

        c = stream.get();

        while (c == ' ') {
            c = stream.get();
        }
        switch (c)
        {
        case '+':
            result += factor();
            break;
        case '-':
            result -= factor();
            break;
        default:
            stream.putback(c);
            return result;
        }
    }
}

double Calculator::number()
{
    double result = 0.0;
    double k = 10.0;
    int sign = 1;
    char c;

    c = stream.get();

    while (c == ' ')
    c = stream.get();

    if (c == '-') {
        sign = -1;
    }
    else {
        stream.putback(c);
    }
    while (true)
    {
        c = stream.get();

        while (c == ' ')
            c = stream.get();

        if (c >= '0' && c <= '9') {
            result = result * 10.0 + (c - '0');
        }
        else
        {
            stream.putback(c);
            break;
        }
    }

    c = stream.get();

    if (c == '.')
    {
        while (true)
        {
            c = stream.get();

            if (c >= '0' && c <= '9') {
                result += (c - '0') / k;
                k *= 10.0;
            }
            else
            {
                stream.putback(c);
                break;
            }
        }
    }
    else {
        stream.putback(c);
    }
    return sign * result;
}

double Calculator::factor()
{
    double result = brackets();
    double temp;
    char c;

    while (true)
    {
        c = stream.get();

        while (c == ' ') {
            c = stream.get();
        }

        switch (c)
        {
        case '*':
            result *= brackets();
            break;
        case '/':
            temp = brackets();

            if (temp == 0.0)
            {
                throw "Division by zero";
            }

            result /= temp;
            break;
        default:
            stream.putback(c);
            return result;
        }
    }
}

double Calculator::brackets()
{
    double result;
    int sign = 1;
    char c;

    c = stream.get();

    while (c == ' ') {
        c = stream.get();
    }

    if (c == '-') {
        sign = -1;
        c = stream.get();
    }

    while (c == ' ') {
        c = stream.get();
    }

    if (c == '(') {
        result = sign * expr();

        c = stream.get();

        if (c != ')')
        {
            throw "Illegal brackets";
        }

        return result;
    }
    else {
        stream.putback(c);

        return sign * number();
    }
}
