//
// Created by jdinh on 10/8/2020.
//

#include "Money.h"

Money::Money()
{
    amount = 0;
}


Money::Money(double amountInput)
{
    amount = amountInput;
}


bool Money::operator>(const Money &amount2)
{
    if (amount > amount2.amount)
    {
        return true;
    }
    return false;
}


bool Money::operator<(const Money &amount2)
{
    if (amount < amount2.amount)
    {
        return true;
    }
    return false;
}


bool Money::operator<=(const Money &amount2)
{
    if (amount <= amount2.amount)
    {
        return true;
    }
    return false;
}


bool Money::operator>=(const Money &amount2)
{
    if (amount >= amount2.amount)
    {
        return true;
    }
    return false;
}


Money Money::percent(int calculatePercent) const
{
    Money value;
    value.amount = ((amount)*calculatePercent) / 100;

    return value;
}