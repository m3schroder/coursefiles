#include <iostream>
#include <string>
#include <fstream>
#include "gaspump.h"

using namespace std;

int main()
{
GasPump ** pump[3];
string type;
double cap;
double perGal;
int seed;
int numCars;
double perc[3];
double actual[2];

cout << fixed;
cout.precision(2);

ifstream myFile;
myFile.open("gas.txt");
myFile >> seed;
myFile >> numCars;


for(int i = 0; i < 3; i++)
     {
     myFile >> type;
     myFile >> cap;
     myFile >> perGal;
     myFile >> perc[i];
     pump[i] = new GasPump(type, cap, perGal);
     }

srand(seed);

double domain1 = 1 - perc[0];
double domain2 = 1 - (perc[0] + perc[1]);


for(int i = 1; i <= numCars; i++)
{
     double ranVal = ((int) rand() % 6) * 5 + 30;
     if(((double) rand() + 1)/RAND_MAX > domain1 && (((double) rand() + 1) / RAND_MAX ) < 1)
     {
          pump[0]->dispenseFuel(&actual[2], ranVal);
          cout << i << endl;
          cout << pump[0]->returnFtype() << " ";
          cout << pump[0]->returnPerGal() << " ";
          cout << ranVal << " ";
          cout << actual[0] <<" ";
          cout << actual[1] <<" ";
          cout << pump[0]->returnInTank() << " " << endl;
     }
     else if((((double) rand() + 1) / RAND_MAX) > domain2 && (((double) rand() + 1) / RAND_MAX < domain1))
     {
          pump[1]->dispenseFuel(&actual[2], ranVal); 
          cout << i << " ";
          cout << pump[1]->returnFtype() << " ";
          cout << pump[1]->returnPerGal();
          cout << ranVal << " ";
          cout << actual[0] <<" ";
          cout << actual[1] <<" ";
          cout << pump[1]->returnInTank() << " " << endl;
     }
     else if((((double) rand() + 1) / RAND_MAX) > 0 && (((double) rand() + 1) / RAND_MAX < domain2))
     {
          pump[2]->dispenseFuel(&actual[2], ranVal);
          cout << i << " ";
          cout << pump[2]->returnFtype() << " ";
          cout << pump[2]->returnPerGal() << " ";
          cout << ranVal << " ";
          cout << actual[0] <<" ";
          cout << actual[1] <<" ";
          cout << pump[2]->returnInTank() << " " << endl;

     }
}
cout << pump[0]->returnFtype();
cout << pump[0]->returnDispensed();
cout << pump[0]->returnCollected() <<endl;      

cout << pump[1]->returnFtype();
cout << pump[1]->returnDispensed();
cout << pump[1]->returnCollected() <<endl;   

cout << pump[2]->returnFtype();
cout << pump[2]->returnDispensed();
cout << pump[2]->returnCollected() <<endl;            

myFile.close();
delete[]pump[0];
delete[]pump[1];
delete[]pump[2];
delete[]pump;
return 0;

}
