//Name: Matthew Schroder
//Professor: Dr. Pettey
//Course: 3080
//Purpose: Takes input for an array size, creates an array of that sizes and then using gaussian elimination computes the inverse of that array
//Due: March 15, 2019 11:59pm

#include <iostream>

using namespace std;

int main()
{
//variable for the size of the matrix
int sz;
cout << "\nInput the dimensions of the matrix: ";
cin >> sz;

float original[sz][sz];
float inverse[sz][sz];
float mult;
float divisor;

cout << "\nInput the matrix\n";

//Loops to input values into the array
for(int i = 0; i < sz; i++)
{
    for(int j = 0; j < sz; j++)
    {
        cin >> original[i][j];
        if(i==j)                    //Makes an inverse array by setting anything on the main diagonal to 1 and everything else to 0
           inverse[i][j] = 1;
        else
           inverse[i][j] = 0;
    }
}

cout << "\nThe inverse is\n";
//Loops through the process to inverse the matrix
for(int i = 0; i < sz; i++)
{
       
    divisor = original[i][i];
    for(int j = sz-1; j >= 0; j--)
    { 
       inverse[i][j] = inverse[i][j]/ divisor;          //Divides row i of the inverse matrix by element i,i of the original matrix 
       original[i][j] = original[i][j]/ divisor;        //Divides row i of the original matrix by element i,i of the original matrix
    }

    for(int j = 0; j < sz; j++)
    {
       {
         if(j!=i)
         {
         mult = -original[j][i];      
         for(int k = 0; k < sz; k++)
          {
           original[j][k] = original[j][k] + (mult * original[i][k]);
           inverse[j][k] = inverse[j][k] + (mult * inverse[i][k]);
          }
         }
       }
   }
}

//Prints out the "inverse" matrix
for(int i = 0; i < sz; i++)
{
    for(int j = 0; j < sz; j++)
    {
        cout << inverse[i][j]<< " ";
    }
    cout << endl;
}

cout << endl;



return 0;
}
