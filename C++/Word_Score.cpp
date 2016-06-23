

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>
#include <limits>
#include <stack>


int WordScore(auto w) {
    int r = 0;
    for(i:w)
        r+=i - 96;
    return r;
}

int main()
{
    std::cout<<WordScore("jumps")<<std::endl;
    return 0;
}

