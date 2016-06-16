/* https://www.hackerrank.com/challenges/anagram */

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int test_cases = 0;
    cin>>test_cases;
    while(test_cases--)
        {
        string s = "";
        cin>>s;
        int length = s.length();
        int count = 0;
        if(length%2 != 0)
            {
            cout<<-1<<endl;
            continue;
        }
        unordered_map<char,int> first_half;
        unordered_map<char,int> second_half;
        for(int i = 0; i < (length/2); i++)
            {
             first_half[s[i]]++;
            second_half[s[length-1-i]]++;
        }
        for(int i = 0; i <26;i++)
            {
            if(first_half[char(97 + i)] < second_half[char(97 + i)])
                {
                count = count + (second_half[char(97 + i)] - first_half[char(97 + i)]);
            }
        }
        cout<<count<<endl;
        
    }
    return 0;
}