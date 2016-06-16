#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int test_cases = 0;
    cin>>test_cases;
    for(int i = 0; i < test_cases; i++)
        {
        string s = "";
        bool result = 1;
        cin>>s;
        int length = s.length();
        string r = s;
        reverse(r.begin(),r.end());
        for(int j = 1; j < length; j++)
            {
            if(abs(s[j] - s[j-1]) != abs(r[j] - r[j-1]))
                {
                cout<<"Not Funny"<<endl;
                result = 0;
                break;
            }
        }
            if(result)
                {
                cout<<"Funny"<<endl;
            } 
        }
    return 0;
}