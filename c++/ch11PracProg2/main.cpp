//Chapter 11 Practice Program 2


#include "Pairs.h"

int main()
{
    Pairs a(8,5);
    Pairs b(2,3);
    Pairs c(4,8);

    cout << "(" << c.accessFirst() << c.accessSecond() << ")" << endl << endl;

    cout << "a" << a << endl;
    cout << "b" << b << endl;
    cout << "c" << c << endl << endl;

    cout << "a + c: " << a + c << endl;
    cout << "b * 2: " << b * 2 << endl;

    return 0;
}
