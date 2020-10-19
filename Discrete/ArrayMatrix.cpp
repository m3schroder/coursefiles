//Matthew Schroder 
//This program takes input for 2 arrays and calculates the sum and product if possible and also determines whether it symmetric and transposes it 

#include<iostream>

using namespace std;

int main()
{
        int rows1;
        int cols1;
        int rows2;
        int cols2;

        //This block takes input for the 1st matrix for rows, cols, and values
        cout << "input rows/cols for the first matrix: ";
        cin >> rows1;
        cin >> cols1;
        int m1[rows1][cols1];
        cout << "input the first matrix" << endl;       
        for(int i = 0; i < rows1; i++)
        {
                for(int j = 0; j < cols1; j++)
                {
                        cin >> m1[i][j];
                }
                cout << endl;
        }
        

        //This block takes input for the 2nd matrix for rows, cols, and values
        cout << "input rows/cols for the second matrix: ";
        cin >> rows2;
        cin >> cols2;
        int m2[rows2][cols2];
        cout << "input the second matrix" << endl;       
        for(int i = 0; i < rows2; i++)
        {
                for(int j = 0; j < cols2; j++)
                {
                        cin >>  m2[i][j];
                }
                cout << endl;
        }

        //This block determines whether or not the first matrix is symmetric
        bool isSym = true;      //declares a variable that is set false when 2 elements in the array are found not equal
        for(int i = 0; i < rows2; i++)
        {
                for(int j = 0; j < cols2; j++)
                {
                       if(m1[j][i]!=m1[i][j])       //Checks to see if the values reflected across the center are equal or not
                               isSym = false;       //Flags isSym false
                }
        }
        if(isSym == false)      //Determines which print statement to use with isSym
                cout << "The first matrix is not symmetric" <<endl;
        else
                cout << "The first matrix is symmetric" <<endl;

            
        //Calculates the sum of the two matrices if it can be  
        if(rows1 == cols1 && rows2 == cols2) 
        {
            cout << "The sum of the two matrices is " << endl;
            for(int i = 0; i < rows2; i++)
            {
                for(int j = 0; j < cols2; j++)
                {
                        cout << m1[i][j] + m2[i][j] << " ";                
                }
                cout << endl;
            }
        }
        else 
                cout << "The sum is not possible" << endl; 

 
        //This calculates the product of the two matrices if it can be determined 
        if(cols1 == rows2)
         {
 
            cout << "The product of the two matrices is " << endl;
            //Declares a 2D array that holds the necessary calculations for each element 
            int ans[rows1][cols2];
            for(int i = 0; i < rows1; i++)
            {
                    for(int j = 0; j < cols2; j++)
                    {
                            ans[i][j] = 0;
                            for(int k = 0; k < cols1; k++)
                            {
                                    ans[i][j] += m1[i][k] * m2[k][j];
                            }
                    }
            }
            
	    //Prints out the ans matrix  
            for(int i = 0; i < rows1; i++)
                    for(int j = 0; j < cols2; j++)
                                {
                                        cout << ans[i][j] << " ";
                                        if(j == cols2 - 1)
                                                cout << endl;
                                }
                    
         }
       else
               cout << "The product is not possible" <<endl; 


        //outputs the transpose of the first matrix 
        cout << "The transpose of the first matrix is" << endl;
	//Switches the rows and cols as is required for a transposal 
        for(int i = 0; i < cols1; i++)
        {
                for(int j = 0; j < rows1; j++)
                {
                        cout << m1[j][i] << " ";
                }
                cout << endl;
        }

        cout << "\ngoodbye" <<  endl; 
        return 0;
}
        
