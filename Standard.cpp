#include "Standard.h"
using namespace std;




//null constructor
Standard :: Standard(): Order(){}


//parameter constructor
Standard :: Standard( int time, double cost ): Order( time, cost ){}


/* getter */

string Standard :: getType()
{
    return TYPE;
} 