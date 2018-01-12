#include<iostream>
#include<vector>

class Solution {
public:
    bool checkPossibility(std::vector<int>& nums) {
        int count = 0;
        int size = nums.size();
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > nums[i + 1])
            {
                int temp = nums[i + 1];
                
                nums[i + 1] = nums[i];
                if(std::is_sorted(nums.begin(), nums.end()))
                {
                    return true;
                }
                
                nums[i] = temp;
                nums[i + 1] = temp;
                if(std::is_sorted(nums.begin(), nums.end()))
                {
                    return true;
                }
                return false;
            }
        }
        return true;
        
    }
};


int main()
{
    Solution s;
    std::vector<int> test = {1, 2, 3};
    std::cout << s.checkPossibility(test) << "\n";
    return 0;
}
