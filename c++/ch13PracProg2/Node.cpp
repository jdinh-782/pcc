//
// Created by jdinh on 11/2/2020.
//

#include "Node.h"

namespace linkedlistofclasses
{
    Node::Node() : data(0), link(nullptr)
    {
        //empty
    }

    Node::Node(int value, Node* next) : data(value), link(next)
    {
        //empty
    }

    Node::~Node()
    {
        NodePtr head, object;
        head = new Node(0, nullptr);

        object = head;

        while (object != nullptr)
        {
            NodePtr nodeToDelete = object;
            object = object->getLink();
            delete nodeToDelete;
        }
        //std::cout << std::endl << "Destructor is executed! ";
    }

    int Node::getData() const
    {
        return data;
    }

    Node* Node::getLink() const
    {
        return link;
    }

    void Node::setData(int value)
    {
        data = value;
    }

    void Node::setLink(Node *next)
    {
        link = next;
    }


}