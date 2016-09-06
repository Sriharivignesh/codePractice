// https://leetcode.com/problems/search-for-a-range/
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

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        auto begin = nums.begin();
        std::vector<int> return_vector;
        if(!std::binary_search(nums.begin(), nums.end(), target))
        {
            return {-1,-1};
        }
        auto low = std::lower_bound (nums.begin(), nums.end(), target);
        auto high = std::upper_bound(nums.begin(), nums.end(), target);
        return_vector.push_back(low - nums.begin());
        return_vector.push_back(high - nums.begin() - 1);
        return return_vector;
        
    }
};

int main()
{
    std::vector<int> input_vector = {-100, -1, 0, 1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 10};
    Solution s1;
    std::vector<int> output_vector = s1.searchRange(input_vector, 5);
    for(auto i : output_vector)
    {
        std::cout<<i<<"\n";
    }
    return 0;
}