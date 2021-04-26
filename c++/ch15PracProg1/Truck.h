//
// Created by jdinh on 11/21/2020.
//

#ifndef CHAPTER15PRACTICEPROGRAM1_TRUCK_H
#define CHAPTER15PRACTICEPROGRAM1_TRUCK_H
#include "TransportVehicle.h"


class Truck : public TransportVehicle
{
private:
    double truckKilometers;

protected:
    double maxTruckCapacity;

public:
    Truck();
    Truck(double truckRegistrationNumber, double truckAge, double truckMaxCapacityInput, int truckKilometersInput);
};


#endif //CHAPTER15PRACTICEPROGRAM1_TRUCK_H
