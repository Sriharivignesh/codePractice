// https://leetcode.com/problems/next-permutation/
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


class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        if(!std::next_permutation(nums.begin(), nums.end()))
        {
            std::sort(nums.begin(), nums.end());
        }
        
    }
};

int main()
{
    Solution s1;
    std::vector<int> input = {1,2,3};
    s1.nextPermutation(input);
    for(auto i : input)
    {
        std::cout<<i<<"\n";
    }
    return 0;
}