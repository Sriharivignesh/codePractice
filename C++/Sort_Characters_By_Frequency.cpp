//This method has O(nlogn) complexity. There is a simpler O(n) solution in the leetcode discussion boards.
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
    std::string frequencySort(std::string s) {
        std::string p = "";
        std::unordered_map<char, int> char_counter;
        std::multimap<int, char> rev_counter;
        for(auto i : s)
        {
            char_counter[i]++;
        }
        for(auto i : char_counter)
        {
            rev_counter.insert(std::pair<int, char> (i.second, i.first));
        }
        for(auto i = rev_counter.rbegin(); i != rev_counter.rend(); i++)
        {
            for(int k = 0; k < i -> first; k++)
            {
                p += i -> second;
            }
        }
        return p;
    }
};

int main()
{
    Solution s1;
    auto g = s1.frequencySort("bibbles");
    std::cout << g << "\n";
    return 0;
}