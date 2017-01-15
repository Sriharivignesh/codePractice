//Solution is very simple. I am using sliding window method. Whenever we encounter a 1, we increment 'end'.
// Whenever we encounter a 0, we check count of 0. if it is more than 1, we make start equal to last checkpoint which is the index after the index at which the last 0 was encountered

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
    int findMaxConsecutiveOnes(std::vector<int>& nums) {
        int count = 0;
        int result = 0;
        int start = 0;
        int end = 0;
        int checkpoint = 0; //Store the next index after the 0 that is included in the window
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 1)
            {
                end++;
            }
            else
            {
                    end++;
                    count++;
                    if(count > 1)
                    {
                        start = checkpoint;
                        count = 1;
                    }
                    checkpoint = i + 1;
            }
            if(((end - start)) > result)
            {
                result = ((end - start));
            }
        }
        return result;
    }
};

int main()
{
    Solution s1;
    std::vector<int> k = {1,0,1,1,0,1};
    std::cout << s1.findMaxConsecutiveOnes(k) << "\n";
    return 0;
}