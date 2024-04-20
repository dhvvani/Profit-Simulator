#include "Simulation.h"
#include "Primero.h"
#include "Standard.h"
#include "Arrival.h"
#include "Shipping.h"
#include "ItemType.h"
#include "ItemID.h"

#include <sstream> //necessary for using stringstream
#include <iostream>

using namespace std;



//null constructor
Simulation :: Simulation()
{
	eventRecord = new Record();
	waitLine = new Record();
	numEmp = 0;
	numDays = 0;
	empCost = 0;
	grossProfit = 0;
	netProfit = 0;
}



//parameter constructor
Simulation :: Simulation( string fileName, int workers )
{
	eventRecord = new Record();
	waitLine = new Record();
    input.open( fileName );

	numEmp = workers + 1;
	grossProfit = 0;
}



//destructor: deletes instance variables on the heap
Simulation :: ~Simulation()
{
	eventRecord->~Record();
	waitLine->~Record();
}




//-----------------------------------------------------------------------------------------------
// beginSimulation()
//
// PURPOSE: starts of the event driven simulation. Calls readLineAddEvent() as its first
//			task. This triggers the onset of removing and processing events from the
//			event and waitLine records. The way an event is processed depends on its instance
//			and is handled by polymorphism. 
//			If the event is a/an:
//			i) arrival - call readLineAddEvent();
//		    ii) shipping - update grossProfit.
//
//		    Repeat the above until the evet record is empty (i.e waitLine is empty as well)
//			using a while loop. Print all events removed from the event record in each iteration.
//
//			Calculate the summary of all instance variables and print them.
//
// Returns: there is no return value, however, items are removed from the event record.
//-----------------------------------------------------------------------------------------------

void Simulation :: beginSimulation()
{

	cout << "\n*** Simulation begins ***\n";

    readLineAddEvent();

	int currentTime;
	int numPreps;
	Event* temp;


	while( eventRecord->isEmpty() == 0 )
	{
		//update stats then remove an event
		currentTime = eventRecord->getCurrentTime();
		numPreps = eventRecord->numPrep();
		temp = eventRecord->removeEvent();


		//print to user
		cout << "\nTIME: -> " << currentTime;
		temp->print();


		temp->processEvent(numPreps, numEmp, currentTime, temp, eventRecord, waitLine);


		//if removed an arrival, add one to the event record
		if( dynamic_cast<Arrival*>( temp ) != nullptr )
			readLineAddEvent();


		//if removed a shipment, update grossProfit
		if( dynamic_cast<Shipping*>( temp ) != nullptr  )
			grossProfit += ( temp->getCost() );
	}


	//print to std out
	summary( currentTime );
	print();
}





//-----------------------------------------------------------
//summary()
//peforms required calculations for the end of the simulation
//-----------------------------------------------------------

void Simulation :: summary( int currentTime )
{
	numDays = currentTime / 8 + 1;
	empCost = ( numEmp - 1 ) * ( numDays * HOUR_PER_DAY * MIN_WAGE )  + ( numEmp-1 )* numDays;
	netProfit = grossProfit - empCost;
}




//-----------------------------------------------------------
//print()
//prints statistics to std out
//-----------------------------------------------------------

void Simulation:: print()
{
	cout << "\n\n\n#######################\nThe simulation has ended";

	cout << ".\nNumber of additional workers: " << numEmp - 1;
	cout << ".\nNumber of work days: " << numDays;

	printf( ".\nCost of additional workers: $%.2f", empCost );

	printf( ".\nThe gross profit before paying workers: $%.2f", grossProfit );
	printf( ".\nThe net profit before paying workers: $%.2f", netProfit );

	cout << ".\n#######################\n";
}





//------------------------------------------------------------------------------------
// readLineAddEvent()
//
// PURPOSE:	reads the next line in the file. If the file is not null, then creates an 
//			order dependant on the [TYPE] that was read. An event is then made which is 
//			then used to create an ItemID which is then added to the event record
//			in an orderly manner. 
//
// Returns: no return but a change is made to the event record provided there is a next
//			line in the required format.
//------------------------------------------------------------------------------------


void Simulation :: readLineAddEvent()
{
	string line;					//stores the line read in


	//variables used to create an order
    int time = 0;
	string customerType = "";
	int value = 0;


	//read provided the next line exists
    if( getline( input, line ) )  
	{

		/*seperate the line by tokens and store 
		in respective variables*/
		stringstream sst( line );  

		sst >> time;
		sst >> customerType;
		sst >> value;  


		/*create the order and add to the event record*/

		Order* first;

		if( customerType == "standard" )
			first = new Standard( time, value );

		else
			first = new Primero( time, value );
	

		Event* initial = new Arrival( first );
		Item* toAdd = new ItemID( initial );

		eventRecord->addToRecord( toAdd );
	}
}




//--------------------------------------------------------------------------------------
// getWaiting()
//
// PURPOSE: removes an event from the waiting line. The event is then processed
//			which triggers an addition to the event record.  The parameter is the
//			current time passed to processEvent() so the new event has time 
//			up-to-date.
//
// Returns: no return value but changes are made to both records provided the waitLine
//			was not empty.
//--------------------------------------------------------------------------------------

void Simulation :: getWaiting( int cTime )
{
	// Event* test = waitLine->removeEvent();

	// if( test != nullptr )
	// {
	// 	test = test->processEvent( cTime );
	// 	Item* toAdd = new ItemID( test );

	// 	eventRecord->addToRecord( toAdd );
	// }
}