//
// Created by jdinh on 10/8/2020.
//

#ifndef CHAPTER11PRACTICEPROGRAM1_MONEY_H
#define CHAPTER11PRACTICEPROGRAM1_MONEY_H

#include <iostream>

using namespace std;

class Money
{
public:
    double amount;

    Money();
    Money(double amountInput);

    Money percent(int calculatePercent) const;

    bool operator<(const Money& amount2);
    bool operator>(const Money& amount2);
    bool operator<=(const Money& amount2);
    bool operator>=(const Money& amount2);

};


#endif //CHAPTER11PRACTICEPROGRAM1_MONEY_H
