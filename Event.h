//----------------------------------------------------------------------
// CLASS: Event
//
// Author: Dhvani Patel (7941769)
//
// REMARKS: This is a purely virtual/abstract class.
//          Event classes contain orders, the time of the event and the
//          shipping time of the order. It's dynamic type signifies the stage
//          of processing the order is in. 
//----------------------------------------------------------------------


#pragma once
#include <string>

using namespace std;
class Order;
class Record;

class Event
{
    private:
    /*time until which a shipment is considered 
    late for each customer type*/
    const int LATE_PRIME = 8;       
    const int LATE_STD = 23;

    //money earned per hour of preparations
    const int HOUR_PREP = 200;

    //instance variables:
    Order* order;
    int eventTime;
    int prepTime;
    double penalty;

    public:

    //Construtors
    Event();
    Event( Order* nOrder );
    virtual ~Event();

    //functions
    virtual void processEvent( int, int, int, Event*, Record*, Record* ) = 0;
    virtual void print() = 0;

    //getters
    int getTime();
    int getPrepTime();
    double getCost();
    double getPenalty();
    Order* getOrder();

    //setter
    void setEventTime(int);
};