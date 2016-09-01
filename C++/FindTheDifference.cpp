// https://leetcode.com/problems/find-the-difference/
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
#include <boost/unordered_map.hpp>
#include <random>

class Solution {
public:
    char findTheDifference(std::string s, std::string t) {
        std::unordered_map<char,int> index1;
        std::unordered_map<char,int> index2;
        for(auto i : s)
        {
            index1[i]++;
        }
        for(auto i : t)
        {
            index2[i]++;
        }
        for(int i = 97; i <= 122; i++)
        {
            if(index2[(char)i] > index1[(char) i ])
            {
                return (char) i;
            }
        }
        return 'a';
    }
};





int main()
{
    Solution s;
    std::cout<<s.findTheDifference("abcd","abcde")<<"\n";
    return 0;
}