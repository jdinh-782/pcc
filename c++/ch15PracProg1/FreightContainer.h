//
// Created by jdinh on 11/21/2020.
//

#ifndef CHAPTER15PRACTICEPROGRAM1_FREIGHTCONTAINER_H
#define CHAPTER15PRACTICEPROGRAM1_FREIGHTCONTAINER_H


class FreightContainer
{
protected:
    double maxCapacity;

public:
    FreightContainer();
    FreightContainer(double maxCapacityInput);

    double getMaxCapacity() const;

};


#endif //CHAPTER15PRACTICEPROGRAM1_FREIGHTCONTAINER_H
