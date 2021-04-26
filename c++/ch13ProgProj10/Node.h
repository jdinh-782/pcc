//
// Created by jdinh on 11/7/2020.
//

#ifndef CHAPTER13PROGRAMMINGPROJECT10_NODE_H
#define CHAPTER13PROGRAMMINGPROJECT10_NODE_H

template <class T>
struct Node
{
    T data;
    Node* next;
    Node* prev;
};
#endif //CHAPTER13PROGRAMMINGPROJECT10_NODE_H
