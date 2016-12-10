//https://www.hackerrank.com/challenges/find-point
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//Solution is simple. Just solve for the equation for finding midpoint using the 2 point sets given so that qx,qy is the midpoint

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n = 0;
    std::cin >> n;
    while(n--)
        {
        int px = 0;
        int py = 0;
        int qx = 0;
        int qy = 0;
        std::cin >> px >> py >> qx >> qy;
        std::cout << ((2 * qx) - px) << " " << ((2 * qy) - py) << "\n";
    }
    return 0;
}

//IMPLEMENT MAIN FUNCTION BY YOURSELF