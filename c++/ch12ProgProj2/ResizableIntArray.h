//
// Created by jdinh on 10/10/2020.
//

#ifndef CHAPTER12PROGRAMMINGPROJECT2_RESIZABLEINTARRAY_H
#define CHAPTER12PROGRAMMINGPROJECT2_RESIZABLEINTARRAY_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class ResizableIntArray
{
private:
    vector <int> v;
    int initialSize, newSize;

public:
    ResizableIntArray();
    ResizableIntArray(int initialSizeInput);

    vector <int> copyVector(vector<int> const& vec);

    ~ResizableIntArray();

    void resize();

    void setElement(int index, int value);

    void displayCopiedVector();

    friend ostream& operator << (ostream& outs, ResizableIntArray& r);
};


#endif //CHAPTER12PROGRAMMINGPROJECT2_RESIZABLEINTARRAY_H
