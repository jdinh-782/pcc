//Chapter 13 Practice Program 2


#include "Node.h"

using namespace std;
using namespace linkedlistofclasses;


void headInsert(NodePtr& head, int theNumber)
{
    NodePtr tempPtr;

    tempPtr = new Node(theNumber, head);
    head = tempPtr;
}


int main()
{
    NodePtr head, object;

    head = new Node(0, nullptr);

    for (int i = 1; i < 5; i++)
    {
        headInsert(head, i);
    }

    object = head;

    while (object != nullptr)
    {
        cout << object->getData() << endl;
        object = object->getLink();
    }


    return 0;
}
