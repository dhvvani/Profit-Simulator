#include "ItemType.h"


//null constructor
ItemType:: ItemType() : Item() {}


//parameter constructor
ItemType:: ItemType( Event* nEvent ) : Item( nEvent ) {}


//destructor
ItemType :: ~ItemType()
{
    Item:: ~Item();
}




//----------------------------------------------------------------------
// compareTo()
//
// PURPOSE: compares the customer's types of the parameter item with 
//          'this' item, if they are the same, to sort by time.
//			If the event times are the different, sort by type.
//
// PARAMETERS:  item for 'this' to be compared with
//
// Returns: returns 1 if 'compare' is standard while 'this' is primero,
//			-1 when 'compare'is primero and 'this' is standard.
//          If the two have the same type, sort by time.
//
//			If the types are equal, returns 1 if 'compare' has a 
//			larger time then 'this', -1 if smaller and 0 if identical.
//-----------------------------------------------------------------------
int ItemType :: compareTo( Item* compare )
{
	int val = 0;


	/* Sort by types if different*/

    if( getType() != compare->getType() )
	{
		if( compare->getType() == "Standard" )
			val = 1;
		else
			val = -1;
	}
	
	/* else by time */
	else
		val = Item :: compareTo( compare );
	

	return val;
}