//
// Created by jdinh on 11/7/2020.
//

#ifndef CHAPTER13PROGRAMMINGPROJECT10_LINKEDLIST_H
#define CHAPTER13PROGRAMMINGPROJECT10_LINKEDLIST_H

#include <iostream>
#include "Node.h"
#include <ctime>

using namespace std;


template <class T>
class LinkedList
{
private:
    Node<T>* head;
    Node<T>* tail;
    static Node<T>* createNode(T item);
    int size = 0;

public:
    LinkedList();
    LinkedList(const LinkedList<T>& list);
    ~LinkedList();

    Node<T>* returnNode(T value);

    void insert(int value);
    void insertEnd(T value);
    void insertBeginning(T value);
    void insertBefore(T newValue, T valueBefore);
    void insertAfter(T newValue, T valueAfter);

    bool insertFirst(Node<T>* node);
    bool empty();
    T listSize();
    T headValue();
    T tailValue();
    T listSeek(int value);
    T listReverseSeek(int value);

    void remove(T value);
    void removeTail();
    void removeHead();
    void clear();
    int returnValue(int value);


    void operator += (T value);

    template <class S>
    friend ostream& operator << (ostream& outs, const LinkedList<S>& list);
};

#include "LinkedList.cpp"

#endif //CHAPTER13PROGRAMMINGPROJECT10_LINKEDLIST_H
