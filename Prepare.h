//----------------------------------------------------------------------
// CLASS: Prepare 
//
// Author: Dhvani Patel (7941769)
//
// REMARKS: This is a subclass of Event. It's presence means that a
//          new order is being prepared. Contains the instance variables 
//          of the super class and no others. Virtual functions are 
//          overriden.
//----------------------------------------------------------------------

#pragma once
#include "Event.h"
class Order;
class Record;

class Prepare: public Event
{
    public:

    //constructors and destructor
    Prepare();
    Prepare( Order* nOrder );
    ~Prepare();
    

    //public methods
    void processEvent( int, int, int, Event*, Record*, Record* ) override;
    void print() override;
};