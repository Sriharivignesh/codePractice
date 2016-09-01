// https://codefights.com/challenge/MJvns2CuaTzeuRZbs/main
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

/* GOLFED CODE
int s, treeIsFull(auto q) {
    for( i : q)
        s += 1024 * pow(0.5,i);
    return s == 1024;

}*/

int treeIsFull(std::vector<int> q) {
    int s = 0;
    for(auto i : q)
    {
        s += 1024 * pow(0.5,i);
    }
    return s == 1024;
}




int main()
{
    std::cout<<treeIsFull({5, 5, 2, 3, 3, 4, 3, 2});
    return 0;
}