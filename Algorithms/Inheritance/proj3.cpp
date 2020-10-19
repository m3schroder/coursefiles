//Matthew Schroder 
//CSCI 3110-001 
//Project 3
//02/19/19

#include <iostream>
#include <fstream>
#include "ship.h"
#include "cruiseship.h"
#include "cargoship.h"

using namespace std;

void sailShip(Ship&);    //prototype for the sailShip function
int main()
{

ifstream  myfile;
myfile.open("ships.txt");          //open file streaming to "ships.txt"

//Declare variables for the cruiseship

string cru_name;
double fuelload;
double lux;
double upp;
double low;
int pass;

//Load in an instantiate the cruiseship

myfile >> cru_name;
myfile >> fuelload;
myfile >> lux;
myfile >> upp;
myfile >> low;
myfile >> pass;
CruiseShip cruise(cru_name, fuelload, lux, upp, low);  //declares cruise ship object and give it necessary parameters 
cruise.load(pass);  //calls the cruise ship class's load function 
cruise.fuel();      //calls the base classes fuel function 
sailShip(cruise);   //calls the cruise ship's version of sail not the base class's 3

//declare variables for the cargoship
 
string car_name;
double fuel;
int cap;
double forward;
int tonnage; 
int flash;

//Load in an instantiate the cargoship

myfile >> car_name;
myfile >> fuel;
myfile >> cap;
myfile >> forward;
myfile >> tonnage;
myfile >> flash;
CargoShip cargo(car_name, fuel, cap, forward);    //creates the cargo ship object with its parameters 
cargo.fuel(flash);       //Prints the flashpoint and shipname
cargo.load(tonnage);     //Loads the ships forward and aft bays with the appropriate percentages
sailShip(cargo);         //calls the base classes sail ship funtion 

myfile.close();

return 0;
}

void sailShip(Ship& ship)
{
ship.sail();
}
