/* https://www.hackerrank.com/challenges/game-of-thrones */

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>


int main() {

    int flag = 1;
    bool once = 0;
    std::unordered_map<char,int> char_count;
    std::string s;
    std::cin>>s;
    // Assign Flag a value of 0 or 1 depending on whether or not you find what you are looking for, in the given string 
    for(int i = 0; i < s.length(); i++)
        {
        char_count[s[i]]++;
    }
    for(int i = 0; i < 26; i++) //No need to iterate over the length of the string again since there are only 26 characters in the alphabet. Makes sense to iterate through the alphabet rather than the string since the string could be much longer.
        {
        if(char_count[(char)(i + 97)]%2 != 0)
            {
            if(once)
                {
                flag = 0;
                break;
            }
            else
                {
                once = 1;
            }
        }
    }
    if(flag==0)
        std::cout<<"NO"<<std::endl;
    else
        std::cout<<"YES"<<std::endl;
    return 0;
}