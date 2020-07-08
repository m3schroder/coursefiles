#ifndef GASPUMP_H
#define GASPUMP_H

#include <iostream>

using namespace std; 

class GasPump
{
string fuel_type;
double inTank;
double pumpCap;
double perGal;
double dispensed;
double collected;
bool needReplen;
void replen();

public:

GasPump(string, double, double);
inline string returnFtype()const
       {
        cout << "sucks" << endl;
        return fuel_type;
        }
inline double returnPerGal()const{return perGal;}
inline double returnInTank()const{return inTank;}
inline double returnDispensed()const{return dispensed;}
inline double returnCollected()const{return collected;}
void dispenseFuel(double*,double);

};
#endif
