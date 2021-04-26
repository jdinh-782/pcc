//
// Created by jdinh on 10/10/2020.
//

#ifndef CHAPTER12PROGRAMMINGPROJECT1_INTERFACE_H
#define CHAPTER12PROGRAMMINGPROJECT1_INTERFACE_H

#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

class interface
{
private:
    int max, num;

    set <int, greater<> > s1 {};
    set <int, greater<> > s2 {};
    set <int, greater<> > combinedSet {};
    vector <int> intersectedElements;

public:
    interface();
    interface(int maxInput, int numInput);

    void getElements();

    void displaySet();

    void createUnion();

    void displayUnion();

    void createIntersection();

    void displayIntersection();

};


#endif //CHAPTER12PROGRAMMINGPROJECT1_INTERFACE_H
