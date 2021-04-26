//
// Created by jdinh on 11/22/2020.
//

#include "Ticket.h"


Ticket::Ticket()
{
    cost = 0;
}


Ticket::Ticket(double costInput)
{
    this->cost = costInput;
}


//void Ticket::addTicket(BasicTicket& b)
//{
//
//}


//ostream& operator<<(ostream& outs, const Ticket &t)
//{
//    for (auto& details : t.v)
//    {
//        outs << details;
//    }
//    return outs;
//}
