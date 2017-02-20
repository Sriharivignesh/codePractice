//
// Created by Sri Hari Vignesh on 19/02/17.
//

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
    int minMoves2(std::vector<int> nums) {
        std::sort(nums.begin(), nums.end());
        int size = nums.size();
        int sum = 0;
        for(int i = 0; i < size; i++)
        {
            sum += std::abs(nums[size/2] - nums[i]);
        }
        return sum;
    }
};


int main()
{
    Solution s1;
    std::cout << s1.minMoves2({1,2,3}) << "\n";
    return 0;
}



