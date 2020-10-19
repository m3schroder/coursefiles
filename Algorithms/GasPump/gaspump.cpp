#include "gaspump.h"

GasPump::GasPump(string type, double cap, double price)
{
fuel_type = type;
pumpCap = cap;
perGal  = price;
inTank  = cap;
}

void GasPump::replen()
{
inTank = pumpCap;
}

void GasPump::dispenseFuel(double*actual, double purchaseAmt)
{
     double desiredAmt = purchaseAmt/perGal;
     if(desiredAmt <= inTank)
      {
          collected = collected + purchaseAmt;
          dispensed = dispensed + desiredAmt;
          actual[0] = purchaseAmt;
          actual[1] = dispensed; 
      }

     else if(needReplen == true)
      {
          replen();
          needReplen = false;
          actual[0] = 0.0;
          actual[1] = 0.0;
      }

     else if(desiredAmt > inTank)
      {
          collected = purchaseAmt/inTank;
          dispensed = dispensed + inTank;
          needReplen = true;
          actual[0] = inTank * perGal;
          actual[1] = inTank;
      }

}

