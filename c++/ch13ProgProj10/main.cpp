//Chapter 13 Programming Project 10


#include "Stack.h"

int main()
{
    Stack<int> primary;
    Stack<int> lower;
    Stack<int> higher;

    srand(time(nullptr));

    cout << "Primary Stack: ";
    for (int i = 0; i < 10; i++)
    {
        primary.push(rand() & 50 + 10);
        cout.width(3);
        cout << primary.seek(i) << " ";
    }

    lower.push(primary.pop());

    cout << "\nLower Stack:   ";
    for (int i = 0; i < 9; i++)
    {
        int num1 = primary.pop(); //next number from primary
        int num2 = lower.seek(num1); //previous number from lower

        if (num1 < num2)
        {
            lower.push(num1);
        }

        else
        {
            higher.push(num1);
        }
    }

    for (int i = 0; i < lower.size(); i++)
    {
        cout.width(3);
        cout << lower.seek(i) << " ";
    }

    cout << "\nHigher Stack:  ";
    for (int i = 0; i < higher.size(); i++)
    {
        cout.width(3);
        cout << higher.seek(i) << " ";
    }

    primary.clear();

    if (primary.isEmpty())
    {
        cout << "\n\nPrimary Stack is empty!\n";
    }

    else
    {
        cout << "\n\nPrimary Stack is not empty!\n";
    }

    cout << "\nUpdated Primary Stack: ";
    for (int i = 0; i < lower.size(); i++)
    {
        primary.push(lower.pop());
        cout.width(3);
        cout << primary.seek(i) << " ";
    }

    for (int i = 0; i < higher.size(); i++)
    {
        int num1 = higher.pop();
        int num2 = primary.top();

        if (num1 > num2)
        {
            primary.push(num1);
        }

        else
        {
            lower.push(num1);
        }
    }

    cout << "\nUpdated Lower Stack:   ";
    for (int i = 0; i < lower.size(); i++)
    {
        cout.width(3);
        cout << lower.seek(i) << " ";
    }

    cout << "\nFinished Primary Stack:  ";
    for (int i = 0; i < primary.size(); i++)
    {
        cout.width(3);
        cout << primary.seek(i) << " ";
    }

    return 0;
}
