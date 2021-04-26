//Chapter 11 Programming Project 3


#include "DecimalBookInfo.h"

int main()
{
    DecimalBookInfo d1("Percy Jackson", 0.6);
    DecimalBookInfo d2("Harry Potter", 0.4);

    if (d1 < d2)
    {
        cout << d1.bookName << ", " << d1.getDecimalClassificationNumber() << endl;
        cout << d2.bookName << ", " << d2.getDecimalClassificationNumber() << endl;
    }

    else
    {
        cout << d2.bookName << ", " << d2.getDecimalClassificationNumber() << endl;
        cout << d1.bookName << ", " << d1.getDecimalClassificationNumber() << endl;
    }

    return 0;
}
