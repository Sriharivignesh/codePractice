/* https://codefights.com/challenge/hMCmr72eyrJBNEdp9/main */

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>
#include <limits>
#include <stack>
#include <iterator>

int usbAndFile(int s, std::vector<int> u) {
    int r = 0;
    std::sort(std::rbegin(u), std::rend(u));
    for (auto x:u) 
    {
        r = r + (s>0);
         s = s - x;
    }
    return r;
}

int main()
{
    std::vector<int> input_vector;
    input_vector.push_back(4);
    input_vector.push_back(2);
    input_vector.push_back(8);
    input_vector.push_back(1);
    std::cout<<usbAndFile(15,input_vector)<<std::endl;
    return 0;
}

