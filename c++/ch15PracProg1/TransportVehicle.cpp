//
// Created by jdinh on 11/21/2020.
//

#include "TransportVehicle.h"

TransportVehicle::TransportVehicle()
{
    registrationNumber = 12345;
    age = 50;
    maxCapacity = 500;
}


TransportVehicle::TransportVehicle(double registrationNumberInput, double ageInput, double maxCapacityInput)
{
    registrationNumber = registrationNumberInput;
    age = ageInput;
    maxCapacity = maxCapacityInput;
}


bool TransportVehicle::addFreightContainer(FreightContainer* object)
{
    if (object->getMaxCapacity() > maxCapacity)
    {
        return false;
    }
    v.push_back(object);
    return true;
}
