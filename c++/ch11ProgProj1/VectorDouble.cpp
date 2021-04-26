//
// Created by jdinh on 10/8/2020.
//

#include "VectorDouble.h"

VectorDouble::VectorDouble()
{
    elements = new double[maxCount];

    count = 0;
}


VectorDouble::VectorDouble(int size)
{
    maxCount = size;
    elements = new double[maxCount];

    count = 0;
}


VectorDouble::VectorDouble(const VectorDouble& v)
{
    double* temp = new double[v.count];
    count = v.size();

    for(int i = 0; i < v.size(); i++)
    {
        temp[i] = v.valueAt(i);
    }

    elements = temp;
}


VectorDouble::~VectorDouble()
{
    delete[] elements;
}


void VectorDouble::operator==(const VectorDouble& v1)
{
    double* temp = new double[v1.count];

    for (int i = 0; i < v1.size(); i++)
    {
        temp[i] = v1.valueAt(i);
    }

    count = v1.size();
    elements = temp;
}


bool operator ==(const VectorDouble& v1, const VectorDouble& v2)
{
    bool equal = true;

    if (v1.size() != v2.size())
    {
        equal = false;
    }

    else
    {
        for (int i = 0; i < v1.size(); i++)
        {
            if (v1.valueAt(i) != v2.valueAt(2))
            {
                equal = false;
            }
        }
    }
    return equal;
}


void VectorDouble::pushBack(double value)
{
    if (count == maxCount)
    {
        expandCapacity();

        elements[count] = value;
        count++;
    }
}


int VectorDouble::capacity() const
{
    return maxCount;
}


void VectorDouble::expandCapacity()
{
    maxCount = 2 * maxCount;
    double* newElements = new double[maxCount];

    for (int i = 0; i < count; i++)
    {
        newElements[i] = elements[i];
    }

    delete[] elements;

    elements = newElements;
}


int VectorDouble::size() const
{
    return count;
}


double VectorDouble::valueAt(int num) const
{
    if (num < 0 || num > count)
    {
        return 0;
    }

    else
    {
        return elements[num];
    }
}


ostream& operator <<(ostream& outs, const VectorDouble& v)
{
    for (int i = 0; i < v.count; i++)
    {
        outs << v.elements[i] << endl;
        return outs;
    }
}