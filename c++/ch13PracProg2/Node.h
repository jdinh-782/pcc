//
// Created by jdinh on 11/2/2020.
//

#ifndef CHAPTER13PRACTICEPROGRAM2_NODE_H
#define CHAPTER13PRACTICEPROGRAM2_NODE_H

#include <iostream>

namespace linkedlistofclasses
{
    class Node
    {
    private:
        int data;
        Node* link;

    public:
        Node();
        Node(int value, Node* next);
        ~Node();

        int getData() const;

        Node* getLink() const;

        void setData(int value);

        void setLink(Node* next);
    };

    typedef Node* NodePtr;
}
#endif //CHAPTER13PRACTICEPROGRAM2_NODE_H
