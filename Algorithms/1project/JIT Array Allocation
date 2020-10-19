// Matt schroder 
// CSCI 3110-001
// Project #1
// Due: 01/28/19 


#include <fstream>
#include <iostream>

using namespace std;

int * allocateArray(int * array, int* array_size, double expansion);
double calcAvg(int * array, int ele_count);


//This is a small program that simulates just in time memory allocation, by dynamically allocating 
//an array, and then reallocating it as the size of the input reaches the array’s capacity. 
int main ()
{

int *array = NULL;						//delcaring an int pointer to the array that is to be allocated in allocateArray
int array_size;			  			//initial size of the array 
double expansion;   					//percent to expand array by
double avrg;
int ele_count = 0;

ifstream numbfile;
ofstream outputfile;
outputfile.open("out.txt");
numbfile.open("nums.txt");
numbfile >> array_size;
numbfile >> expansion;

expansion = expansion + 1;

if(array_size % 50 != 0 || array_size < 100 || array_size > 350)		//size specification check
	   {
	   cout << "Error" << endl;
	   numbfile.close();
	   outputfile.close();
	   delete[]array;
	   return 0;    
	   }

array = allocateArray(array, &array_size, expansion); 				//first instance
cout << array_size << endl;
outputfile << array_size << endl;

int i = 0; 	  
while(numbfile >> array[i])
	   {
	   i++;
	   ele_count++;

			 if(i == array_size)
			 {
			 avrg = calcAvg(array, ele_count);
			 array = allocateArray(array, &array_size, expansion);	 
			 cout << ele_count << " " << avrg << endl;
			 outputfile << ele_count << " "<<  avrg << endl;  
			 }
	   }

avrg = calcAvg(array, ele_count);

//final print statements
outputfile << array_size << " " << ele_count << " "<<  avrg << endl; 
cout <<array_size << " " << ele_count << " "<<  avrg << endl;
 
delete[]array;
numbfile.close();
outputfile.close();
return 0;
}




// This function dynamically allocates memory for an array, and when necessary copies elements
// from the old array to the new and deallocates the memory of the array being expanded.

int* allocateArray(int * array, int* array_size, double expansion)
{
	   
	   if(array == NULL)
	   {
	   array = new int[*array_size];  
	   }	   

	   else
	   {
	   int old_size = *array_size;		  
	   *array_size = *array_size * expansion;
	   int * new_array = new int[*array_size];
			 for(int k = 0; k < old_size; k++)
			 {
			 new_array[k] = array[k]; 
			 }
	   delete[]array;
	   return new_array;
	   }

return array;
}


// This function accepts as input parameters the dynamic array, and the number of
// values that have been read into it, and returns the calculated average. 

double calcAvg(int *array, int ele_count)
{
double avrg;
double sum;
	   for(int i = 0; i < ele_count; i++)
	   {
	   sum = sum + array[i];
	   }	
avrg = sum/ele_count;
return avrg;

}



