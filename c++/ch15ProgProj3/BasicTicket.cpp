//
// Created by jdinh on 11/22/2020.
//

#include "BasicTicket.h"


BasicTicket::BasicTicket()
{
    basicTicketCost = 0;
}


BasicTicket::BasicTicket(double basicTicketCostInput) : Ticket(basicTicketCostInput)
{
    this->basicTicketCost = basicTicketCostInput;
}


double BasicTicket::getTicketCost()
{
    return basicTicketCost;
}