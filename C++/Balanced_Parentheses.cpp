/* https://www.hackerrank.com/challenges/balanced-parentheses */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main()
{
    int number = 0;
    cin>>number;
    vector <string> string_array(number);
    for(int i = 0; i < number; i++)
    {
        string input_string;
        cin>>input_string;
        int length = input_string.length();
        stack<char> bracket_stack;
        if(length%2!=0)
        {
            string_array[i] = "NO";
            continue;
        }
        string_array[i] = "YES";
        for(int j = 0;j< length;j++)
        {
            if(input_string[j] == '{' || input_string[j] == '(' || input_string[j] == '[')
            {
                bracket_stack.push(input_string[j]);
            }
            else
            {
                if(bracket_stack.empty())
                {
                    string_array[i] = "NO";
                    break;
                }
                if(input_string[j] == '}' && bracket_stack.top() == '{')
                {
                    bracket_stack.pop();
                }
                else if(input_string[j] == ')' && bracket_stack.top() == '(')
                {
                    bracket_stack.pop();
                }
                else if(input_string[j] == ']' && bracket_stack.top() == '[')
                {
                    bracket_stack.pop();
                }
                else
                {
                    string_array[i] = "NO";
                    break;
                }
            }
         }
    }
    
    for(int i=0;i<number;i++)
    {
        cout<<string_array[i]<<endl;
    }
    return 0;
}