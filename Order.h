//----------------------------------------------------------------------
// CLASS: Order
//
// Author: Dhvani Patel (7941769)
//
// REMARKS: This is a purely virtual/abstract class.
//          Allows creation of orders. Holds information specific to an 
//          order such as arrival time, cost and ID.
//----------------------------------------------------------------------


#pragma once
#include <string>
using namespace std;

class Order
{
    private:
    int arrivalTime;                    //time that the order arrived
    double cost;                        //cost to customer
    int orderID;                        
    static int identification;          //tracks number of orders made

    
    public:
    //constructor
    Order();
    Order( int, double );
    virtual ~Order();


    //getters

    int getArrivalTime();
    double getCost();
    
    int getPenalty();
    int getID();

    virtual string getType() = 0;
};