/* https://codefights.com/challenge/sMP85aZRQeFfjHDR4/main */

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>


std::vector<std::string> printPyramid(int count, bool direction) {
    std::vector<std::string> result;
    for(int i = 1; i <= count; i++)
    {
        std::string s= "";
       if(direction)
        {
            for(int j = 1; j <= i; j++)
            {
                s = s + '*';
            }
           result.push_back(s);
        }
        else
        {
            for(int j = 1; j <= (count - i + 1); j++)
            {
                s = s + '*';
            }
            result.push_back(s);
        }
    }
    return result;
}
int main()
{
    std::vector<std::string> pattern;
    pattern = printPyramid(4,1);
    for (std::vector<std::string>::iterator it = begin (pattern); it != end (pattern); it++) {
        std::cout<<*it<<std::endl;
}
return 0;
}