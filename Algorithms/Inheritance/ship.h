#ifndef SHIP_H
#define SHIP_H
#include <string>
#include <iostream>
using namespace std;

class Ship
{
protected:
string shipname;
double fuel_on_board;

public:
Ship(string, double);
virtual void sail();
void fuel();
virtual void load(int) = 0;
};

#endif
