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

class Solution {
public:
    int findPairs(std::vector<int> nums, int k) {
        if(k < 0)
        {
            return 0;
        }
        std::unordered_map<int, int> lookup;
        std::unordered_set<int> done_lookup;
        int total = 0;
        for(auto i : nums)
        {
            lookup[i]++;
        }
        for(auto i : lookup)
        {
            if(k == 0)
            {
                if(i.second >= 2)
                {
                    total += 1;
                }
                done_lookup.insert(i.first);
                continue;
            }
            if(lookup.count(i.first - k))
            {
                if(!done_lookup.count(i.first - k))
                {
                    if(i.second && lookup[i.first - k])
                    {
                        total += 1;
                    }
                }
            }
            if(lookup.count(i.first + k))
            {
                if(!done_lookup.count(i.first + k))
                {
                    if(i.second >= 1 && lookup[i.first + k])
                    {
                        total += 1;
                    }
                }
            }
            done_lookup.insert(i.first);
        }
        return total;
    }
};

int main()
{
    Solution s1;
    std::cout << s1.findPairs({1,1,1,1,1,1,1}, 0) << "\n";
    //std::cout << s1.largestPalindrome(4) << "\n";
    return 0;
}