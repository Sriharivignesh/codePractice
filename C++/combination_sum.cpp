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
    std::vector<std::vector<int>> selector(std::vector<int>& candidates, int target)
    {
         // In a while loop keep adding the same number and calling the spliced list
         // recursively. Append any results to the vector and send it back.
        std::vector<std::vector<int>> result; 
        
        for(int i = 0; i < candidates.size(); i++)
	{   
            std::vector<int> working;
            int add_sum = 0;
         
            while(true)
            {
                add_sum += candidates[i];
                if(add_sum > target)
                    break;

                working.push_back(candidates[i]);
            }
       }                
                          
    } 
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) 
    {
        candidates = initialiser(candidates, target);
        return selector(candidates, target);
    }
};


int main()
{
    return 0;
}
