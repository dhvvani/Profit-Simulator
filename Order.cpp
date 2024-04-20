#include "Order.h"
#include <iostream>

using namespace std;

int Order:: identification = 0;





//null construtor
Order::Order()
{
    arrivalTime = 0;
    cost = 0.0;
}



//parameter constructor
Order::Order( int aTime, double expenditure )
{
    arrivalTime = aTime;
    cost = expenditure;
    orderID = identification + 1;
    identification++;
}

Order:: ~Order(){};



//getters

int Order:: getArrivalTime() 
{
    return arrivalTime;
}


//this implementation is optional
// string Order:: getType()
// {
//     return "";
// }



double Order:: getCost()
{
    return cost;
}



int Order:: getID()
{
    return orderID;
}