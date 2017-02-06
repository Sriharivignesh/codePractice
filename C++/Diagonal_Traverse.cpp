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
    std::vector<int> findDiagonalOrder(std::vector<std::vector<int>> &matrix) {
        std::vector<int> result;
        if(matrix.empty())
        {
            return {};
        }
        int column = matrix[0].size();
        int row = matrix.size();
        std::vector<std::vector<int>> lookup(row+column);
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < column; j++)
            {
                lookup[i + j].push_back(matrix[i][j]);
            }
        }
        for(int i = 0; i < (row + column); i++)
        {
            if(i % 2 == 0)
            {
                result.insert(result.end(), lookup[i].rbegin(), lookup[i].rend());
            }
            else
            {
                result.insert(result.end(),lookup[i].begin(), lookup[i].end());
            }
        }
        return result;
        
    }
};

int main()
{
    Solution s1;
    std::vector<std::vector<int>> input = {{2,5,8},{4,0,-1}};
    auto p = s1.findDiagonalOrder(input);
    for(auto i : p )
    {
        std::cout << i << ",";
    }
    return 0;
}