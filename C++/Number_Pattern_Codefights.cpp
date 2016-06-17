/* https://codefights.com/challenge/iBJCkwKHBdMiuxfHF/main?utm_source=challengeOfTheDay&utm_medium=email&utm_campaign=email_notification */

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>


int pattern(int i) {
/*    int result = 1;
    for(int j = 1; j < i; j++)
    {
        result = ((result + 1) * 2);
    }
    return result;*/
    
    return (i == 1)?(1):(2*(pow(2 , i - 2) + (pow(2 , i - 1) -1)));
}




int main() {
    std::cout<<pattern(4)<<std::endl;
    return 0;
}