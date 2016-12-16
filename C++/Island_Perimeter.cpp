//https://leetcode.com/problems/island-perimeter/

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
    int islandPerimeter(std::vector<std::vector<int>>& grid) {
        int perimeter = 0;
        int csize = grid[0].size();
        int rsize = grid.size();
        for(int i = 0; i < rsize; i++)
        {
            for(int j = 0; j < csize; j++)
            {
                if(grid[i][j] == 1)
                {
                    int temp = 4;
                    if((i-1) >= 0)
                    {
                        if(grid[i-1][j] == 1)
                        {
                            temp--;
                        }
                    }
                    if((i + 1) < rsize)
                    {
                        if(grid[i + 1][j] == 1)
                        {
                            temp--;
                        }
                    }
                    if((j - 1) >= 0)
                    {
                        if(grid[i][j - 1] == 1)
                        {
                            temp--;
                        }
                    }
                    if((j + 1) < csize)
                    {
                        if(grid[i][j + 1] == 1)
                        {
                            temp--;
                        }
                    }
                    perimeter += temp;
                }
            }
        }
        return perimeter;
        
    }
};

//IMPLEMENT YOUR OWN MAIN FUNCTION!