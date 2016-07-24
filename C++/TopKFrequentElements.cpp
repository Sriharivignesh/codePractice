/* https://leetcode.com/problems/top-k-frequent-elements/ */

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

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        int i = 0;
        std::vector<int> result;
        std::unordered_map<int,int> c_map;
        std::priority_queue<std::pair<int,int> > top_k;
        for(auto p : nums)
        {
            c_map[p]++;
        }
            for(auto iterator = c_map.begin(); iterator != c_map.end(); iterator++)
            {
                top_k.push(std::make_pair(iterator->second,iterator->first));
            }
            for(i = 0; i < k; i++)
            {
                result.push_back(top_k.top().second);
                top_k.pop();
            }
        
        return result;
        
    }

};

int main()
{
    std::vector<int> b = {1,1,1,2,2,2,3,5,5,6,100,14,15,16,1,2,44};
    Solution s1;
    std::vector<int> t = s1.topKFrequent(b,3);
    for(auto i : t)
    {
        std::cout<<i<<std::endl;
    }
    return 0;

}