//
// Created by jdinh on 11/7/2020.
//

#ifndef CHAPTER13PROGRAMMINGPROJECT10_STACK_CPP
#define CHAPTER13PROGRAMMINGPROJECT10_STACK_CPP
#include "Stack.h"


//template<class T>
//Stack<T>::Stack() : l(l)
//{
//
//}


template <class T>
bool Stack<T>::isEmpty()
{
    bool temp = LinkedList<T>::empty();
    return temp;
}


template <class T>
T Stack<T>::size()
{
    int num = LinkedList<T>::listSize();
    return num;
}


template <class T>
void Stack<T>::push(T value)
{
    LinkedList<T>::insertEnd(value);
}


template <class T>
T Stack<T>::pop()
{
    if (LinkedList<T>::empty())
    {
        cout << "\nStack is empty!";
        exit(1);
    }

    else
    {
        data = LinkedList<T>::headValue();
        LinkedList<T>::removeHead();
    }
    return data;
}


template <class T>
T Stack<T>::top()
{
    data = LinkedList<T>::headValue();
    return data;
}


template <class T>
int Stack<T>::seek(int num)
{
    return LinkedList<T>::listSeek(num);
}


template <class T>
int Stack<T>::reverseSeek(int num)
{
    return LinkedList<T>::listReverseSeek(num);
}


#endif //CHAPTER13PROGRAMMINGPROJECT10_STACK_CPP