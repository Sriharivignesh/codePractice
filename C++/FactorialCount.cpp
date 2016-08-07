/* https://leetcode.com/problems/top-k-frequent-elements/ */

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>
#include <limits>
#include <stack>
#include <iterator>
#include <set>
#include <queue>
#include <sstream>
#include <stdlib.h>

//FORMULA FOR THIS PROBLEM CAN BE FOUND HERE - http://oeis.org/A034968


//GOLFED VERSION - REQUIRES COMPILER TWEAKING TO MAKE IT RUN. GOLFED CODE RUNS EXECUTES SUCCESSFULLY ON CODEFIGHTS IDE
/*int r,k=2,FactorialCount(int n) {
    for(;n;n/=k++)
        r+=n%k;
    return r;
}*/

int FactorialCount(int n) {
    int r = 0; 
    int k = 2;
    for(;n;)
    {
        r+=n%k;
        n/=k;
        k++;
    }
    return r;
}


int main()
{ 
    std::cout<<FactorialCount(100)<<std::endl;

    return 0;
}