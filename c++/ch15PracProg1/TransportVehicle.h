//
// Created by jdinh on 11/21/2020.
//

#ifndef CHAPTER15PRACTICEPROGRAM1_TRANSPORTVEHICLE_H
#define CHAPTER15PRACTICEPROGRAM1_TRANSPORTVEHICLE_H
#include <iostream>
#include <vector>
#include "FreightContainer.h"


using namespace std;


class TransportVehicle
{
private:
    double registrationNumber, age, maxCapacity;
    vector<FreightContainer*> v;

public:
    TransportVehicle();
    TransportVehicle(double registrationNumberInput, double ageInput, double maxCapacityInput);

    bool addFreightContainer(FreightContainer* object);

};


#endif //CHAPTER15PRACTICEPROGRAM1_TRANSPORTVEHICLE_H
