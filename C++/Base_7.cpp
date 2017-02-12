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
    std::string convertTo7(int num) {
        bool negative = 0;
        if(num < 0)
        {
            negative = 1;
            num = -1 * num;
        }
        std::stack<int> keeper;
        while(num)
        {
            keeper.push(num%7);
            num /= 7;
        }
        int temp = 0;
        while(!keeper.empty())
        {
            temp *= 10;
            temp += keeper.top();
            keeper.pop();
        }
        return std::to_string(negative?(-1 * temp):temp);
        
    }
};

int main()
{
    Solution s1;
    std::cout << s1.convertTo7(100) << "\n";
    return 0;
}