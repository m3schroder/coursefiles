#include <forward_list> 
#include <time.h>
#include <iostream>

using namespace std;

int main()
{
     clock_t timerStart, timerEnd;
     timerStart = clock();


     forward_list <int> lis;
     for(int i = 0; i < 1000000; i++)
     {
             lis.push_front(i);
     }

     timerEnd = clock();
     cout << (timerEnd - timerStart)*1.0/CLOCKS_PER_SEC << endl;

     return 0;
}


