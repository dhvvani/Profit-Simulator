#include "Item.h"
#include "Order.h"
#include "Event.h"


//null constructor
Item:: Item()
{
    event = nullptr;
    next = nullptr;
}


//parameter constructor
Item:: Item( Event* nEvent )
{
    event = nEvent;
    next = nullptr;
}



//destructor
Item :: ~Item()
{
    event->~Event();
}




//----------------------------------------------------------------------
// compareTo()
//
// PURPOSE: compares the event's times of the parameter item with 
//          'this' item and accordingly returns and integer.
// PARAMETERS:  item for 'this' to be compared with
// Returns: returns 1 if 'compare' has a larger event time, -1 if 
//          'compare' has a smaller event time and 0 if both have the 
//          same event time 
//-----------------------------------------------------------------------
int Item:: compareTo( Item* compare )
{
    int val = 0;

    if( getTime() < compare->getTime() )
        val = 1;

    else if ( getTime() > compare->getTime() )
        val = -1;

    return val;
}




/*getters and setters*/

Item* Item:: getNext()
{
    return next;
}


Event* Item:: getEvent()
{
    return event;
}


int Item:: getTime()
{
    return event->getTime();
}


int Item:: getID()
{
    return event->getOrder()->getID();
}


string Item:: getType()
{
    return event->getOrder()->getType();
}


void Item:: setNext( Item* newItem )
{
    next = newItem;
}

void Item:: setTime( int time )
{
    event->setEventTime( time );
}
