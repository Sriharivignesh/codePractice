#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>


int main(){
    int T = 0;
    std::cin >> T;
    for(int a0 = 0; a0 < T; a0++){
        int N;
        std::cin >> N;
        std::cout << (((N * (N - 1))/2)) << "\n";
    }
    return 0;
}