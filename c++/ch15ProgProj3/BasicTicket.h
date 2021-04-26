//
// Created by jdinh on 11/22/2020.
//

#ifndef CHAPTER15PROGRAMMINGPROJECT3_BASICTICKET_H
#define CHAPTER15PROGRAMMINGPROJECT3_BASICTICKET_H
#include "Ticket.h"


class BasicTicket : public Ticket
{
private:
    double basicTicketCost;

public:
    BasicTicket();
    BasicTicket(double basicTicketCostInput);

    virtual double getTicketCost();
};


#endif //CHAPTER15PROGRAMMINGPROJECT3_BASICTICKET_H
