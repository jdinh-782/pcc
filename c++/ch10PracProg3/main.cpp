//Chapter 10 Practice Program #3
#include <iostream>
#include "ShowTicket.h"

using namespace std;

int main()
{
    ShowTicket theatre;

    theatre.display();

    if (theatre.checkTicket())
    {
        cout << "You now have that seat!\n";
    }

    else
    {
        cout << "That seat is sold already!\n";
    }

    theatre.updateTicket();

    return 0;

}
