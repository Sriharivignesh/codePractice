/* https://leetcode.com/problems/implement-strstr/ */
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        int l1 = haystack.length();
        int l2 = needle.length();
        if(needle == haystack)
        {
            return 0;
        }
        if(l2 >= l1)
        {
            return -1;
        }
        if(l2 == 0)
        {
            return 0;
        }
        if(l1 == 0 && l2 == 0)
        {
            return 0;
        }
        if(l1 == 0 && l2 != 0)
        {
            return -1;
        }
        for(int i = 0; i < l1; i++)
        {
            bool got_it = 1;
            if(haystack[i] == needle[0])
            {
                for(int j = 0; j < l2; j++)
                {
                    if(i+j >= l1)
                    {
                        got_it = 0;
                        break;
                    }
                    if(needle[j] != haystack[i + j])
                    {
                        got_it = 0;
                        break;
                    }
                }
                if(got_it)
                {
                    return i;
                }
            }
        }
       return -1; 
    }
};


int main()
{
    std::string haystack = "mississipi";
    std::string needle = "issip";
    Solution s1;
    std::cout<<s1.strStr(haystack, needle)<<std::endl;
    return 0;
}