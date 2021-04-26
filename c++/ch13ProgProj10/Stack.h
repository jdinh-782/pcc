//
// Created by jdinh on 11/7/2020.
//

#ifndef CHAPTER13PROGRAMMINGPROJECT10_STACK_H
#define CHAPTER13PROGRAMMINGPROJECT10_STACK_H

#include "LinkedList.h"


template <class T>
class Stack : public LinkedList<T>
{
private:
    //LinkedList<T>& l;
    T data;

public:
    //Stack();
    //Stack(const Stack& s);
    //~Stack();

    void push(T value);

    bool isEmpty();

    T size();
    T pop();
    T top();
    int seek(int num);
    int reverseSeek (int num);

};

#include "Stack.cpp"

#endif //CHAPTER13PROGRAMMINGPROJECT10_STACK_H
