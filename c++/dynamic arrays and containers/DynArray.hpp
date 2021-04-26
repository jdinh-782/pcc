//
// Name: Johnson Dinh
// SSID: 
// Assignment #: 2
// Submission Date: 3/23/21
//

#ifndef _DYNARRAY_HPP
#define _DYNARRAY_HPP

#include "Container.hpp"


template <class T>
class DynArray : public Container<T>
{
public:
    DynArray<T>() : memsize(0), _data(nullptr)
    {

    }

    DynArray<T>(int size, initializer_list<T> il);

    DynArray<T>(const DynArray<T>& arr);

    virtual ~DynArray<T>();

    //TODO A2: override all container virtual functions
    bool resize(int s);
    bool empty();
    int size();
    T* begin();
    T* end();
    T& front();
    T& back();
    T& at(int position);
    T* data();
    const T* data() const;
    T& operator [] (int position);


private:
    int memsize = 0;
    T* _data = nullptr;

};


template<class T>
DynArray<T>::DynArray(int size, initializer_list<T> il)
{
    _data = new T[size];
    for (auto item : il)
    {
        _data[memsize] = item;
        memsize++;
    }
}


template<class T>
DynArray<T>::DynArray(const DynArray<T>& arr)
{
    _data = new T[arr.memsize];
    for (auto item : arr)
    {
        _data[memsize] = item;
        memsize++;
    }
}


template<class T>
DynArray<T>::~DynArray()
{
    delete [] _data;
}


template<class T>
bool DynArray<T>::resize(int s)
{
    memsize = s;
    _data = new T[memsize];

    //check if there is no first data
    if (_data == nullptr)
    {
        return false;
    }
    return true;
}


template<class T>
bool DynArray<T>::empty()
{
    if (memsize == 0)
    {
        return true;
    }
    return false;
}


template<class T>
int DynArray<T>::size()
{
    return memsize;
}


template<class T>
T* DynArray<T>::begin()
{
    if (empty())
    {
        return nullptr;
    }
    return &_data[0];
}


template<class T>
T* DynArray<T>::end()
{
    return begin() + memsize;
}


template<class T>
T& DynArray<T>::front()
{
    return *begin();
}


template<class T>
T& DynArray<T>::back()
{
    return *prev(end());
}


template<class T>
T& DynArray<T>::at(int position)
{
    try
    {
        if (position >= memsize || position < 0)
        {
            throw "\nIndex is out of range!\n";
        }
        return _data[position];
    }
    catch (const char* e)
    {
        cout << e;
    }
}


template<class T>
T* DynArray<T>::data()
{
    if (size() == 0)
    {
        return nullptr;
    }
    return _data;
}


template<class T>
const T* DynArray<T>::data() const
{
    return _data;
}


template<class T>
T& DynArray<T>::operator [] (int position)
{
    return _data[position];
}


#endif
