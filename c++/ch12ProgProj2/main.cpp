//Chapter 12 Programming Project 2



#include "ResizableIntArray.h"

int main()
{
    int index;

    ResizableIntArray r;

    cout << r;

    r.resize();

    cout << endl << r;

    cout << "\nEnter an index: ";
    cin >> index;

    r.setElement(index, 0);

    cout << "\nHere ia copy of your vector: ";

    r.displayCopiedVector();

    r.~ResizableIntArray();



    return 0;
}
