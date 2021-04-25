//
// Created by jdinh on 9/21/2020.
//

//Chapter 10 Practice Program #1

#include "CDAccount.h"
#include <iostream>

using namespace std;

CDAccount::CDAccount()
{
    balance = 100.00;
    interestRate = 10.00;
    term = 6;
}


CDAccount::CDAccount(double setBalance, double setInterestRate, int setTerm)
{
    balance = setBalance;
    interestRate = setInterestRate;
    term = setTerm;
}


double CDAccount::getInitialBalance()
{
    do
    {
        cout << "\nEnter account balance: $";
        cin >> balance;
    } while (balance < 0);

    return balance;
}


double CDAccount::getInterestRate()
{
    do
    {
        cout << "\nEnter account interest rate: ";
        cin >> interestRate;
    } while (interestRate < 0);

    return interestRate;
}


int CDAccount::getTerm()
{
    do
    {
        cout << "\nEnter the number of months until maturity (must be 12 or fewer months): ";
        cin >> term;
    } while (term < 1 || term > 12);

    return term;
}


double CDAccount::calculateBalance(double balance, double interestRate, int term)
{
    rateFraction = interestRate / 100.0;

    interest = balance * rateFraction * (term / 12.0);

    totalBalance = balance + interest;

    return totalBalance;
}


void CDAccount::display()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "\nWhen your CD matures in " << term << " months, it will have a balance of $" << totalBalance << endl;
}