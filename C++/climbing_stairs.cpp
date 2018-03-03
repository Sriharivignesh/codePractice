// This TLEs unfortunately.

#include <iostream>


class Solution {
public:
    int climbStairs(int n) {
        if(n < 1)
        {
            return 0;
        }
        if(n == 1)
        {
            return 1;
        }
        if(n == 2)
        {
            return 2;
        }
        int one_steps = (climbStairs(n - 1));
        int two_steps = (climbStairs(n - 2));
        
        return one_steps + two_steps;
    }
};


int main()
{
    Solution s1;
    std::cout << s1.climbStairs(44) << "\n";
    return 0;
}
