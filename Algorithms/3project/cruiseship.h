#ifndef CRUISESHIP_H
#define CRUISESHIP_H
#include <iostream>
#include <string>
#include "ship.h"

using namespace std;

class CruiseShip : public Ship
{
private:
double lux;  //must sum to 1
double upp;
double low;
int i_lx;
int i_up;
int i_lo;

public:
CruiseShip(string, double, double, double, double);
void sail();
void load(int);       
};
#endif
