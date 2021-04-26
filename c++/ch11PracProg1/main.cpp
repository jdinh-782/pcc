//Chapter 11 Practice Program 1


#include "Money.h"

int main()
{
    Money m1;
    m1.amount = 100.10;

    Money temp;

    temp = m1.percent(10);
    cout << temp.amount;
    return 0;
}
