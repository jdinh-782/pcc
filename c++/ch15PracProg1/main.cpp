//Chapter 15 Practice Program 1


#include "TransportVehicle.h"
#include "Plane.h"
#include "Truck.h"

int main()
{
    Plane plane(12345, 4, 50, 120);
    FreightContainer freightContainer(50);

    auto* p = new FreightContainer;
    p = &freightContainer;

    cout << plane.addFreightContainer(p) << endl;

    Truck truck(67890, 30, 150, 120);
    cout << truck.addFreightContainer(p);

    return 0;
}
