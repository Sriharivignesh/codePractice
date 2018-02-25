class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        // First sort partition the array into two pieces:
        // First piece will have the positive numbers
        // Second will have the negative numbers.
        
        int positive_end = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > 0)
            {
                std::swap(nums[i], nums[positive_end]);
                positive_end++;
            }
        }
        
        for(int i = 0; i < positive_end; i++)
        {
            int number = std::abs(nums[i]);
            if((number - 1) < positive_end)
            {
                nums[number - 1] = nums[number - 1] < 0? nums[number - 1]: -nums[number - 1];
            }
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > 0)
            {
                return (i + 1);
            }
        }
        return positive_end + 1;
        
    }
};
