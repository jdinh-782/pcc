#include <iostream>
#include "Timer.h"

using namespace std;


int fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}


void loop(int n)
{
    int a = 0;
    int b = 1;
    int c;

    for (int i = 0; i < n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    cout << a << endl;
    //1, 1, 2, 3, 5, 8, 13, 21
}


int main()
{
    Timer t;
    t.start();
    for (int i = 1; i <= 21; i++) //after the 20th term, the fibonacci function starts crashing
    {
        loop(i);
        //cout << fibonacci(i) << endl;
    }
    t.end();
    cout << "\nIt took " << t.getDuration() << " seconds to run the function n times" << endl;
    return 0;
}
