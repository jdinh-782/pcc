//
// Created by jdinh on 11/21/2020.
//

#ifndef CHAPTER15PRACTICEPROGRAM1_PLANE_H
#define CHAPTER15PRACTICEPROGRAM1_PLANE_H
#include "TransportVehicle.h"


class Plane : public TransportVehicle
{
private:
    int planeHours;

protected:
    double planeMaxCapacity;

public:
    Plane();
    Plane(double planeRegistrationNumber, double planeAge, double planeMaxCapacityInput, int planeHoursInput);

};


#endif //CHAPTER15PRACTICEPROGRAM1_PLANE_H
