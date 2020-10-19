//Matthew Schroder 
//3110
//Dr. Barbosa 
//This program uses a recursive function to find the exit or lack of exit in a maze using backtracking

#include "maze.h"
#include <iostream> 
#include <fstream> 

using namespace std;

int main()
{
bool flag;          //Delcares a flag in main which is passed by reference 
                    //to FindExit to determine whether or not the exit was found 
ifstream myfile;
myfile.open("maze.txt");

Maze amaze(myfile);

myfile.close();

cout << "Maze State:" << endl;
amaze.Print();

cout << "Starting position: 1,1" << endl;
amaze.FindExit(1, 1, flag);
    
if(flag == false)
        cout << "No Exit!" << endl;


return 0;
}
