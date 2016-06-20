/* https://leetcode.com/problems/longest-increasing-subsequence/ */

/*  References - Tushar Roy - LIS */

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>
#include <limits>


class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        int size = nums.size();
        if(size == 0)
        {
            return 0;
        }
        if(size == 1)
        {
            return 1;
        }
        if(size == 2)
        {
            if(nums[0] < nums[1])
            {
                return 2;
            }
            else
            {
                return 1;
            }
        }
        int max = 1;
        int index[size];
        index[0] = 1;
        /*for(int i = 0; i < size; i++)
        {
            index[i] = 1;
        }*/
        for(int i = 1; i < size; i++)
        {
            index[i] = 1;
            for(int j = 0; j < i; j++)
            {
                if(nums[i] > nums[j])
                {
                    if(index[i] < (1 + index[j]))
                    {
                        index[i] = 1 + index[j];
                    }
                    if(index[i] > max)
                    {
                        max = index[i];
                    }
                }
            }
        }
        return max;
    }
};


int main() {
   std::vector<int> input_vector = {
       1,1,1,1,1,1,1,1,101,1,1,1,1,1,1,1,1
    };

    Solution s1;
    std::cout<<s1.lengthOfLIS(input_vector)<<std::endl;
    return 0;
}

