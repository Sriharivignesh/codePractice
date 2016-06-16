/* https://www.hackerrank.com/challenges/two-strings */

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int test_cases = 0;
    std::cin>>test_cases;
    while(test_cases--)
        {
        bool first[26] = {0};
        bool second[26] = {0};
        bool set = 1;
        std::string s1 = "";
        std::string s2 = "";
        std::cin>>s1;
        std::cin>>s2;
        int l1 = s1.length();
        int l2 = s2.length();
        int i = 0;
        for(i = 0; i < (l1>=l2?l1:l2);i++)
            {
            if(i < l1)
                {
                first[(int)s1[i] - 97] = 1;
            }
            if(i < l2)
                {
                second[(int)s2[i] - 97] = 1;
            }
        }
        for(i = 0; i < 26; i++)
            {
            if(first[i] == 1 && second[i] == 1)
                {
                std::cout<<"YES"<<std::endl;
                set = 0;
                break;
            }
        }
        if(set)
            {
            std::cout<<"NO"<<std::endl;
        }
    }
    return 0;
}