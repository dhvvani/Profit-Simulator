#include "Primero.h"

using namespace std;





//null constructor
Primero :: Primero(): Order(){}


//parameter constructor
Primero :: Primero( int time, double cost ): Order( time, cost ){}


//getter
string Primero :: getType()
{
    return TYPE;
} 