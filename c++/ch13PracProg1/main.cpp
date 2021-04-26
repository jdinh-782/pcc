//Chapter 13 Practice Program 1


#include <iostream>
#include <string>

using namespace std;

struct Node
{
    string name;
    Node* link;
    Node* next;
};

typedef Node* NodePtr;


//part a
void display(Node* head)
{
    while (head != nullptr)
    {
        cout << head->name << " ";
        head = head->link;
    }
}


//part c
void deleteNode(Node* head)
{
    NodePtr prev = nullptr;
    while (head != nullptr)
    {
        if (head->name == "Joules")
        {
            prev->link = head->link;
            delete head;
            break;
        }
        prev = head;
        head = head->link;
    }
}


//part d
void deleteLinkedList(NodePtr head)
{
    NodePtr temp;
    while (head != nullptr)
    {
        temp = head;
        head = head->next;
        //head = head->link;
        delete temp;
    }
}


int main()
{
    NodePtr listPtr, tempPtr;

    listPtr = new Node;
    listPtr->name = "Emily";

    tempPtr = new Node;
    tempPtr->name = "James";
    listPtr->link = tempPtr;

    tempPtr->link = new Node;
    tempPtr = tempPtr->link;
    tempPtr->name = "Joules";
    tempPtr->link = nullptr;

    display(listPtr);

    //part b
    tempPtr->link = new Node;
    tempPtr= tempPtr->link;
    tempPtr->name = "Joshua";
    tempPtr->link = nullptr;

    cout << endl;
    display(listPtr);

    deleteNode(listPtr);

    cout << endl;
    display(listPtr);

    deleteLinkedList(listPtr);

    cout << endl;
    display(listPtr);

    return 0;
}
