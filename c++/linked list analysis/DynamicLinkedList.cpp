//
// Created by jdinh on 11/5/2020.
//

#include "DynamicLinkedList.h"

DynamicLinkedList::DynamicLinkedList()
{
    myVector.clear();
}


DynamicLinkedList::DynamicLinkedList(int data)
{
    for (int i = 0; i < data; i++)
    {
        myVector.push_back(data);
    }
}


void DynamicLinkedList::insertBeginning(int data)
{
    myVector.insert(myVector.begin(), data);
}


void DynamicLinkedList::insertEnd(int data)
{
    myVector.push_back(data);
}


void DynamicLinkedList::insertAt(int pos, int data)
{
    myVector.insert(myVector.begin() + pos, data);
}


void DynamicLinkedList::remove(int pos)
{
    myVector.erase(myVector.begin() + pos);
}


ostream& operator << (ostream& outs, const DynamicLinkedList& d)
{
    for (int x : d.myVector)
    {
        outs << x << " ";
    }
    return outs;
}