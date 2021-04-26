//Chapter 13 Programming Project 6


#include "LinkedList.h"

int main()
{
    LinkedList list;

    for (int i = 1; i < 21; i++)
    {
        list += i;
    }

    cout << list << endl;

    cout << "Lucky Suitor: " << list.eliminateSuitors() << endl;

    return 0;
}
