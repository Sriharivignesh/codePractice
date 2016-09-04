// https://codefights.com/challenge/HTPdz8fy2hiZGAXbJ/main
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
#include <fstream>
#include <cstdint>
#include <boost/unordered_map.hpp>
#include <random>

/* GOLFED VERSION - REQUIRES SPECIAL COMPILER FLAGS TO COMPILE PROPERLY - WORKS FINE ON CODEFIGHTS IDE
int k,i = 2,s,offsets(auto c) {
    for(k = c[0]- '0'; i < c.length(); i++)
        s += (c[i] - '0') - (c[i - 1] - '0');
return s + k; 
}*/

int offsets(std::string c) {
    int k = 0;
    int i = 2;
    int s = 0;
    for(k = c[0]- '0'; i < c.length(); i++)
        s += (c[i] - '0') - (c[i - 1] - '0');
return s + k; 
}

int main()
{
    std::cout<<offsets("87508255625608756473598067564539098796745385764539788787774538607500090907960580576752365875213")<<"\n";
    return 0;
}