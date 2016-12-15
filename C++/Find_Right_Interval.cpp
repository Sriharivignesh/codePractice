//https://leetcode.com/problems/find-right-interval/
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

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    std::vector<int> findRightInterval(std::vector<Interval>& intervals) {
        std::unordered_map<int, int> check;
        std::vector<int> book(intervals.size());
        std::vector<int> find_check;
        for(int i = 0; i < intervals.size(); i++)
        {
            check[intervals[i].start] = i;
            find_check.push_back(intervals[i].start);
        }
        std::sort(find_check.begin(), find_check.end());
        for(int i = 0; i < intervals.size(); i++)
        {
            if(check.count(intervals[i].end))
            {
                book[i] = check[intervals[i].end];
            }
            else if(std::upper_bound(find_check.begin(), find_check.end(), intervals[i].end) != find_check.end())
            {
                auto k = std::upper_bound(find_check.begin(), find_check.end(), intervals[i].end);
                book[i] = check[*k];
            }
            else
            {
                book[i] = -1;
            }
        }
        
        return book;
    }
};


//IMPLEMENT MAIN FUNCTION YOURSELF