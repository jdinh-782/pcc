//
// Created by jdinh on 11/5/2020.
//

#ifndef LINKED_LIST_ANALYSIS_DYNAMICLINKEDLIST_H
#define LINKED_LIST_ANALYSIS_DYNAMICLINKEDLIST_H

#include <iostream>
#include <vector>

using namespace std;

class DynamicLinkedList
{
private:
    vector<int> myVector;

public:
    DynamicLinkedList();
    DynamicLinkedList(int data);

    void insertBeginning(int data);
    void insertEnd(int data);
    void insertAt(int pos, int data);
    void remove(int pos);

    friend ostream& operator << (ostream& outs, const DynamicLinkedList& d);
};


#endif //LINKED_LIST_ANALYSIS_DYNAMICLINKEDLIST_H
