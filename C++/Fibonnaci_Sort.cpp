/* https://codefights.com/challenge/QczEop25GyKxsRTjJ/main */

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>
#include <limits>
#include <stack>
#include <iterator>


//GOLFED VERSION - REQUIRES SOME COMPILER TWEAKING TO GET IT TO RUN, BUT IT EXECUTES FINE IN THE IDE PROVIDED BY CODEFIGHTS
/*std::vector<int> b, FibonacciSort(std::vector<int> s) {
    int j=0,c = s.size(),a[] = {0,1,2,3,5,8,13,21,34,55,89};
    for(i:a)
    {
        if(i < c)
        b.push_back(s[i]);
    }
    std::sort(b.begin(),b.end());
    for(i : a)
    {
        if(i < c)
        s[i] = b[j++];
    }
    return s;
}*/

std::vector<int> FibonacciSort(std::vector<int> sequence) {
    int j=0;
    int c = sequence.size();
    int fibonnaci_reference[] = {0,1,2,3,5,8,13,21,34,55,89}; //Hardcode fibonnaci numbers that is under 100 as sequence length mentioned in constraints is guaranteed to be under 101
    std::vector<int> temporary;
    for(auto i:fibonnaci_reference)
    {
        if(i < c)
        temporary.push_back(sequence[i]);
    }
    std::sort(temporary.begin(),temporary.end());
    for(auto i : fibonnaci_reference)
    {
        if(i < c)
        sequence[i] = temporary[j++];
    }
    return sequence;
}



int main()
{
    std::vector<int> input = {1, 0, 1, 0, 1, 0, -1, -1, -1, -1, 0, 0, 0, 0, 0, 1};
    std::vector<int> c = FibonacciSort(input);
    for(auto i : c)
    {
        std::cout<<i<<std::endl;
    }
    return 0;
}

