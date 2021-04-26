//
// Created by jdinh on 10/10/2020.
//

#include "interface.h"

interface::interface()
{
    max = 0;
    num = 0;
}


interface::interface(int maxInput, int numInput)
{
    max = maxInput;
    num = numInput;
}


void interface::getElements()
{
    cout << "\nhow many numbers: ";
    cin >> max;

    for (int i = 0; i < max; i++)
    {
        cout << "\nnum: ";
        cin >> num;
        s1.insert(num);
    }

    cout << "\n\nenter another set...";
    cout << "\nhow many numbers: ";
    cin >> max;

    for (int i = 0; i < max; i++)
    {
        cout << "\nnum: ";
        cin >> num;
        s2.insert(num);
    }
}


void interface::displaySet()
{
    cout << "\nSet 1: ";
    for (int counter : s1)
    {
        cout << counter << " ";
    }

    cout << "\nSet 2: ";
    for (int counter : s2)
    {
        cout << counter << " ";
    }
}


void interface::createUnion()
{
    merge(s1.begin(), s1.end(),
          s2.begin(), s2.end(),
          inserter(combinedSet, combinedSet.begin()));
}


void interface::displayUnion()
{
    cout << "\nCombined set: ";
    for (int counter : combinedSet)
    {
        cout << counter << " ";
    }
}


void interface::createIntersection()
{
    vector<int> v1(s1.size());
    copy(s1.begin(), s1.end(), v1.begin());

    vector<int> v2(s2.size());
    copy(s2.begin(), s2.end(), v2.begin());

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());


    set_intersection(v1.begin(), v1.end(),
                     v2.begin(), v2.end(),
                     back_inserter(intersectedElements));
}


void interface::displayIntersection()
{
    cout << "\nThe intersected element(s) are: ";
    for (int counter : intersectedElements)
    {
        cout << counter << " ";
    }
}