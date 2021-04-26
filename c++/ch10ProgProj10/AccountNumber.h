//
// Created by jdinh on 9/26/2020.
//

//Chapter 10 Programming Project #10

#ifndef CHAPTER10PROGRAMMINGPROJECT10_ACCOUNTNUMBER_H
#define CHAPTER10PROGRAMMINGPROJECT10_ACCOUNTNUMBER_H


class AccountNumber
{
private:
    int accountNumber[5];
    int* accountPointer;

public:
    int size, sum;

    AccountNumber();
    AccountNumber(int* setAccountPointer, int setSize, int accountNumberInput);

    bool checkAccountNumber();

};


#endif //CHAPTER10PROGRAMMINGPROJECT10_ACCOUNTNUMBER_H
