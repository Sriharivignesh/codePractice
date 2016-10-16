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
    int trailingZeroes(int n) {
        int result = 0;
        for(long i = 5; i <= n; i*=5)
        {
            result += n/i;
        }
        return result;
    }
};
int main()
{
    Solution s;
  std::cout << s.trailingZeroes(25) << "\n";
  return 0;
}