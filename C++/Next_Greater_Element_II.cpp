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
    std::vector<int> nextGreaterElements(std::vector<int>& nums) {
        int size = nums.size();
        for(int i = 0; i < size; i++)
        {
            nums.push_back(nums[i]);
        }
        std::stack<int> nge;
        std::stack<int> index;
        std::vector<int> result(size);
        std::fill(result.begin(), result.end(), INT_MIN);
        for(int i = 0; i < nums.size(); i++)
        {
            if(nge.empty() || nums[i] < nge.top())
            {
                nge.push(nums[i]);
                index.push(i);
            }
            else
            {
                while(!nge.empty() && nums[i] > nge.top())
                {
                    auto p = nge.top();
                    auto k = index.top();
                    if(k < size)
                        result[k] = nums[i];
                    else
                        result[k - size] = nums[i];
                    nge.pop();
                    index.pop();
                }
                nge.push(nums[i]);
                index.push(i);
            }
        }
        while(!nge.empty())
        {
            auto p = index.top();
            if(result[(p>=size)?(p-size):p] == INT_MIN)
            {
                if(p >= size)
                    result[p - size] = -1;
                else
                    result[p] = -1;
            }
            nge.pop();
            index.pop();
        }
        return result;
    }
};

int main()
{
    Solution s1;
    std::vector<int> k = {5,4,3,2,1};
        k = s1.nextGreaterElements(k);
        for(auto i : k)
        {
            std::cout << i << "\n";
        }
    return 0;
}