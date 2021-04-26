//
// Created by jdinh on 11/21/2020.
//

#include "FreightContainer.h"

FreightContainer::FreightContainer()
{
    maxCapacity = 0.00;
}


FreightContainer::FreightContainer(double maxCapacityInput)
{
    maxCapacity = maxCapacityInput;
}


double FreightContainer::getMaxCapacity() const
{
    return maxCapacity;
}



