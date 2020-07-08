/*
Name: Matthew Schroder 
Course: 3080
Date: March 26, 2019
Purpsose: This program takes input for an adjacency relation converts it into a matrix and displays information about it from a menu  
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
        int numN, mat[9][9] = {0}, i, j, sum;
        string adRel;
        char selection = 'a';
        bool noIso = true;      //Flags if isolated node is found
              
        cout << "Please input the number of nodes: " << endl;
        cin >> numN;
       
        cout << "Please input the adjacency relation: \n"; 
        cin >> adRel;
        
        for(i = 0; i < adRel.length(); i++)     //iterates through all characters of the adjecency relation string
        {
              if(adRel[i-1] == '(')         //Uses ascii (minus 49 since starting at element 0) codes to change character into appropriate array element 
                 mat[adRel[i] - 49][adRel[i+2]-49] = 1;      //If sets the element to whatver the char value is - 1
        }

int arr[numN] = {0}, interest, one, two;
while(selection!='6')
    {
        cout <<"Choose from the following\n";
        cout <<"1. Print the adjecency matrix\n";
        cout <<"2. Determine if there are any isolated nodes\n";
        cout <<"3. Determine the degree of the node\n";
        cout <<"4. Determine if an Euler path exists\n";
        cout <<"5. Determine if one node is adjacent to another\n";
        cout <<"6. Quit\n";

        cin >> selection;
        switch(selection)
        {
                

                case '1':               //Prints out the adjaceny matrix
                 
                 for(i = 0; i < numN; i++)
                 {
                    cout << endl;
                    for(j = 0; j < numN; j++)
                    {
                            cout << mat[i][j];
                    }
                 }
                 cout << "\n\n";
                 break;

                 case '2':                //Checks for an isolated node
                
                  for(i = 0; i < numN; i++)     //Loops through the whole array
                  {
                    sum = 0;
                    for(j = 0; j < numN; j++)
                    {
                       sum = sum + mat[i][j];        //Sums all of the values in one row 
                    }
                    if(sum == 0)                //If the sum of one row is equal to 0 then it is isolated
                    {
                       cout << i+1 << " is an isolated node" << endl;        
                       noIso = false;
                    }
                  }
                  if(noIso == true)
                          cout << "There are no isolated nodes" << endl;

                  cout << "\n\n";
                  break;

                 case '3':               //determines the degree of a node
                  
                  cout << "Which node are you interested in?" << endl;
                  cin >> interest;
                  sum = 0;
                  for(i = 0; i < numN; i++)
                       sum = sum + mat[interest-1][i];   //Checks the row of interest-1 since conventional numbering isn't the same as elements

                  cout << "The degree of node " << interest << " is " << sum << endl;           //Every value in the row is equal to 1 degree
                  cout << "\n\n";
                  break;

                  case '4':              //Determines whether or not there is a Euler path

                  for(i = 0; i < numN; i++)
                  {
                          sum = 0;
                          for(j = 0; j < numN; j++)
                             sum = sum + mat[i][j];          //Checks the degree of node i
                          if(sum % 2 != 0)
                             arr[i]=1;      //If the degree of node i is odd then arr[i] is flagged
                  }
                    
                  sum = 0;
                  for(i = 0; i < numN; i++)
                  {
                          if(arr[i] == 1)         //Counts the number of nodes flagged and stores that value in sum
                                  sum += arr[i]; 
                  }

                  if(sum == 0||sum == 2)        //If there are 0 or 2 odd nodes then there is an Euler path 
                          cout << "An Euler path does exist in the graph" << endl;
                  else
                          cout << "An Euler path does not exist in the graph" << endl;
                  

                  cout << "\n\n";
                  break;
                 
                 case '5':
                
                  cout << "Which two nodes are you interested in?" << endl;
                  cin >> one;
                  cin >> two;

                  if(mat[one-1][two-1] == 1 || mat[two-1][one-1] == 1)          //Checks both of the desired elements of the array in any order 
                         cout << "Node " << one << " is adjacent to node " << two << endl;
                  else if(one == two)       // A nod cant be adjacent to itself 
                         cout << "Node " << one << " is not adjacent to node " << two << endl;
                   else
                         cout << "Node " << one << " is not adjacent to node " << two << endl;
                  
                  cout << "\n\n";
                  break;        
                 
                  case '6':
                  break;
        }
    }


return 0;        
}
 
