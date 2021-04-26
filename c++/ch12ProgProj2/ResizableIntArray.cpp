//
// Created by jdinh on 10/10/2020.
//

#include "ResizableIntArray.h"

ResizableIntArray::ResizableIntArray()
{
    v = {1, 2, 3, 4, 5};
    initialSize = 5;
}


ResizableIntArray::ResizableIntArray(int initialSizeInput)
{
    initialSize = initialSizeInput;
}


vector<int> ResizableIntArray::copyVector(const vector<int> &vec)
{
    vector <int> newVector(vec);
    return newVector;
}


void ResizableIntArray::resize()
{
    cout << "\nEnter a number to resize your vector: ";
    cin >> newSize;

    assert(("The new size has to be greater than 0! ", newSize > 0));

    v.resize(newSize);
}


void ResizableIntArray::setElement(int index, int value)
{
    value = newSize;

    assert(("The index has to be greater than or equal to 0! ", index >= 0));

    cout << "\nThe number at index " << index << " is ";
    for (int i = 0; i < value; i++)
    {
        if (index == i)
        {
            cout << v.at(i);
            exit(1);
        }
    }
}


ostream& operator << (ostream& outs, ResizableIntArray& r)
{
    outs << "Your vector is: [ ";
    for (int counter : r.v)
    {
        outs << counter << " ";
    }
    outs << "]";

    return outs;
}


void ResizableIntArray::displayCopiedVector()
{
    vector <int> v2 = copyVector(v);

    for (int counter : v2)
    {
        cout << counter << " ";
    }
}


ResizableIntArray::~ResizableIntArray()
{
    cout << "\nFreeing memory! ";

    v.clear();
}