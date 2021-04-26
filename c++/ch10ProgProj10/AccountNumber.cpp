//
// Created by jdinh on 9/26/2020.
//

//Chapter 10 Programming Project #10

#include "AccountNumber.h"

AccountNumber::AccountNumber()
{
    size = 5;
    sum = 0;
}


AccountNumber::AccountNumber(int *setAccountPointer, int setSize, int accountNumberInput)
{
    accountPointer = setAccountPointer;

    size = setSize;

    for (int i = size - 1; i >= 0; i--)
    {
        accountNumber[i] = accountNumberInput % 10;

        accountNumberInput = accountNumberInput / 10;
    }
}


bool AccountNumber::checkAccountNumber()
{
    //had trouble on this part
    accountPointer = accountNumber;

    for (int i = size - 1; i >= 0; i--)
    {
        if (i % 2 == 1)
        {
            *(accountPointer + i) = *(accountPointer + i) * 2;

            if (*(accountPointer + i) > 9)
            {
                *(accountPointer + i) -= 9;
            }
        }
        sum += *(accountPointer + i);
    }

    if (sum % 10 == 0)
    {
        return true;
    }

    else
    {
        return false;
    }
}