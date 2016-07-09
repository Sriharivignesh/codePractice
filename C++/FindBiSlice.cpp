/* https://codefights.com/challenge/n75eG9MuhDzejuCyp/main */

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

/* Keeps inserting numbers in std::set. When set size exceeds 2, 
** it means 3 different numbers are in the set which resets the count of the longest contiguous array.
*/
int findBiSlice(std::vector<int> arr) {
    int maximum = -1000;
    int count = 0;
    int size = arr.size(); //Size of input vector 'arr'
    for(int i = 0; i < size; i++) //This is an O(n^2) solution.
    {
        std::set<int> test;
        if(count > maximum)
        {
           maximum = count;
        }
        if(maximum > size/2) //Optimization in case we find longest subarray before reaching the end of the original array.
        {
            return maximum;
        }
        count = 0;
        for(int j = i; j < size; j++)
        {
            test.insert(arr[j]);
            if(test.size() > 2)
            {
                break;
            }
            count++;
        }
    }
    return maximum;
}


//GOLFED VERSION - NOT SO MUCH OF GOLFING AS GIVING ALL VARIABLES SINGLE CHARACTER NAMES :D
/*int s,i,j,m = -1,c,findBiSlice(auto a) {
    s = a.size();
    for(i = 0; i < s;)
    {
        std::set<int> t;
        c>m?m=c:1;
        c = 0;
        for(j = i++; j < s;)
        {
            t.insert(a[j++]);
            if(t.size() > 2)
                break;
            c++;
        }
    }
    return m;
}*/


int main()
{
    std::vector<int> input = {5, 8, 8, 6, 7, 4, 3, 4, 3};
    std::cout<<findBiSlice(input)<<std::endl;
    return 0;
}

