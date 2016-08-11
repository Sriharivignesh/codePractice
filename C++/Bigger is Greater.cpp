/*https://www.hackerrank.com/challenges/bigger-is-greater */

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


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n = 0;
    std::cin>>n;
    for(int i = 0; i < n; i++)
        {
        std::string s = "";
        std::cin>>s;
        bool y = std::next_permutation(s.begin(), s.end());
            if(y)
            {
            std::cout<<s<<std::endl;
        }
        else
            {
            std::cout<<"no answer"<<std::endl;
        }
    }
    return 0;
}

