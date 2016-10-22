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
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_map<int, int> container;
        for(auto i : nums)
        {
            container[i]++;
            if(container[i] > 1)
            {
                return 1;
            }
        }
        return 0;
        
    }
};


int main()
{
    Solution s1;
    std::vector<int> input_vec = {1,1,1,1,1};
    std::cout << s1.containsDuplicate(input_vec) << "\n";
    return 0;
}