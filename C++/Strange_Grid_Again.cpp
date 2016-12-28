//https://www.hackerrank.com/challenges/strange-grid?utm_campaign=challenge-recommendation&utm_medium=email&utm_source=24-hour-campaign
#include <vector>
#include <iostream>
#include <algorithm>


int main() {
    std::vector<int> row_values = {100,0,2,4,6,8};
    long r = 0;
    long c = 0;
    std::cin >> r;
    std::cin >> c;
    if(r%2 == 0)
        std::cout << row_values[c] + ((r/2) * 1) + (((r/2) - 1) * 9) << "\n";
    else
        std::cout << row_values[c] + ((r/2) * 1) + (((r/2)) * 9) << "\n";
    return 0;
}