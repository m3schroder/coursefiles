#ifndef CARGOSHIP_H
#define CARGOSHIP_H
#include "ship.h"

using namespace std;

class CargoShip : public Ship
{
private:
double * forward;
double * aft;
int maxCap;
double perc;

public:
CargoShip(string, double, int, double);      //Defined with base class in .cpp folder 
~CargoShip();                                //deallocates memory for forward and aft 
void fuel(int);                              //overloads base class
void load(int);                              //overrides base class pure virtual function 
};

#endif
