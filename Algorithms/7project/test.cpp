#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
       vector <int> vec = {1, 2, 3, 4, 5};
       vec.reserve(20);

       for (auto i: vec)
       std::cout << i << ' ';

       vec.pop_back();

       if(vec[1] == NULL)
              cout << "\n There was a null at 10\n";

       swap(vec[0], vec[3]);


       for (auto i: vec)
       std::cout << i << ' ';

       return 0;
}


    