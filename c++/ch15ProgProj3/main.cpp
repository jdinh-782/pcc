//Chapter 15 Programming Project 3


#include "Ticket.h"
#include "PremiumTicket.h"


int main()
{
    vector<BasicTicket*> v;

    PremiumTicket premiumTicket(20);
    BasicTicket basicTicket(10);
    BasicTicket basicTicket1(15);

    auto* newBasicTicket = new BasicTicket;
    newBasicTicket = &basicTicket;

    v = premiumTicket.addTicket(newBasicTicket, v);
    cout << v[0]->getTicketCost() << endl;

    delete newBasicTicket;

    auto* newBasicTicket1 = new BasicTicket;
    newBasicTicket1 = &basicTicket1;

    v = premiumTicket.addTicket(newBasicTicket1, v);
    cout << v[1]->getTicketCost();


    return 0;
}
