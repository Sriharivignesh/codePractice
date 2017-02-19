
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
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
#include <list>


class Solution {
public:
    bool checker(std::string a, std::string &b)
    {
        std::sort(a.begin(), a.end());
        return a == b;
    }
    std::vector<int> findAnagrams(std::string s, std::string p) {
        std::string psorted = p;
        std::sort(psorted.begin(), psorted.end());
        std::vector<int> result;
        int plength = p.length();
        int slength = s.length();
        int start = 0;
        int end = 0;
        std::string temp = "";
        std::unordered_set<char> lookup;
        std::unordered_map<std::string, bool> tcheck;
        tcheck[p] = 1;
        tcheck[psorted] = 1;
        lookup.reserve(plength);
        if(slength < plength)
        {
            return result;
        }
        for(int i = 0; i < plength; i++)
        {
            lookup.insert(p[i]);
        }
        for(; start <= (slength - plength) && end <= slength;)
        {
            if((end - start) == plength)
            {
                if(tcheck.count(temp) || checker(temp, psorted))
                {
                    result.push_back(start);
                    tcheck[temp] = 1;
                }
                temp.erase(temp.begin());
                start++;
            }
            if(lookup.count(s[end]))
            {
                temp.push_back(s[end++]);
            }
            else
            {
                start = end + 1;
                end = start;
                temp = "";
            }
        }
        return result;
    }
};