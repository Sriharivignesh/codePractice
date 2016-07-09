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
/*int findBiSlice(std::vector<int> arr) {
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
}*/

//FOLLOWING IS THE IMPLEMENTATION OF O(N) solution suggested by Sir_Ementaler which works wonderfully - how could I not have thought if this earlier??

/* Iterate over the array a while keeping the last two encountered values in mind, say x and y. If a[i] is either x or y, then the calculated length of the sequence of x's and y's is incremented. If it some z that is neither x nor y, then the sequence of x's and y's is closed and we start counting ** a new sequence. This new sequence is a sequence of either x's and z's or y's and z's, depending on whether an occurrence of x or y was more recent, and already has some entries, i.e. the number of uninterrupted occurrences of x or y prior to encountering z. That means you also need to remember ** which of the values was more recent, and how many times in a row it last occurred. The returned value is the maximum found length of any sequence.
** You can see my solution for one possible implementation. It's very obfuscated but readable if you replace conditional operators with ifs and elses (I also use a ^ b in place of a != b). Variable descriptions:
** x - most recent found value
** y - second most recent found value
** s - length of the ongoing sequence of xs
** t - length of the ongoing sequence of xs and ys
** r - greatest length found so far
*/

int findBiSlice(std::vector<int> arr) { //{5, 8, 8, 6, 7, 4, 3, 4, 3}
    int x = arr[0];
    int y = arr[1];
    int x_count = 0;
    int y_count = 0;
    int count = 0;
    int last = 0;
    int maximum = -100;

    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] == x)
        {
            count++;
            x_count++;
            last = x;
        }
        else if(arr[i] == y)
        {
            count++;
            y_count++;
            last = y;
        }
        else
        {
            if(last == x)
            {
                if(count > maximum)
                {
                    maximum = count;
                }
                count = x_count + 1;
                y = arr[i];
                last = y;
                y_count = 1;
            }
            else
            {
                if(count > maximum)
                {
                    maximum = count;
                }
                count = y_count + 1;
                x = arr[i];
                last = x;
                x_count = 1;
            }
        }
    }
        if(count > maximum)
        {
            return count;
        }
        else
        {
            return maximum;
        }
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
    std::vector<int> input = {4, 5, 5, 4, 4, 5};
    std::cout<<findBiSlice(input)<<std::endl;
    return 0;
}

