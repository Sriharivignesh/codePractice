/* https://codefights.com/challenge/yhN2jyWsWDTWA4qnW/main */

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>
#include <limits>
#include <stack>

int FactorialSum(int n) {
    int result = 0;
    long t = tgamma(n + 1); //tgamma function returns factorial of a number when the argument is number + 1
    if(n > 8 && t%10) // Doing this check as some factorial result like 12! is one short of the actual value for some reason.
        t+=1; // Adding one if the last digit is not 0. Exloiting the fact that factorials above 5 end in 0
    while(t)
    {
        result+=(t%10);
        t/=10;
    }
    return result;
}

int main()
{
    std::cout<<FactorialSum(13)<<std::endl;
    return 0;
}

