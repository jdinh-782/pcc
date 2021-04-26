//
// Created by jdinh on 11/7/2020.
//

#ifndef CHAPTER13PROGRAMMINGPROJECT10_LINKEDLIST_CPP
#define CHAPTER13PROGRAMMINGPROJECT10_LINKEDLIST_CPP
#include "LinkedList.h"


template <class T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
}


template <class T>
LinkedList<T>::LinkedList(const LinkedList& list)
{
    *this = list;
}


template <class T>
LinkedList<T>::~LinkedList()
{
    clear();
}


template <class T>
Node<T>* LinkedList<T>::createNode(T item)
{
    auto* n = new Node<T>;
    n->data = item;
    n->next = nullptr;
    n->prev = nullptr;
    return n;
}


template <class T>
bool LinkedList<T>::insertFirst(Node<T>* node)
{
    if (head == nullptr)
    {
        head = node;
        tail = node;
        size++;
        return true;
    }
    return false;
}


template <class T>
void LinkedList<T>::insert(int value)
{
    Node<T>* temp = createNode(value);

    if (head == nullptr)
    {
        head = temp;
        tail = temp;
    }

    else
    {
        tail->next = temp;
        tail = temp;
    }
}


template <class T>
void LinkedList<T>::insertEnd(T value)
{
    Node<T>* temp = createNode(value);

    if(!insertFirst(temp))
    {
        tail->next = temp;
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
        size++;
    }
}


template <class T>
void LinkedList<T>::insertBeginning(T value)
{
    Node<T>* temp = createNode(value);
    if(!insertFirst(temp))
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
        size++;
    }
}


template <class T>
void LinkedList<T>::operator += (T value)
{
    insertEnd(value);
}


template <class T>
void LinkedList<T>::insertBefore(T newValue, T valueBefore)
{
    Node<T>* userTemp = createNode(newValue);
    Node<T>* node = returnNode(valueBefore);

    if (node != nullptr)
    {
        if (head == tail || node == head)
        {
            insertBeginning(newValue);
        }

        else
        {
            userTemp->next = node;
            userTemp->prev = node->prev;
            node->prev->next = userTemp;
            node->prev = userTemp;
            size++;
        }
    }
}


template <class T>
void LinkedList<T>::insertAfter(T newValue, T valueAfter)
{
    Node<T>* userTemp = createNode(newValue);
    Node<T>* previousTemp = returnNode(valueAfter);

    userTemp->next = previousTemp->next;
    previousTemp->next = userTemp;
    userTemp->prev = previousTemp;
    size++;
}


template <class T>
Node<T>* LinkedList<T>::returnNode(T value)
{
    for (Node<T>* object = head; object != nullptr; object = object->next)
    {
        if (object->data == value)
        {
            return object;
        }
    }
    return nullptr;
}


template <class T>
T LinkedList<T>::listSize()
{
    int count = 0;
    Node<T>* temp = head;

    while (temp != nullptr)
    {
        count++;
        size++;
        temp = temp->next;
    }
    return count;
}


template <class T>
bool LinkedList<T>::empty()
{
    if (head == nullptr && tail == nullptr)
    {
        return true;
    }
    return false;
}


template <class T>
void LinkedList<T>::remove(T value)
{
    if (returnNode(value) == nullptr)
    {
        cout << "Node value was not found!\n";
        return;
    }

    Node<T>* deleteNode = returnNode(value);

    if (head == nullptr)
    {
        cout << "\nList is empty! ";
    }

    else if (head->data == deleteNode->data)
    {
        if (head->next == nullptr)
        {
            head = nullptr;
            delete deleteNode;
        }
        else
        {
            head = deleteNode->next;
            head->prev = nullptr;
            delete deleteNode;
        }
    }

    else if (tail->data == deleteNode->data)
    {
        tail = deleteNode->prev;
        tail->prev = deleteNode->prev->prev;
        tail->next = nullptr;
        delete deleteNode;
    }

    else
    {
        deleteNode->prev->next = deleteNode->next;
        deleteNode->next->prev = deleteNode->prev;
        delete deleteNode;
    }
}


template <class T>
void LinkedList<T>::removeHead()
{
    remove(head->data);
}


template <class T>
void LinkedList<T>::removeTail()
{
    remove(tail->data);
}


template <class T>
void LinkedList<T>::clear()
{
    Node<T>* object = head;
    Node<T>* previous;

    while (object != nullptr)
    {
        previous = object;
        object = object->next;
        delete previous;
        size--;
    }
    head = nullptr;
    tail = nullptr;
}


template <class T>
T LinkedList<T>::headValue()
{
    return head->data;
}


template <class T>
T LinkedList<T>::tailValue()
{
    return tail->data;
}


template <class T>
T LinkedList<T>::listSeek(int value)
{
    Node<T>* object = head;
    int counter = 0;

    while (object != nullptr && counter < value)
    {
        object = object->next;
        counter++;
    }

    if (object != nullptr)
    {
        return object->data;
    }

    else if (tail != nullptr)
    {
        return tail->data;
    }
    return T();
}


template <class T>
T LinkedList<T>::listReverseSeek(int value)
{
    Node<T>* object = tail;
    int counter = 0;

    while (object != nullptr && counter < value)
    {
        object = object->prev;
        counter++;
    }

    if (object != nullptr)
    {
        return object->data;
    }

    else
    {
        return head->data;
    }
}


template <class T>
int LinkedList<T>::returnValue(int value)
{
    for (Node<T>* object = head; object != nullptr; object = object->next)
    {
        if (object->data == value)
        {
            return object->data;
        }
    }
    return -1;
}


template <class S>
ostream& operator << (ostream& outs, const LinkedList<S>& list)
{
    for (Node<S>* object = list.head; object != nullptr; object = object->next)
    {
        outs.width(5);
        outs << object->data;
    }
    return outs;
}


#endif //CHAPTER13PROGRAMMINGPROJECT10_LINKEDLIST_CPP








