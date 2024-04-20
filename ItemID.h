//----------------------------------------------------------------------
// CLASS: ItemID
//
// Author: Dhvani Patel (7941769)
//
// REMARKS: The main purpose is to provide a compareTo() method which 
//          compares via time, followed by ID. The ItemID's are used to 
//          add events to records. It is a subclass of Item.
//----------------------------------------------------------------------

#pragma once
#include "Item.h"

class Event;

class ItemID: public Item
{
    public:

    //constructors and destructors
    ItemID();
    ItemID( Event* );
    ~ItemID();


    /*returns 1 if input Item is bigger, -1 if smaller and 0 if equal*/
    int compareTo( Item* ) override;
};