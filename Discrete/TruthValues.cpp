#include <iostream>

using namespace std;

int main()
{
bool p,q;
char cont;
char expr[3];       //declares a char array for the expression to make checking characters easier 
bool ans;           //the answer to be displayed 

cout << "Would you like to evaluate boolean expression?" << endl;          //ask the user if they should continue 
cin >> cont;

while(cont == 'y')
     {
          cout << "Input the truth values for P and Q using 1 for true and 0 for false\n";          //prompt the user to input boolean values
          cin >> p >> q;
          cout << "Input the logical expression to be evaluated\n";                                 //prompt the user to input the expression to evaluate 
          cin >> expr[0] >> expr[1] >> expr[2];
     
          switch(expr[1])          //switch statement to decide course of action based on the operator in the second element 
            {
                case 'A':
                ans = p&&q;   //and p and q
                cout << "The result of the expression " << expr[0] << expr[1] << expr[2] << " is " << ans << endl;
                break;
                
                case 'O':
                ans = p||q;   //the answer to p or q (vice versa)
                cout << "The result of the expression " << expr[0] << expr[1] << expr[2] << " is " << ans << endl;
                break;
                
                case 'N':
                if(expr[0] == 'Q') //Check which variable is in element one then not it 
                        ans = !q;
                else
                        ans = !p;

                cout << "The result of the expression " << expr[0] << expr[1] << expr[2] << " is " << ans << endl;
                break;

                case 'I':
                    if((expr[0] == 'P') && (p == 1 && q == 0))        //check if PIQ is false 
                    {
                    ans = 0;
                    cout << "The result of the expression " << expr[0] << expr[1] << expr[2] << " is " << ans << endl;
                    }

                    else if((expr[0] == 'Q') && (p == 0 && q == 1))   //check is QIP is false 
                    {
                    ans = 0;
                    cout << "The result of the expression " << expr[0] << expr[1] << expr[2] << " is " << ans << endl;
                    }

                    else      //if if and else if are false then the statement is true 
                    {
                    ans = 1;
                    cout << "The result of the expression " << expr[0] << expr[1] << expr[2] << " is " << ans << endl;
                    }

                break;
                  
                case 'E':     //checking if p and q are equivalent 
                ans = p==q;
                cout << "The result of the expression " << expr[0] << expr[1] << expr[2] << " is " << ans << endl;
                break;
                              
            }   
          cout << "Would you like to evaluate boolean expression?" << endl;
          cin >> cont; 

     }

cout << "Goodbye" << endl;
return 0;

}
