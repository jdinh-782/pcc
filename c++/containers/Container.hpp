//
// Name : Johnson Dinh
// SSID : 1857773
// Assignment #: 1
// Submission Date : 3/9/21
//

#ifndef _CONTAINER_HPP
#define _CONTAINER_HPP
#include <iostream>
#include <string>

using namespace std;


template <class T, int N>
class Container
{
public:
    Container();
    using value_type = T;
    void add_item(T item);  //output container full, if add_item cannot add (%10 points)
    T get_item(int index);  //throw a string if index out of bounds (%10 points)
    void remove_item(T item);   //remove first occurrence of item (%10 points)
    bool empty();   //check of Container is empty (%5 points)
    void clear();   //clear all contents, assign value_type
    constexpr int size();   //return current number of elements in container
    T* begin();
    T* end();

private:
    int _size = 0;
    T container[N];
}; //Container interface


template <class T, int N>
Container<T, N>::Container()
{
    _size = 0;
}


template <class T, int N>
constexpr int Container<T, N>::size()
{
    return _size;
}


template <class T, int N>
void Container<T, N>::clear()
{
    for (int i = 0; i < _size; i++)
    {
        container[i] = T(); //or value_type();
    }
    _size = 0;
}


template <class T, int N>
T* Container<T, N>::begin()
{
    return _size ? &container[0] : nullptr;
}


template <class T, int N>
T* Container<T, N>::end()
{
    return begin() + _size;

}


//add_item function
template <class T, int N>
void Container<T, N>::add_item(T item)
{
    if (_size >= N)
    {
        cout << "\n Container is full!\n";
        return;
    }
    container[_size] = item;
    _size++;
}


//remove_item function
template <class T, int N>
void Container<T, N>::remove_item(T item)
{
    int index = 0;
    for (int i = 0; i < _size; i++)
    {
        if (container[i] == item)
        {
            index = i;
        }
    }

    _size--;
    for (int j = index; j < _size; j++)
    {
        container[j] = container[j+1];
    }
}


//empty function
template<class T, int N>
bool Container<T, N>::empty()
{
    if (_size <= 0)
    {
        return true;
    }
    return false;
}


//get_item function
template<class T, int N>
T Container<T, N>::get_item(int index)
{
    try
    {
        if (index >= _size)
        {
            throw "\nIndex is out of range!\n";
        }
        return container[index];
    }
    catch (const char* e)
    {
        cout << e;
    }
}


#endif
