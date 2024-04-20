#include "Record.h"
#include "Shipping.h"
#include "Item.h"
#include <iostream>


//null constructor
Record :: Record() 
{
    top = nullptr;
    currTime = 0;
}



//destructor
Record :: ~Record()
{
	Item* next = nullptr;
    while( top != nullptr )
    {
        next = top->getNext();
        top->~Item();
        top = next;
    }
}





//----------------------------------------------------------------------------------------------------
// addToRecord()
//
// PURPOSE: orderly adds an Item to the record. The way an item is compared is handled by
//          polymorphism. There are four cases to an Item being added to the record:
//          -adding the first item          -adding before the first item
//          -adding in between two items    -adding after the last item
//
//          If the Item being added is not the first in the list, its correct position is found
//          using while loops. There are three cases that fail the condition in the first while
//          loop (where curr is the current item newItem is being compared to):
//          i) curr is larger than the newItem      ii) curr is identical to the newItem
//          iii) item next to curr is a null pointer
//
//          Note that an item can only be identical if the compareTo method returns 0 and the input
//          parameter to compareTo() is larger when the function returns 1.
//          When case i) occurs, the item must be added before curr, when case ii) occurs, the 
//          item must be added after the last item it is identical to, i.e after curr and when
//          case iii) occurs the node be added after curr.
//
// PARAMETERS: Item to be added.
// Returns: no return vale, an item is added to the record and current time is updated to 
//          be the event time of the top Item.
//----------------------------------------------------------------------------------------------------

void Record:: addToRecord( Item* newItem ) 
{

    //first item to record
    if( top == nullptr )
    {
        top = newItem;
    }

    else
    {

        //add before the top
        if( newItem->compareTo( top ) == 1 )
        {
            newItem->setNext( top );
			top = newItem;
        }

        else
        {
            Item* curr = top;
			Item* prev = nullptr;


            //identify Item to add beside
			while( curr->getNext() != nullptr && newItem->compareTo( curr ) < 0 )
			{
				prev = curr;
				curr = curr->getNext();
			}


            //add before curr if newItem is smaller
			if( newItem->compareTo( curr ) == 1 )
            {
                if( prev != nullptr )
                    prev->setNext( newItem );

                newItem->setNext( curr );
            }

            //add to last identical item
            else if( newItem->compareTo( curr ) == 0 )
			{

                //traverse to last identical item

				while( curr->getNext() != nullptr && 
                newItem->compareTo( curr->getNext() ) == 0 )

				{
					prev = curr;
					curr = curr->getNext();
				}

                newItem->setNext( curr->getNext() );
                curr->setNext( newItem );
			}

            //add to end of record
            else
            {
                curr->setNext( newItem );
            }
        }
    }


    currTime = top->getTime();
}





//------------------------------------------------------
// numPrep()
//
// PURPOSE: counts the number of employees working on an order. This is 
//          done by identifying h=the number of shipment instances exist
//          in the record using a while loop.
//          
// Returns: number of unavailable employees 
//------------------------------------------------------

int Record :: numPrep()
{
    Item* curr = top;
    int numPrep = 0;
    Event* temp;

    while( curr != nullptr )
    {
        temp = curr->getEvent();

        if( dynamic_cast<Shipping*>( temp ) != nullptr )
            numPrep++;

        curr = curr->getNext();
    }

    return numPrep;
}





//------------------------------------------------------
// removeEvent()
//
// PURPOSE: removes the top most event (provided the record is not empty).
//          Updates the current time and the top pointer.
//------------------------------------------------------

Event* Record :: removeEvent() 
{ 
    Event* retEvent = top->getEvent();


    /*if the record isn't empty, update the current time*/

    if( top != nullptr )
        currTime = top->getTime();

    top = top->getNext();

    return retEvent; 
}


//------------------------------------------------------
// isEmpty()
//
// PURPOSE: returns 1 if the record is empty and 1 if not
//------------------------------------------------------

int Record:: isEmpty()
{
    int empty = 0;

    if( top == nullptr )
        empty = 1;

    return empty;
}


//returns the current time
int Record :: getCurrentTime()
{
    return top->getTime();
}