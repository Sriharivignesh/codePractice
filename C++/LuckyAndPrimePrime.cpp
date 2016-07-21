/* https://codefights.com/challenge/doXskkj8PMAJ27Epk/main */
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>
#include <limits>
#include <stack>
#include <iterator>
#include <set>
#include <queue>
#include <sstream>
#include <stdlib.h>

bool isprime(int a)
{
    if(a == 1 || a == 0)
    {
        return 0;
    }
    for(int i = 2; i <=sqrt(a); i++) {  //Enough if we check till square root of input number.
        if(a%i == 0) return 0;
    }
    return 1;
}

int luckyandprimeprime(int l, int r) {
    
    int prime_count = 0;
    int final_count = 0;
    
    for(int i = 2; i < l ; i++)
    {
        if(isprime(i))
        {
            prime_count++;
        }
    }
    
    for(int i = l; i <= r; i++)
    {
            if(isprime(i))
            {
                prime_count++;
            }
            if(isprime(prime_count))
            {
                final_count++;
            }
    }
    return final_count;
}



// CODE GOLFED VERSION - REQUIRED COMPILER TWEAKING TO MAKE IT RUN
// #define e return

// int u,ip(int a)
// {
//     if(a < 2)
//         e 0;
//     for(u = 2; u <=sqrt(a);)
//         if(a%u++ < 1) e 0;
//     e 1;
// }

// int p,f,i=1,j,luckyandprimeprime(int l, int r) {
//     for(; i < l ;)
//         if(ip(i++))
//             p++;
    
//     for(i = l; i <= r;)
//     {
//             if(ip(i++))
//                 p++;
//             if(ip(p))
//                 f++;
//     }
//     e f;
// }




int main()
{
    std::cout<<luckyandprimeprime(100,1000)<<std::endl;

    return 0;

}