/* https://codefights.com/challenge/SZRtfwnjeBTyk9yy5/main */
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>
#include <limits>
#include <stack>
#include <iterator>

int helptoclone(std::vector<int> A) {
    int j = 0;
    int count= 0;
    int size = A.size();
    for(auto i:A)
    {
        if(i%2==0)
        {
            count += (size - j++ -1);
        }
    }
    return count;
}

/* GOLFED VERSION - CODEFIGHTS IDE INITIALISES ALL INTEGERS TO 0. A.size() takes constant time.
int j,c,helptoclone(auto A) {
    for(i:A)
            i%2==0?c+=A.size() - j++ -1:1;
    return c;
}
*/


int main()
{
    std::vector<int> input = {9999, 78, 1, 3, 5, 9, 11}; 
    std::cout<<helptoclone(input)<<std::endl;
    return 0;
}

