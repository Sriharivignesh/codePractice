//https://leetcode.com/problems/assign-cookies/

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
#include <random>
#include <valarray>
#include <numeric>
#include <sstream>

class Solution {
public:
    int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
        int satisfied = 0;
        int cookie_last = 0;
        std::vector<bool> assigned(g.size());
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        for(int j = 0; j < s.size(); j++)
        {
            for(int i = cookie_last; i < g.size(); i++)
            {
                if(s[j] >= g[i])
                {
                    if(!assigned[i])
                    {
                        assigned[i] = 1;
                        satisfied++;
                        cookie_last++;
                    }
                }
                break;

            }
        }
        return satisfied;
        
    }
};

int main()
{
    Solution s1;
    std::vector<int> children_greed = {10, 9, 8, 7};
    std::vector<int> cookie = {5,6,7,8};
    std::cout << s1.findContentChildren(children_greed, cookie) << "\n";
    return 0;
}