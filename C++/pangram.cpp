/* https://www.hackerrank.com/challenges/pangrams */
  /*
    ASCII Value of 'a' is 97
    ASCII Value of 'z' is 122
    ASCII Value of 'A' is 65
    ASCII Value of 'Z' is 90  */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    bool letters[26];
    string input_string;
    getline(std::cin, input_string);
    int length = input_string.length();
    if(length<26)
    {
        cout<<"not pangram"<<endl;
        return 0;
    }
    
    for(int i= 0; i<length;i++)
    {
        if((int)input_string[i] >= 97 && (int)input_string[i] <= 122)
        {
            letters[(int)input_string[i] - 97] = 1;
        }
        else if((int)input_string[i] >= 65 && (int)input_string[i] <= 90)
        {
            letters[(int)input_string[i] - 65] = 1;
        }
        else
        {
            continue;
        }
    }
    for(int i = 0;i<26;i++)
    {
        if(letters[i] == 0)
        {
            cout<<"not pangram"<<endl;
            return 0;
        }
    }
    cout<<"pangram"<<endl; 
    return 0;
}

