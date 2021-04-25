//
// Created by jdinh on 9/21/2020.
//

//Chapter 10 Practice Program #1

#ifndef CHAPTER10PRACTICEPROGRAM1_CDACCOUNT_H
#define CHAPTER10PRACTICEPROGRAM1_CDACCOUNT_H

using namespace std;


class CDAccount
{
private:
    double balance, interestRate, setBalance, setInterestRate;
    int term, setTerm;   //months until maturity

public:
    double rateFraction, interest, totalBalance;

    CDAccount();
    CDAccount(double setBalance, double setInterestRate, int setTerm);

    double getInitialBalance();

    double getInterestRate();

    int getTerm();

    double calculateBalance(double balance, double interestRate, int term);

    void display();

};


#endif //CHAPTER10PRACTICEPROGRAM1_CDACCOUNT_H
