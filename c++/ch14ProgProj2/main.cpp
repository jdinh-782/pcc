//Chapter 14 Programming Project 2


#include <iostream>

using namespace std;


struct TreeNode
{
    int data;
    TreeNode* leftLink; //prev
    TreeNode* rightLink; //next
};


class Tree
{
private:
    TreeNode* head;
    TreeNode* tail;

    static TreeNode* createNode(int item)
    {
        TreeNode* temp = new TreeNode;
        temp->data = item;
        temp->rightLink = nullptr;
        temp->leftLink = nullptr;
    }

public:
    Tree()
    {
        head = nullptr;
        tail = nullptr;
    }

    void headInsert(int item)
    {
        TreeNode* temp = createNode(item);
        if (head == nullptr)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            temp->rightLink = head;
            head->leftLink = temp;
            temp->leftLink = nullptr;
            head = temp;
            return headInsert(item-1);
        }
    }

    friend ostream& operator << (ostream& outs, const Tree& t)
    {
        for (TreeNode* object = t.head; object != nullptr; object = object->rightLink)
        {
            outs.width(3);
            outs << object->data;
        }
        return outs;
    }

};


int main()
{
    Tree t;

    t.headInsert(5);

    cout << t;
    return 0;
}
