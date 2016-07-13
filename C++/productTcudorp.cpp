/* https://codefights.com/challenge/P4XeTQi9BJ3H3cm8r/main */
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

/* GOLFED VERSION - REQUIRES SOME COMPILER FLAG SETTING FOR THIS TO WORK
int r,q,productTcudorp(int n) {
    r = n;
        for(;n;)
        q*=10,
        q+=n%10,
        n/=10;
    return r*q;
}*/

int productTcudorp(int n) {
    int r = n;
    int q = 0;
        for(;n;) //Reverse the given integer
        q*=10,
        q+=n%10,
        n/=10;
    return r*q; //return the product
}

int main()
{
    std::cout<<productTcudorp(5)<<std::endl;
    return 0;

}