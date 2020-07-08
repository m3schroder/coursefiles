#include "maze.h"

Maze::Maze(std::ifstream& myfile)               // Constructor: takes file object and reads maze map from file
{
myfile >> maxRows;
myfile >> maxCols;

for(int i = 0; i < maxRows+2; i++)              //Adds 2 to the array size to make room for the walls
{
    for(int j = 0; j < maxCols+2; j++)
    {
        if(i == 0 || j == 0 || i == maxRows+1 || j == maxCols+1)    //If the current element is on the outside of the array it is a Wall 
                maze[i][j] = 'X';
        else
                myfile >> maze[i][j];
    }

}
}


void Maze::Print()                        // Displays the maze and its state
{
    
    for(int i = 1; i < maxRows+1; i++)
    {
        for(int j = 1; j < maxCols+1; j++)
        {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }

}

void Maze::FindExit(int row,int col,bool& flag)     // Recursive function that finds the exit (ints: row, then column) N, E, S, W
{
 if(flag == false)
 {
  if(maze[row][col] == 'E')
  {
         cout << "Found exit!" << endl;
         flag = true;                         //Sets flag to true so it is no evaluated wrong inside of main
  }
                    
  else if(maze[row][col] != 'X' && maze[row][col] != '*')         //Doesn't process the location if it is a X or *
  {
         cout << "Exploring " << row << "," << col << endl;
  
           maze[row][col] = '*';                //If it isn't an X, E, or * then it's a O an needs to be changed to *

           Print();
                   
           for(int i = 0; i < 4; i++)           //Loops 4 times for each cardinal direction
             {
              if(i == 0)
                FindExit(row-1, col, flag);     //Checks north
              else if(i == 1)
                FindExit(row, col+1, flag);     //Checks east
              else if(i == 2)
                FindExit(row+1, col, flag);     //Checks south 
              else if(i == 3)
                FindExit(row, col-1, flag);     //Checks west
             }
          
  }
 }
}
