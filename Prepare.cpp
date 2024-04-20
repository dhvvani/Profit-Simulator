#include "Prepare.h"
#include "Shipping.h"
#include "Order.h"
#include "Record.h"
#include "ItemID.h"
#include <iostream>

using namespace std;




//null constructor
Prepare :: Prepare() : Event() {}


//parameter constuctor
Prepare :: Prepare( Order* nOrder ) : Event( nOrder ) {}


//destructor
Prepare :: ~Prepare()
{
    Event :: ~Event();
}




//--------------------------------------------------------------------------------------------
// processEvent(int)
//
// PURPOSE: the proccessing of a prepare involves creation of an event of instance 'shipping'.
//          The time of the new event must be set to the input time + preparation time.
//          The new event is then added to the event record.
//
// PARAMETERS: as superclass
//
// Returns: no return but an item is added to the event record.
//--------------------------------------------------------------------------------------------

void Prepare :: processEvent( int numPrep, int numEmp, int time, Event* removed, Record* eventRec, Record* wait )
{
    Event* shipping = new Shipping( getOrder() );

    shipping->setEventTime ( time + shipping->getPrepTime() );

    Item* toAdd = new ItemID( shipping );

    eventRec->addToRecord( toAdd );
}




//print event and preparation time
void Prepare :: print()
{
    //call super class's print
    Event::print();
    cout << "is being prepared (prep time = " << getPrepTime() << ")";
}