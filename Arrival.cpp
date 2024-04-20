#include "Arrival.h"
#include "Prepare.h"
#include "Order.h"
#include "Record.h"
#include "ItemID.h"
#include "ItemType.h"
#include <iostream>

using namespace std;




//null constructor
Arrival :: Arrival() : Event() {}


//parameter constructor
Arrival :: Arrival(Order* nOrder) : Event(nOrder) {}


//destructor
Arrival :: ~Arrival()
{
    Event :: ~Event();
}




//-----------------------------------------------------------------------------------------
// processEvent(int)
//
// PURPOSE: processing an arrival involves the following steps:
//          -add the arrival to the waitlist
//          -if an employee is available, remove the top most arrival from the
//           waitlist and send it for preparation (add a prepare event to event record)
//           at the current time.
//
// PARAMETERS: as superclass
//
// Returns: no return value but changes are made to the records (both if an employee is 
//          available).
//-----------------------------------------------------------------------------------------

void Arrival :: processEvent(int numPrep, int numEmp, int time, Event* removed, Record* eventRec, Record* wait)
{

    Item* toAdd = new ItemType( removed );
    wait->addToRecord( toAdd );


    /* if the umber of preparations in the list is less than the number of 
       employees, then at least one is avaialble to prepare the next
       order.
    */

    if( numPrep < numEmp )
    {
        removed = wait->removeEvent();

        Event* prep = new Prepare( removed->getOrder() );
        prep->setEventTime( time );

        Item* toAdd = new ItemID( prep );

	    eventRec->addToRecord( toAdd );
    }
    
}



//print the event
void Arrival :: print()
{
    //call super class's print
    Event::print();
    cout << "arrives";
}