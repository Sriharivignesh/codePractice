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

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        if(amount == 0)
        {
            return 0;
        }
        std::vector<int> working(amount + 1);
        for(int i = 0; i < amount + 1; i++)
        {
            working[i] = INT_MAX;
        }
        working[0] = 0;
        for(int i = 0; i < coins.size(); i++)
        {
            for(int j = 1 ; j < amount + 1; j++)
            {
                if(coins[i] > j)
                {
                    continue;
                }
                if(working[j - coins[i]] != INT_MAX)
                working[j] = std::min(working[j], 1 + working[j - coins[i]]);
            }
        }
        if(working[amount] == INT_MAX)
        {
            return -1;
        }
        return working[amount];
        
    }
};


int main()
{
  Solution s1;
  std::vector<int> coins = {2};
  int total = 3;
  std::cout << s1.coinChange(coins, total) << "\n";
  return 0;
}