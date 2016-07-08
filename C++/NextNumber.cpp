/* https://codefights.com/challenge/fE4DJSQmFQEWrdYwp/main */

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>
#include <limits>
#include <stack>
#include <iterator>


//MY CODEGOLF ENTRY
/*int q,i,nextNumber(int N) {
    q = __builtin_popcount(N);
    i = N;
    while(i < INT_MAX)
    {
        i++;
        if(__builtin_popcount(i) == q)
            return i;
    }
}*/

int nextNumber(int N) {
    int q = __builtin_popcount(N); //__builtin_popcount() returns the number of set bits in the binary representation of the integer
    int i = N;
    while(i < INT_MAX)
    {
        i++;
        if(__builtin_popcount(i) == q)
            return i;
    }
    return N;
}

int main()
{
    std::cout<<nextNumber(2)<<std::endl;
    return 0;
}

