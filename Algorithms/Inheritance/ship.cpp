#include "ship.h"
#include <iostream>
#include <string>

Ship::Ship(string name, double fuel)    //constructor that is called along side derived class constructors 
{
        shipname = name;
        fuel_on_board = fuel;
}

void Ship::fuel()   //defines the basic fuel function used with cruiseship 
{
        cout << shipname << " " << fuel_on_board << endl;
}

void Ship::sail()   //defines the basic sail function used with the cargoship 
{
        cout << shipname << " sailing " << endl;
}


