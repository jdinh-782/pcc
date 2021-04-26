//
// Created by jdinh on 11/22/2020.
//

#include "PremiumTicket.h"


PremiumTicket::PremiumTicket()
{
    premiumTicketCost = 0;
}


PremiumTicket::PremiumTicket(double premiumTicketCostInput) : Ticket(premiumTicketCostInput)
{
    this->premiumTicketCost = premiumTicketCostInput;
}


vector<BasicTicket*> PremiumTicket::addTicket(BasicTicket* b, vector<BasicTicket*> v)
{
    v.push_back(b);
    return v;
}


double PremiumTicket::getTicketCost()
{
    return premiumTicketCost;
}


