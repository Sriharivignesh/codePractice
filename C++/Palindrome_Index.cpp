#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>

using namespace std;

bool is_palindrom(string r, int length)
{
    for(int i = 0; i < length/2; i++)
    {
        if(r[i] != r[length -1 -i])
        {
            return 0;
        }
    }
    return 1;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int test_cases = 0;
    cin>>test_cases;
    while(test_cases--)
        {
        string s = "";
        cin>>s;
        int length = s.length();
        int return_result = -1;
        for(int i = 0; i < length/2; i++)
            {
            if(s[i] != s[length -1 -i])
                {
                    string str = s;
                    str.erase (i,1);
                    if(is_palindrom(str,length -1))
                    {
                        return_result = i;
                        break;
                    }
                    else
                    {
                        return_result = length -1 -i;
                        break;
                    }
            }
            }  
        cout<<return_result<<endl;
    }
    return 0;
}

