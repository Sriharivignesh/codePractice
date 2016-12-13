//https://leetcode.com/problems/number-of-segments-in-a-string/

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
    int countSegments(std::string s) {
        int count = 0;
        bool char_before = 0;
        int length = 0;
        for(auto i : s)
        {
            if(isspace(i))
            {
                if(char_before && length > 0)
                {
                    count++;
                    char_before = 0;
                    length = 0;
                }
            }
            else
            {
                length++;
                char_before = 1;
            }
        }
        if(char_before && length)
        {
            count++;
        }
        return count;
    }
};

int main()
{
    Solution s1;
    std::cout << s1.countSegments("a, b, c") << "\n";
    return 0;
}