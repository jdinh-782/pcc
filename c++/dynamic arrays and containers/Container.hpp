//
// Name: Johnson Dinh
// SSID: 
// Assignment #: 2
// Submission Date: 3/23/21
//


#ifndef _CONTAINER_HPP
#define _CONTAINER_HPP

#include <iostream>

using namespace std;


template <class T>
class Container
{
public:
    //destructor
    virtual ~Container();

    //create the dynamic array with size s
    virtual bool resize (int s) = 0;

    //checks if the container has no elements
    virtual bool empty() = 0;

    //returns the number of elements in and/or size of the container for an array size and memsize will be the same
    virtual int size() = 0;

    virtual T* begin() = 0;
    virtual T* end() = 0;

    //for a container c, the expression c.front() is equivalent to *c.begin(); undefined if empty()
    virtual T& front() = 0;

    //if size() is 0, data() may or may not return a null pointer
    virtual T* data() = 0;
    virtual const T* data() const = 0;

    //return reference to the requested element
    virtual T& operator [] (int position) = 0;

};


template<class T>
Container<T>::~Container()
= default;


#endif
