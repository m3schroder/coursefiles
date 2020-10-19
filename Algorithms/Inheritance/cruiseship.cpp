#include "cruiseship.h"

CruiseShip::CruiseShip(string name, double fuel, double lx, double up, double lw) : Ship(name, fuel) //calls base class constructor and defines variables
{
        lux = lx;
        upp = up;
        low = lw;
}

void CruiseShip::sail()       //writes to output the number of passengers in each level
{
cout << shipname << " " << i_lx << " " << i_up << " " << i_lo << endl;
}

void CruiseShip::load(int pass)    //distribute passengers across cabin 
{
i_lx = lux * pass;  
i_up = upp * pass;
i_lo = low * pass;
}
