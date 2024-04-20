//----------------------------------------------------------------------
// CLASS: Record
//
// Author: Dhvani Patel (7941769)
//
// REMARKS: Acts as a generic list of events. Allows Items (which contains events)
//          and any of its subclasses to be chained in the record. Functions include
//          addToRecord which adds the Item in an ordered manner and removeEvent()
//          which removes the first Item in the record.
//          Remaining functions are used by the simulation class to allow processing.
//----------------------------------------------------------------------


#pragma once
class Item;
class Event;

class Record 
{

    private:
    int currTime;
    Item* top;

    public:

    //constructor and destructor
    Record();
    ~Record();

    //methods
    void addToRecord( Item* nEvent );
    int isEmpty();                      //returns 1 if the record is empty and 0 if not
    Event* removeEvent();               //removes the first ordered item
    int getCurrentTime();                       
    int numPrep();                      //counts the number of preparations
};