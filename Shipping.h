//----------------------------------------------------------------------
// CLASS: Shipping 
//
// Author: Dhvani Patel (7941769)
//
// REMARKS: This is a subclass of Event. It's presence means that a
//          new order is being shipped. Contains the instance variables 
//          of the super class and no others. Virtual functions are 
//          overriden.
//----------------------------------------------------------------------

#pragma once
#include "Event.h"
class Order;
class Record;

class Shipping: public Event
{
    public:

    //constructors and destructor
    Shipping();
    Shipping( Order* nOrder );
    ~Shipping();

    //public methods
    
    void processEvent( int, int, int, Event*, Record*, Record* ) override;
    void print() override;
};