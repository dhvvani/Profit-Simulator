//----------------------------------------------------------------------
// CLASS: Primero
//
// Author: Dhvani Patel (7941769)
//
// REMARKS: Extends order. Allows creation on primero customers who
//          should recieve first priority. 
//----------------------------------------------------------------------


#pragma once
#include "Order.h"
using namespace std;

class Primero: public Order
{

    private:
    const string TYPE = "Primero";

    public:
    //constructors
    Primero();
    Primero( int, double );

    //getter
    string getType() override;
};