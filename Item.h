//----------------------------------------------------------------------
// CLASS: iTEM
//
// Author: Dhvani Patel (7941769)
//
// REMARKS: This class and its subclasses are used to extend records. They
//          hold events and a next item. The class consists of constructors,
//          destructors and a compareTo() method.
//          compareTo() returns 1 if the parameter item is larger than 'this' 
//          item, -1 if smaller and 0 if identical.
//----------------------------------------------------------------------

#pragma once
#include <string>
class Event;
using namespace std;

class Item
{
    private:
    Event* event;
    Item* next;


    public:

    //constructors

    Item();
    Item( Event* );
    ~Item();


    //public methods

    virtual int compareTo(Item*);
    

    //getters

    Event* getEvent();
    Item* getNext();
    int getTime();          //returns the event's time
    int getID();            //returns ID
    string getType();


    //setters

    void setNext(Item*);
    void setTime(int);      //sets the event's time to time
};