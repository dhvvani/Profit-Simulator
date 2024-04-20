#include "Shipping.h"
#include "Prepare.h"
#include "Order.h"
#include "Record.h"
#include "ItemID.h"
#include <iostream>

using namespace std;





//null constructor
Shipping :: Shipping() : Event() {}


//parameter constructor
Shipping :: Shipping( Order* nOrder ) : Event( nOrder ) {}


//destructor
Shipping :: ~Shipping()
{
    Event :: ~Event();
}




//-----------------------------------------------------------------------------------------
// processEvent(int)
//
// PURPOSE: processing a shipment only has an effect if the waiting line of orders is
//          not empty. If it is not empty, then an event is removed from the wait line 
//          and is sent for preparation at the current time.
//
// PARAMETERS: as superclass
//
// Returns: no return value but changes are made to both records provided the waitline is
//          not empty
//-----------------------------------------------------------------------------------------

void Shipping :: processEvent( int numPrep, int numEmp, int time, Event* removed, Record* eventRec, Record* wait )
{
    if( wait->isEmpty() == 0 )
    {

        /* get next order to prepare and add to event record */

        Event* nextCust = wait->removeEvent();

        nextCust = new Prepare( nextCust->getOrder() );
        nextCust->setEventTime( time );

        Item* toAdd = new ItemID( nextCust );

        eventRec->addToRecord( toAdd );
    }
}




//print the event + any penalties if necessary

void Shipping :: print()
{
    double expense = Event::getPenalty();
    
    Event::print();
    cout << "has been shipped";


    if( expense != 0.0 )
        cout << "\t***Penalty Paid $" << expense;    
}