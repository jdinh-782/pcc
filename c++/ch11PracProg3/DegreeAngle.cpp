//
// Created by jdinh on 10/8/2020.
//

#include "DegreeAngle.h"

DegreeAngle::DegreeAngle()
{
    angle1 = 0;
    angle2 = 0;
}


DegreeAngle::DegreeAngle(int angleInput1, int angleInput2)
{
    angle1 = angleInput1;
    angle2 = angleInput2;
}


void DegreeAngle::checkForAngle()
{
    for (int i = 0; i <= 359; i++)
    {
        angleArray[i] = i;
        // cout << angleArray[i];
    }
}


double DegreeAngle::operator +(const DegreeAngle& add)
{
    sumAngle = add.angle1 + add.angle2;
    return sumAngle;
}


double DegreeAngle::operator -(const DegreeAngle& subtract)
{
    differenceAngle = subtract.angle1 - subtract.angle2;
    return differenceAngle;
}


istream& operator >>(istream& ins, DegreeAngle& num)
{
    cout << "enter angle 1: ";
    ins >> num.angle1;

    cout << "\nenter angle 2: ";
    ins >> num.angle2;

    num.checkForAngle();

    num.angle1 + num.angle2;
    num.angle1 - num.angle2;

    return ins;
}


ostream& operator <<(ostream& outs, const DegreeAngle& num)
{
    outs << "\nThe sum of the two angles is " << num.sumAngle << ".";
    outs << "\nThe difference of the two angles is " << num.differenceAngle << ".";

    return outs;
}