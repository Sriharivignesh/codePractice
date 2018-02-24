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
    std::vector<std::vector<int>> selector(std::vector<int>& candidates, int target, int index)
    {
         // In a while loop keep adding the same number and calling the spliced list
         // recursively. Append any results to the vector and send it back.
        std::vector<std::vector<int>> result; 
        
        for(int i = index; i < candidates.size(); i++)
	{
            std::vector<std::vector<int>> working;
            std::vector<int> dups;
            int add_sum = 0;
         
            while(true)
            {     
                add_sum += candidates[i];
                if((add_sum > target) || ((target - add_sum) < candidates[i]))
                    break; 
                // Send call to recursion, get the result and append
                dups.push_back(candidates[i]);
                for(int j = i; j < candidates.size(); j++)
                {
                    std::vector<std::vector<int>> temp = selector(candidates, target - (add_sum + (i == j) ? 0 : candidates[j]), j + 1);
                    
                    // Append the dups to the retuned temp vector of vectors
                    for(int k = 0; k < temp.size(); k++)
                    {
                        temp[k].insert(temp[k].end(), dups.begin(), dups.end());
                        result.push_back(temp[k]);
                    }
               }
           }
       }
 //      if(std::binary_search(candidates.begin() + index, candidates.end(), target))
//           result.push_back({target});
       return result;                
                          
    }
 
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) 
    {
        candidates = initialiser(candidates, target);
        return selector(candidates, target, 0);
    }
};


int main()
{
    std::vector<int> input = {2, 3, 6, 7};
    int target = 7;
    
    Solution s;
    std::vector<std::vector<int>> ret = s.combinationSum(input, target);
    for(int i = 0; i < ret.size(); i++)
    {
        for(int j = 0; j < ret[i].size(); j++)
        {
            std::cout << ret[i][j] << "\t";
        }
        std::cout << "\n";
    }
    return 0;
}
