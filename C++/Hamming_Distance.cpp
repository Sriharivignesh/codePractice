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
#include <random>
#include <valarray>
#include <numeric>
#include <sstream>

class Solution {
public:
    int hammingDistance(int x, int y) {
        int k = x^y;
        int distance = 0;
        while(k)
        {
            distance++;
            k = k & (k - 1);
        }
        return distance;
        
    }
};

int main()
{
    Solution s1;
    std::cout << s1.hammingDistance(2, 4) << "\n";
    return 0;
}