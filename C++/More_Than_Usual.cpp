/* https://codefights.com/challenge/yheqsAwQnHmtoA8h4/main */

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>
#include <limits>



int moreThanUsual(int n) {
    int s = 4;
    while(n>1)
    {
        s*=n;
        n--;
    }
    return s;
}

int main()
{
    std::cout<<moreThanUsual(5)<<std::endl;
    return 0;
}

