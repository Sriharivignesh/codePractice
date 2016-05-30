/* https://www.hackerrank.com/challenges/alternating-characters?h_r=next-challenge&h_v=zen */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int number = 0;
    cin>>number;
    for(int j = 0;j < number; j++)
    {
        string input_string;
        cin>>input_string;
        char current = input_string[0];
        int deletions = 0;
        for(int i = 1;i < input_string.length();i++)
        {
            if(input_string[i] == current)
            {
                deletions++;
            }
            else
            {
                current = input_string[i];
            }
        }
        cout<<deletions<<endl;
    }
    return 0;
}