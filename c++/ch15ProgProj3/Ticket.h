//
// Created by jdinh on 11/22/2020.
//

#ifndef CHAPTER15PROGRAMMINGPROJECT3_TICKET_H
#define CHAPTER15PROGRAMMINGPROJECT3_TICKET_H
#include <iostream>
#include <vector>

using namespace std;


class Ticket
{
private:
    double cost;

public:
    Ticket();
    Ticket(double costInput);

    virtual double getTicketCost() = 0;

    friend ostream& operator << (ostream& outs, const Ticket& t);
};


#endif //CHAPTER15PROGRAMMINGPROJECT3_TICKET_H
