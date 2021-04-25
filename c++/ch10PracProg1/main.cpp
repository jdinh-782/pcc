//Chapter 10 Practice Program #1
#include "CDAccount.h"

int main()
{
    CDAccount account;
    double balance, interestRate;
    int term;

    balance = account.getInitialBalance();

    interestRate = account.getInterestRate();

    term = account.getTerm();

    account.calculateBalance(balance, interestRate, term);

    account.display();

    return 0;
}
