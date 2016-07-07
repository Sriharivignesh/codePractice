/* https://codefights.com/challenge/3eZwiyP6btWXDxohS/main */

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>
#include <limits>
#include <stack>
#include <iterator>

std::vector<int> NarcissisticNumber(int s, int f) 
{
    std::vector<int> b;
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9,153, 370, 371, 407,1634, 8208, 9474}; //There are only 88 narcissistic numbers. They can be gotten from Wolfram website. No need to calculate them again
    for(auto i:a)
    {
        if(i >= s && i <=f)
            b.push_back(i);
    }
    return b;
}


//LESS CHARACTER VERSION 
/*std::vector<int> b,NarcissisticNumber(int s, int f) 
{
    //std::vector<int> b;
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9,153, 370, 371, 407,1634, 8208, 9474};
    for(auto i:a)
    {
        if(i >= s && i <=f)
            b.push_back(i);
    }
    return b;
}*/

int main()
{
    std::vector<int> c = NarcissisticNumber(1,99);
    for(auto i : c)
    {
        std::cout<<i<<std::endl;
    }
    return 0;
}

