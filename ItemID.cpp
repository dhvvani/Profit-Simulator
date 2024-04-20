#include "ItemID.h"

//null constructor
ItemID:: ItemID() : Item() {}


//parameter constructor
ItemID:: ItemID( Event* nEvent ) : Item(nEvent) {}


//destructor
ItemID :: ~ItemID()
{
    Item:: ~Item();
}




//----------------------------------------------------------------------
// compareTo()
//
// PURPOSE: compares the event's times of the parameter item with 
//          'this' item, if they are equal, no need to sort by ID.
//			If the event times are the same, sort by ID.
//
// PARAMETERS:  item for 'this' to be compared with
//
// Returns: returns 1 if 'compare' has a larger event time, -1 if 
//          'compare' has a smaller event time and 0 if both have the 
//          same event time; in the case that times are different
//
//			If the event times are equal, returns 1 if 'compare' has a 
//			larger ID then 'this', -1 if smaller and 0 if identical.
//-----------------------------------------------------------------------


int ItemID :: compareTo( Item* compare )
{

	/* Compare firstly by time */

    if( getTime() != compare->getTime() )
		return Item :: compareTo( compare );

	/* Followed by ID*/

	else
	{
		int val = 0;

		if( getID() != compare->getID() )
		{
			if( compare->getID() > getID() )
				val = 1;
			else
				val = -1;
		}
		
		return val;
    }
}