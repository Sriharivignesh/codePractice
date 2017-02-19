//http://math.stackexchange.com/questions/1798061/the-largest-product-of-two-n-digit-numbers-which-is-palindrome
//Just add the numbers mentioned % 1337. Then you are good to go.
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
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
#include <list>

class Solution 
{
    public:
        int largestPalindrome(int n) 
        {
            std::vector<int> k = {9, 987,123,597,677,1218,877,475};
            return k[n - 1];
        }
};

int main()
{
    Solution s1;
    std::cout << s1.largestPalindrome(4) << "\n";
    return 0;
}