/* https://www.hackerrank.com/challenges/make-it-anagram */

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    std::string s1 = "";
    std::string s2 = "";
    int l1 = 0;
    int l2 = 0;
    int count = 0;
    std::unordered_map<char,int> char_count1; //Keep character count for all characters in string 1
    std::unordered_map<char,int> char_count2; //Keep character count for all characters in string 2
    std::cin>>s1;
    std::cin>>s2;
    l1 = s1.length();
    l2 = s2.length();
    for(int i = 0; i < (l1>=l2?l1:l2); i++)
        {
        if(i < l1)
            {
            char_count1[s1[i]]++;
        }
        if(i < l2)
            {
            char_count2[s2[i]]++;
        }
    }
    for(int i = 0; i < 26; i++) //Iterating through the alphabet is enough. Otherwise it could be slow if the length of any of the 2 strings is above 26
        {
        if(char_count1[char(i +97)] != char_count2[char(i +97)])
            {
            count = count + abs(char_count1[char(i +97)] - char_count2[char(i +97)]); //Just the difference between the count of characters need to be deleted.
        }
    }
    std::cout<<count<<std::endl;
    
    
    return 0;
}