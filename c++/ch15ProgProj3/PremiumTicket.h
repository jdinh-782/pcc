//
// Created by jdinh on 11/22/2020.
//

#ifndef CHAPTER15PROGRAMMINGPROJECT3_PREMIUMTICKET_H
#define CHAPTER15PROGRAMMINGPROJECT3_PREMIUMTICKET_H
#include "Ticket.h"
#include "BasicTicket.h"


class PremiumTicket : public Ticket
{
private:
    double premiumTicketCost;

public:
    PremiumTicket();
    PremiumTicket(double premiumTicketCostInput);

    vector<BasicTicket*> addTicket(BasicTicket* b, vector<BasicTicket*> v);

    virtual double getTicketCost();

};


#endif //CHAPTER15PROGRAMMINGPROJECT3_PREMIUMTICKET_H
