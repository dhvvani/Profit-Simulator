//----------------------------------------------------------------------------------------------
// CLASS: name...
//
// Author: Dhvani Patel (7941769)
//
// REMARKS: Creates a simulation to allow maximization of net profit for Amazin. Reads a
//          file in which each line must have the following format:
//          [TIME] [TYPE] [COST]
//          where time is an integer for the arrival time, type is the customers status
//          (either "primero" or "standard") and the cost is a double representing the
//          customer's expense. The Simulation runs with the use of two Record variables,
//          i.e the eventRecord and the Waitline. Items of type ItemID are added to eventRecord
//          while ItemType to waitLine; for purposes of orderly input. 
//          The eventRecord is ordered based on time followed by ID while the waitLine by 
//          customerType followed by time.
//          Private methods readLineAddEvent and getWaiting assist in processing of an event.
//----------------------------------------------------------------------------------------------

#pragma once
#include "Record.h"
#include <fstream> //necessary to use ifstream (to open a file)
#include <string>

using namespace std;

class Simulation
{
    private:
    const double MIN_WAGE = 13.50;
    const int HOUR_PER_DAY = 8;

    //instance variables
    int numEmp;                 //number of workers (including Geoff)
    double empCost;             //total cost of additional workers
    int numDays;                //number of days to complete orders
    double grossProfit;
    double netProfit;

    Record* eventRecord;
    Record* waitLine;
    ifstream input; 


    //private methods
    void readLineAddEvent();
    void getWaiting( int );
    void summary( int );
    void print();


    public:
    //constructors & destructors
    Simulation();
    Simulation( string, int );
    ~Simulation();

    //public methods
    void beginSimulation();
    
};