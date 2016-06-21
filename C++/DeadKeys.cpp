/* https://codefights.com/challenge/3b7NFtFTf9ie9GBDs/main */

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>
#include <limits>


int DeadKeys(std::string keys, char target, std::vector<std::string> menu) {
    
    char current = menu[0][0]; //Keep track of index character to facilitate comparisons
    int maximum_steps= 9000;  //The result to be returned. Initialise to arbitrary large value
    int previous_count = 0;   // To keep count of number of words with same lexicographic index to compute maximum steps
    int maximum_size = menu[0].length(); //To keep track of word with least length in the same lexicographic index range
    int i = 0;  //Loop iterator variable
    std::unordered_map<char,bool> options; //To check what all characters are available in the 'keys'
    for(i = 0; i < keys.length(); i++)
    {
        options[keys[i]] = 1;
    }
    for(i = 0; i < menu.size(); i++)
    {
        if(menu[i][0] == current && i != 0) // i != 0 because we don't want to increase 'previous_count' if the first word itself fulfils all the conditions
        {
            previous_count++;
            if(maximum_size > menu[i].length())
            {
                maximum_size = menu[i].length();
            }
        }
        else
        {
            previous_count = 0; // We enter new lexicographic index, so we reset count to 0
            current = menu[i][0]; //Change 'current' to new lexicographic index variable
            maximum_size = 90000; 
        }
       if(menu[i].find(target) != std::string::npos && options[menu[i][0]])
       {
           if(previous_count == 0)
           {
               return 1;
           }
           int letter = 1; //To keep track of number of letters iterated through in 'menu[i]'
           if(maximum_steps > (previous_count + 1))
           {
               maximum_steps = previous_count + 1;
           }
           while(letter < maximum_size)
           {
               int word_count = 0;
               if(menu[i][letter] == target)
               {
                   break;
               }
               if(options[menu[i][letter]] == 1)
               {
                   for(int j = 1; j <= previous_count; j++)
                   {
                       if(menu[i-j][letter] == menu[i][letter])
                       {
                           word_count++;
                       }
                   }
                   if(maximum_steps > (word_count + 1 + letter))
                   {
                       maximum_steps = word_count + 1 + letter;
                   }
                   letter++;
               }
               else
               {
                   break;
               }
           }  
       }
    }
    return maximum_steps;
}


int main()
{
    std::vector<std::string> input_menu;
    std::string input_key = "abcdfghjklmnstvxyz";
    char input_target = 'o';
    input_menu.push_back("string");
    input_menu.push_back("true");
    input_menu.push_back("try");
    input_menu.push_back("typeof");
    input_menu.push_back("var");
    input_menu.push_back("void");
    input_menu.push_back("while");
    input_menu.push_back("with");
    std::cout<<DeadKeys(input_key,input_target,input_menu)<<std::endl;
    return 0;
}

