
/* https://codefights.com/challenge/qsRziH273jPy4p4ga/main */

/* I tried to code the shortest solution possible and this is the best I could do. It comes out to 390 chars if you don't count whitespace*/

/* The solution is simple - just use a stack */

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>
#include <limits>
#include <stack>

#define t break
#define q case

int RPN(std::string e) {    
    std::stack<int> r;
    int a,b,k,p,n = 0;
    std::map<char,bool> s{{'+',1},{'*',1},{'-',1},{'/',1},{'%',1},{'^',1}};
    for(char &d:e)
    {
        if(d == ' ')
        {
            if(k)
            r.push(n);
            n=0;
        }
        else if(s[d])
        {
            b = r.top();
            r.pop();
            a = r.top();
            r.pop();
            k = 0;
            switch(d)
            {
                q'+':p=a+b;t;
                q'-':p=a-b;t;
                q'*':p=a*b;t;
                q'/':p=a/b;t;
                q'%':p=a%b;t;
                q'^':p=pow(a,b);t;
            }
            //#undef case
            r.push(p);
        }
        else
        {
            n*= 10;
            n+=d - 48;
            k = 1;
        }
    }
    return r.top();
}

int main()
{
    std::cout<<RPN("4 0 3 - -")<<std::endl;
    return 0;
}

