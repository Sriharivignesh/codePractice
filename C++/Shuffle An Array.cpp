// https://leetcode.com/problems/shuffle-an-array/

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

//I don't use namespace std, but here i was too lazy to add std:: to every std container.
using namespace std;

class Solution {
public:
    Solution(vector<int> nums) {
        working = nums;
        original = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        working = original;
        return working;
        
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        //std::next_permutation(working.begin(), working.end());
        std::random_shuffle ( working.begin(), working.end() );
        return working;
    }
    
    std::vector<int> original;
    std::vector<int> working;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */


int main()
{
    std::vector<int> index = {1,2,3,4,5,6,7,8};
    std::vector<int> temp;
    Solution s(index);
    //s.Solution(index);
    temp = s.shuffle();
    std::cout<<"Shuffle1:";
    for(auto k : temp)
    {
        std::cout<<k<<",";
    }
    std::cout<<"--------------------------------"<<"\n";
    temp = s.shuffle();
    std::cout<<"Shuffle2:";
    for(auto k : temp)
    {
        std::cout<<k<<",";
    }
    return 0;
}

