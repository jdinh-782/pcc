//
// Created by jdinh on 10/8/2020.
//

#ifndef CHAPTER11PRACTICEPROGRAM3_DEGREEANGLE_H
#define CHAPTER11PRACTICEPROGRAM3_DEGREEANGLE_H

#include <iostream>
#include <algorithm>

using namespace std;


class DegreeAngle
{
private:
    double angleArray[360];

public:
    DegreeAngle();
    DegreeAngle(int numInput, int angleInput2);

    int angle1, angle2;
    double sumAngle, differenceAngle;

    void checkForAngle();

    double operator +(const DegreeAngle& add);
    double operator -(const DegreeAngle& subtract);
    friend istream& operator >>(istream& ins, DegreeAngle& num);
    friend ostream& operator <<(ostream& outs, const DegreeAngle& num);


};


#endif //CHAPTER11PRACTICEPROGRAM3_DEGREEANGLE_H
