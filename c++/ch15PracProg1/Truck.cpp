//
// Created by jdinh on 11/21/2020.
//

#include "Truck.h"

Truck::Truck() : TransportVehicle()
{
    truckKilometers = 25.00;
    maxTruckCapacity = 150.00;
}


Truck::Truck(double truckRegistrationNumber, double truckAge, double truckMaxCapacityInput, int truckKilometersInput) :
TransportVehicle(truckRegistrationNumber, truckAge, truckMaxCapacityInput)
{
    maxTruckCapacity = truckMaxCapacityInput;
    truckKilometers = truckKilometersInput;
}


