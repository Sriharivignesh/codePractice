/* https://www.hackerrank.com/challenges/the-love-letter-mystery?h_r=next-challenge&h_v=zen */


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
    for(int i = 0; i < number; i++)
    {
        string input_string;
        cin>>input_string;
        int length =  input_string.length(); 
        int operations = 0;   
        for(int i = 0;i < length/2; i++)
        {
            if(input_string[i] == input_string[length -1 - i])
            {
                continue;
            }
            else if(input_string[i] < input_string[length -1 - i])
            {
                operations = operations + (input_string[length -1 - i] - input_string[i]);
            }
            else
            {
                operations = operations + (input_string[i] - input_string[length -1 - i]);
            }
        }
        cout<<operations<<endl;
    }
    return 0;
}

