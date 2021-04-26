//Chapter 14 Programming Project 1


#include <iostream>

using namespace std;


struct Node
{
    int data;
    Node* next;
    Node* prev;
};

class LinkedList
{
private:
    Node* tail;
    static Node* createNode(int item)
    {
        Node* temp = new Node;
        temp->data = item;
        temp->next = nullptr;
        temp->prev = nullptr;
        return temp;
    }

public:
    Node* head;
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void operator += (const int item)
    {
        Node* temp = createNode(item);
        if (head == nullptr)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }
    }

    int listSize(Node* object)
    {
        if (object == nullptr)
        {
            return 0;
        }

        else
        {
            return 1 + listSize(object->next);
        }
    }

    friend ostream& operator << (ostream& outs, const LinkedList& l)
    {
        for (Node* object = l.head; object != nullptr; object = object->next)
        {
            outs.width(5);
            outs << object->data;
        }
        return outs;
    }
};


int main()
{
    LinkedList l;

    for (int i = 0; i < 5; i++)
    {
        l += i;
    }
    cout << l << endl;

    cout << l.listSize(l.head);

    return 0;
}
