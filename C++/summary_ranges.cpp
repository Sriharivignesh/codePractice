class Solution {
public:
    std::vector<string> summaryRanges(std::vector<int>& nums) {
        int size = nums.size();
        std::vector<std::string> ranges;
        
        if(size == 1)
        {
            ranges.push_back(std::to_string(nums[0]));
            return ranges;
        }

        int range_start = 0;
        int last = 0;

        for(int i = 0; i < size; i++)
        {
            if(i == 0)
            {
                range_start = nums[i];
                last = nums[i];
                //temp.push_back(std::to_string(nums[i]));
            }
            else if(i == (size - 1))
            {
                if(nums[i] != (last + 1))
                {
                    if(range_start == last)
                    {
                        // Just push lone number into ranges
                        ranges.push_back(std::to_string(last));
                        ranges.push_back(std::to_string(nums[i]));
                    }
                    else
                    {
                        // Push range in a->b format into ranges
                        ranges.push_back(std::to_string(range_start) + "->" + std::to_string(last));
                        ranges.push_back(std::to_string(nums[i]));
                    }
                }
                else
                {
                    ranges.push_back(std::to_string(range_start) + "->" + std::to_string(nums[i]));
                }
            }
            else
            {
                if(nums[i] != (last + 1))
                {
                    if(range_start == last)
                    {
                        // Just push lone number into ranges
                        ranges.push_back(std::to_string(last));
                        last = nums[i];
                        range_start = nums[i];
                    }
                    else
                    {
                        // Push range in a->b format into ranges
                        ranges.push_back(std::to_string(range_start) + "->" + std::to_string(last));
                        last = nums[i];
                        range_start = nums[i];
                    }
                }
                else
                {
                    last = nums[i];
                }
            }
        }
        return ranges;
    }
};
