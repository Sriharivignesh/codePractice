/* DOESNT WORK YET...AM WORKING ON IT*/

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
    //(number<=1)?(return 0):;  
    bool letter_index[number][26];
    vector <string> input_string(number);
    int minimum = 500;
    int index = 0;
    int count = 0;
    for(int i = 0; i < number; i++)
    {
        cin>>input_string[i];
        int length = input_string[i].length();
        if(length < minimum)
        {
            minimum = length;
            index = i;
        }
        for(int j = 0; j < length; j++)
        {
            if(input_string[i][j] >= 97 && input_string[i][j] <=122)
            {
                letter_index[i][input_string[i][j] - 97] = 1;
            }
        }
    }
    for(int i = 0; i < minimum; i++)
    {
        bool index_check = 1;
        for(int j = 0; j < number; j++)
        {
            if(letter_index[j][input_string[index][i] - 97] != 1)
            {
                index_check = 0;
                cout<<"Breaking from index"<<endl;
                break;
            }
            else
            {
                
            }
        }
        if(index_check == 1)
        {
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}
