//
// Created by jdinh on 9/21/2020.
//

//Chapter 10 Practice Program #3

#include "ShowTicket.h"
#include <iostream>

ShowTicket::ShowTicket()
{
    row = 1;
    seatNumber = 5;
}


ShowTicket::ShowTicket(int setRow, int setSeatNumber)
{
    row = setRow;
    seatNumber = setSeatNumber;
    ticketSold = false;
}


void ShowTicket::updateTicket()
{
    for (int i = 1; i < 6; i++)
    {
        status = ": Available";
        if (i % 2 == 0 || i == seatNumber)
        {
            status = ": Sold";
        }
        cout << "\nSeat " << i << status;
    }
}


bool ShowTicket::checkTicket()
{
    cout << "\n\nEnter a seat number: ";
    cin >> seatNumber;

    for (int i = 1; i < 6; i++)
    {
        status = ": Available";
        if (i % 2 == 0)
        {
            status = ": Sold";
        }

        if (i == seatNumber)
        {
            if (status == ": Available")
            {
                return true;
            }

            else
            {
                return false;
            }
        }
    }
}


void ShowTicket::display()
{
    cout << "\nRow " << row << " has " << seatNumber << " total seats!\n";
    for (int i = 1; i < 6; i++)
    {
        status = ": Available";
        if (i % 2 == 0)
        {
            status = ": Sold";
        }
        cout << "\nSeat " << i << status;
    }
}