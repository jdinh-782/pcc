//
// Created by jdinh on 10/8/2020.
//

#ifndef CHAPTER11PRACTICEPROGRAM2_PAIRS_H
#define CHAPTER11PRACTICEPROGRAM2_PAIRS_H

#include <iostream>

using namespace std;

class Pairs
{
private:
    int f, s;

public:
    Pairs();
    Pairs(int first, int second);
    Pairs(int first);

    int accessFirst();
    int accessSecond();

    friend Pairs operator +(const Pairs& first, const Pairs& second);
    friend Pairs operator *(const Pairs& first, int num);
    friend istream& operator >>(istream& ins, Pairs& second);
    friend ostream& operator <<(ostream& outs, const Pairs& second);


};


#endif //CHAPTER11PRACTICEPROGRAM2_PAIRS_H
