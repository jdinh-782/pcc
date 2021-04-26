//Chapter 10 Programming Project #10
#include <iostream>
#include "AccountNumber.h"

using namespace std;


int main()
{
    int* p;

    AccountNumber account;

    AccountNumber(p, 5, 28126);

    if (account.checkAccountNumber())
    {
        cout << "This account number IS valid. ";
    }

    else
    {
        cout << "This account number IS NOT valid. ";
    }


    return 0;
}
