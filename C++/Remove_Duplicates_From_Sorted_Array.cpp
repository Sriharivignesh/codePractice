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

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        auto k = std::unique(nums.begin(), nums.end());
        int count = 0;
        for(auto i = k; i != nums.end(); i++)
        {
            count++;
        }
        return nums.size() - count;
        
    }
};

int main()
{
    Solution s1;
    std::vector<int> input_container = {1,2,2,2,2,3,3,3,3,4,4,4,5};
    std::cout << s1.removeDuplicates(input_container) << "\n";
    return 0;
}