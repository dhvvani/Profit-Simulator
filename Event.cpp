#include "Event.h"
#include "Order.h"
#include <iostream>

using namespace std;



//null constructor
Event :: Event()
{
    order = nullptr;

    eventTime = 0;
    prepTime = 0;
    penalty = 0;
}



//parameter constructor:
//preparation time for an order is 1 hour for every $0-$199
Event :: Event( Order* nOrder ) 
{
    order = nOrder;
    eventTime = order->getArrivalTime();
    int cost = order->getCost();

    prepTime = cost / HOUR_PREP  + 1;
    penalty = 0;
}



//destructor
Event :: ~Event()
{
    delete order;
}


//only instances of subclasses must process events
void Event:: processEvent( int numPerp, int numEmp, int time, Event* removed, Record* eventRec, Record* wait ) 
{}




void Event :: print()
{
    cout << " Order " << order->getID() << " (" << order->getType() << ", $" << order->getCost() << ") " ;
}


/* getters */


int Event:: getTime()
{
    return eventTime;
}



int Event:: getPrepTime()
{
    return prepTime;
}




//--------------------------------------------------
// return the cost to the customers after calculating 
// the late shipping discount (if it applies).
//--------------------------------------------------
double Event:: getCost()
{
    getPenalty();
    double cost = order->getCost() * 0.5;

    if( penalty != 0 )
        cost -= penalty;

    return cost;
}




//--------------------------------------------------
// return the penalty to the business due to late
// shipment (if shipment is indeed late).
//--------------------------------------------------
double Event :: getPenalty()
{
    int shipTime = eventTime - order->getArrivalTime();

    if( ( order->getType() == "Primero" && shipTime > LATE_PRIME )
    ||  ( order->getType() == "Standard" && shipTime > LATE_STD ) )
        penalty = order->getCost() * 0.15;

    return penalty;
}



Order* Event:: getOrder()
{
    return order;
}


void Event:: setEventTime(int time)
{
    eventTime = time;
}

