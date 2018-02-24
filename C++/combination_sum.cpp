#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    std::vector<int> initialiser(std::vector<int> &candidates, int target)
    {
        // Get rid of any number more than the target value and get rid of duplicates
        std::vector<int> temp;
        std::unordered_map<int, bool> lookup;

        for(int i: candidates)
        {
            if(i <= target)
            {
                if(!lookup.count(i))
                {
   		    temp.push_back(i);
                    lookup[i] = true;
                }
            }
        }

       // Sort the array
       std::sort(temp.begin(), temp.end());

       return temp;
    } 
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) 
    {
        candidates = initialiser(candidates, target);
    }
};


int main()
{
    return 0;
}
