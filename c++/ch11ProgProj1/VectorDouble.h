//
// Created by jdinh on 10/8/2020.
//

#ifndef CHAPTER11PROGRAMMINGPROJECT1_VECTORDOUBLE_H
#define CHAPTER11PROGRAMMINGPROJECT1_VECTORDOUBLE_H

#include <ostream>

using namespace std;


class VectorDouble
{
private:
    double *elements;
    int maxCount;
    int count;

public:
    VectorDouble();
    VectorDouble(int size);
    VectorDouble(const VectorDouble& v);

    ~VectorDouble();

    void pushBack(double value);

    double valueAt (int num) const;

    void changeValueAt(double newValue, int num);

    int size() const;

    int capacity() const;

    void reserve(int);

    void resize(int);

    void expandCapacity();

    friend ostream& operator <<(ostream& outs, const VectorDouble& v);

    friend bool operator ==(const VectorDouble& v1, const VectorDouble& v2);

    void operator ==(const VectorDouble& v1);
};


#endif //CHAPTER11PROGRAMMINGPROJECT1_VECTORDOUBLE_H
