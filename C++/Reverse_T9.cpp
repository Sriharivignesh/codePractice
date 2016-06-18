/* https://codefights.com/challenge/JGNL3YRDqC7By3fbu/main */

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>
#include <limits>

std::string reverse_t9(std::string keys) {
    std::map<int,std::string> t9_map = {{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};
    std::string s = "";
    int length = keys.length();
    int count = 0;
    int number = -100;
    for(int i = 0; i < length; i++)
    {
        if(isspace(keys[i]))
        {
            if(i == 0)  //If space is the first character in the string, then just go to the next iteration in the loop
            {
                continue;
            }
            if(keys[i -1] == '0') //If the previous character is 0, then we don't have to do anything so just continue to the next iteration
            {
                continue;
            }
            s = s + t9_map.at(number).at(count - 1); //Otherwise add the typed letter to the result string using std::map
            count = 0;
        }
        else if(keys[i] == '0')
        {
            if(i == 0)
            {
                s = s + " ";
                continue;
            }
            if(isspace(keys[i - 1]))
            {
                s = s + " ";
                count = 0;
                continue;
            }
            s = s + t9_map.at(number).at(count - 1);
            s = s + " ";
            count = 0;
        }
        else if(number != (keys[i] - 48)) // char representation of 1 is 49 in ASCII. So from 1 - 9 it is easy to compare with int if we subtract 49 from the keys[i] char.
        {
            if(i != 0)
            {
                if(keys[i-1] != '0' && !isspace(keys[i - 1]))
                s = s + t9_map.at(number).at(count - 1);
                count = 0;
            }
            number = keys[i] - 48;
            count++;
        }
        else
        {
            number = keys[i] - 48;
            count++;
        }
        
    }
    if(length > 1)
    {
        if(keys[length - 1] != '0' && !isspace(keys[length - 1]))
        s = s + t9_map.at(number).at(count -1);
    }
    return s;
}


int main()
{
    std::cout<<reverse_t9("3330060555")<<std::endl;
    return 0;
}