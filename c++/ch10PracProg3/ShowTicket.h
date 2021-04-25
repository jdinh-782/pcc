//
// Created by jdinh on 9/21/2020.
//

//Chapter 10 Practice Program #3

#ifndef CHAPTER10PRACTICEPROGRAM3_SHOWTICKET_H
#define CHAPTER10PRACTICEPROGRAM3_SHOWTICKET_H

#include <string>

using namespace std;

class ShowTicket
{
private:
    int row, seatNumber;
    bool ticketSold;
    string status;

public:
    ShowTicket();
    ShowTicket(int setRow, int setSeatNumber);

    bool checkTicket();

    void updateTicket();

    void display();
};


#endif //CHAPTER10PRACTICEPROGRAM3_SHOWTICKET_H
