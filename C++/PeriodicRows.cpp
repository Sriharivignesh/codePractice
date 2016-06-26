/* https://codefights.com/challenge/uPYiZqNFE3n2LiLpg/main */

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>
#include <limits>
#include <stack>

#define h return
int PeriodicRows(int n) {
    if(n <3)
        h 1;
    if(n < 11)
        h 2;
    if(n < 19)
        h 3;
    if(n < 37)
        h 4;
    if(n < 55)
        h 5;
    if(n < 87)
        h 6;
    if(n < 119)
        h 7;
    h 0;
}
#undef return

int main()
{
    std::cout<<PeriodicRows(36)<<std::endl;
    return 0;
}

