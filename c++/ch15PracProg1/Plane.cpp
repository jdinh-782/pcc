//
// Created by jdinh on 11/21/2020.
//

#include "Plane.h"

Plane::Plane() : TransportVehicle()
{
    planeHours = 10;
    planeMaxCapacity = 500.00;
}


Plane::Plane(double planeRegistrationNumber, double planeAge, double planeMaxCapacityInput, int planeHoursInput) :
TransportVehicle(planeRegistrationNumber, planeAge, planeMaxCapacityInput)
{
    planeMaxCapacity = planeMaxCapacityInput;
    planeHours = planeHoursInput;
}
