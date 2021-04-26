//
// Created by jdinh on 11/3/2020.
//

#ifndef CHAPTER13PROGRAMMINGPROJECT6_LINKEDLIST_H
#define CHAPTER13PROGRAMMINGPROJECT6_LINKEDLIST_H

#include <iostream>
#include "Node.h"

using namespace std;

class LinkedList
{
private:
    NodeList::Node* head;
    NodeList::Node* tail;
    NodeList::Node* createNode(int data);
    int lastValue;

public:
    LinkedList();
    LinkedList(const LinkedList& l);
    ~LinkedList();

    NodeList::Node* returnNode(int data);

    int returnSize();
    int eliminateSuitors();
    void operator += (int value);

    friend ostream& operator << (ostream& outs, const LinkedList& l);
};


#endif //CHAPTER13PROGRAMMINGPROJECT6_LINKEDLIST_H
