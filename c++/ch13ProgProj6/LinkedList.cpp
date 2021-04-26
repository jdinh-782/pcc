//
// Created by jdinh on 11/3/2020.
//

#include "LinkedList.h"

LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
}


LinkedList::LinkedList(const LinkedList& l)
{
    *this = l;
}


LinkedList::~LinkedList()
{
    NodeList::Node* object = head;
    NodeList::Node* prev;

    while (object != nullptr)
    {
        prev = object;
        object = object->next;
        delete prev;
    }
}


NodeList::Node* LinkedList::createNode(int data)
{
    auto* n = new NodeList::Node;
    n->value = data;
    n->next = nullptr;
    n->prev = nullptr;
    return n;
}


NodeList::Node *LinkedList::returnNode(int data)
{
    for (NodeList::Node* object = head; object != nullptr; object = object->next)
    {
        if (object->value == data)
        {
            return object;
        }
    }
    return nullptr;
}


int LinkedList::returnSize()
{
    NodeList::Node* temp = head;
    int size = 0;

    while (temp != nullptr)
    {
        size++;
        temp = temp->next;
    }
    return size;
}


//needs fixing due to memory error
int LinkedList::eliminateSuitors()
{
    int position;
    auto* temp = returnNode(lastValue);
    temp->next = new NodeList::Node;
    temp->next = head;

    auto* tempBefore = new NodeList::Node;
    tempBefore = temp;
    temp = temp->next;

    NodeList::Node* deleteNode;

    if (temp->value == temp->next->value)
    {
        position = temp->value;
        delete temp;
        delete tempBefore;
        return position;
    }

    else
    {
        while (temp->value != temp->next->value)
        {
            for (int i = 0; i < 2; i++)
            {
                temp = temp->next;
                tempBefore = tempBefore->next;
            }
            deleteNode = temp;

            if (temp->value == head->value)
            {
                head = temp->next;
                tempBefore->next = temp->next;
                temp = temp->next;
                delete deleteNode;
            }

            else
            {
                tempBefore->next = temp->next;
                temp = temp->next;
                delete deleteNode;
            }
        }
    }
    position = temp->value;
    delete temp;
    return position;
}


void LinkedList::operator += (int value)
{
    lastValue = value;
    int position = 1;
    auto* n = new NodeList::Node;

    for (int i = 0; i < value; i++)
    {
        n->value = position;

        if (i == 0)
        {
            head = n;
        }

        if (n->value != value)
        {
            n->next = new NodeList::Node;
            n = n->next;
            position++;
        }
    }
}


ostream& operator << (ostream& outs, const LinkedList& l)
{
    for (NodeList::Node* object = l.head; object != nullptr; object = object->next)
    {
        outs.width(5);
        outs << object->value;
    }
    return outs;
}


