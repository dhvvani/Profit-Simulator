//----------------------------------------------------------------------
// CLASS: Standard
//
// Author: Dhvani Patel (7941769)
//
// REMARKS: Extends order. Allows creation on standard customers who
//          should recieve second priority. 
//----------------------------------------------------------------------

#pragma once
#include "Order.h"
using namespace std;

class Standard: public Order
{
    private: 
    const string TYPE = "Standard";         //customer type

    public:
    //constructor
    Standard();
    Standard( int, double );
    
    //getter
    string getType() override;
};