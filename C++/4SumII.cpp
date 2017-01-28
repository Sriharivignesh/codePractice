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
    void helper(std::vector<int> &P, std::vector<int> &Q, int s, std::unordered_map<int, int> &c)
    {
        for(int i = 0; i < s; i++)
        {
            for(int j = 0; j < s; j++)
            {
                c[P[i] + Q[j]]++;
            }
        }
    }
    int fourSumCount(std::vector<int>& A, std::vector<int>& B, std::vector<int>& C, std::vector<int>& D) {
        int size = A.size();
        int answer = 0;
        std::unordered_map<int, int> c1; 
        std::unordered_map<int, int> c2;
        helper(A, B, size, c1);
        helper(C, D, size, c2);
        for(auto i = c1.begin(); i != c1.end(); i++)
        {
           auto k = c2.find(-1 * (i -> first));
           if(k != c2.end())
           {
               answer += (i -> second * k -> second);
           }
        }
        return answer;
    }
};


//Write your own main function please