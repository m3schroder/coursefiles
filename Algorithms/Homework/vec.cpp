#include <vector> 
#include <time.h>
#include <iostream>

using namespace std;

int main()
{
clock_t timerStart, timerEnd;
timerStart = clock();

     vector <int> vec(1000000);
     for(int i = 0; i < 1000000; i++)
     {
             vec.push_back(i);
     }

     timerEnd = clock();
     cout << (timerEnd - timerStart)*1.0/CLOCKS_PER_SEC << endl;

     return 0;
}
