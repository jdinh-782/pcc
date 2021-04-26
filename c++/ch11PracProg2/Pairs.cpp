//
// Created by jdinh on 10/8/2020.
//

#include "Pairs.h"

Pairs::Pairs()
{
    f = 0;
    s = 0;
}


Pairs::Pairs(int first, int second) : f(first), s(second)
{

}


int Pairs::accessFirst()
{
    return f;
}


int Pairs::accessSecond()
{
    return s;
}


Pairs operator +(const Pairs& first, const Pairs& second)
{
    return Pairs(first.f + second.s, first.s + second.f);
}


Pairs operator *(const Pairs& first, int num)
{
    return Pairs(first.f * num, first.s * num);
}


istream& operator >>(istream& ins, Pairs& second)
{
    char ch;
    ins >> ch;
    ins >> second.f;
    ins >> ch;
    ins >> second.s;
    ins >> ch;

    return ins;
}


ostream& operator <<(ostream& outs, const Pairs& second)
{
    outs << '(';
    outs << second.f;
    outs << ',';
    outs << second.s;
    outs << ')';

    return outs;
}

