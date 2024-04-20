//-------------------------------------------------------------------------
// NAME				: Dhvani Mayoor Patel 
// STUDENT NUMBER	: 7941769
// COURSE		: COMP 2150
// INSTRUCTOR	: Mr. Olivier
// ASSIGNMENT	: assignment 2
// 
// REMARKS: Build an event driven simulation which provides statistics on a 
//			list of orders. Display the flow of orders and tally statistics to
//			maximize profits. The simulation runs by reading the contents of
//			the input file and by the number of workers (in addition to the 
//			owner). The file name and number of additional workers is read
//			during execution and used as parameters for the simulation
//			constructor
//
//			The input file must be ordered by time and each line must 
//			have the following format:
//			[TIME] [TYPE] [COST]
//			The time must be an integer, type either 'primero' or 'standard'
//			and the cost is the customer's expense as a double.
//
//			The simulation prioritizes primero customers over standard 
//			customers. A 15% discount is applied if a a primero order is 
//			shipped after 8 hours or a standard order after 23 hours.
//---------------------------------------------------------------------------

#include "Simulation.h"
#include <iostream>
using namespace std;




int main( int argc, char* argv[] )
{

	/* Read in the file name and the 
	number of additional employees*/

    if( argc != 3 )
		return 0;

    string filename = argv[1];
	int numAddEmp = stoi( argv[2] );
	


    /* Create the simulation and start it*/

	Simulation sim( filename, numAddEmp );
	sim.beginSimulation();


	/* Destroy the simulation*/

	sim.~Simulation();


	cout << "\n\nEnd of processing\n";
}