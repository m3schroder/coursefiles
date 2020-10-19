#include "cargoship.h"

CargoShip::CargoShip(string name, double fuel, int cap, double percent) : Ship(name, fuel) //defines variables with default values 
{
     perc = percent;
     maxCap = cap;
     forward = new double;         //allocates space for aft and forward pointers
     aft = new double; 
     *forward = 0;
     *aft = 0;
}

CargoShip::~CargoShip()            //deallocates forward and aft
{
     delete forward;
     delete aft;
}

void CargoShip::fuel(int flashpt)  //calls base class fuel funciton and its own fuel definition  
{
     Ship::fuel();
     cout << shipname << " " << flashpt << endl;
}

void CargoShip::load(int toload)        //loads the forward and aft with toload parameter checks to make sure cargo cap doesn't exceed the max capacity 
{
     double curr_plus = (toload + *forward + *aft);         //to condense code 
     if(curr_plus <= maxCap)  //checks to see if the desired load amount plus current load will exceed the capacity 
     {
          *forward = perc * toload;         
          *aft = (1-perc) * toload;       
     }
     else if(curr_plus > maxCap)
     {
          *forward = (perc) * (maxCap);
          *aft = (1-perc) * (maxCap);
     }
     cout << shipname << " " << *forward << " " << *aft << endl; 
}
