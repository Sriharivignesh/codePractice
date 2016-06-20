/* https://leetcode.com/problems/russian-doll-envelopes/ */

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>
#include <limits>


class Solution {
public:
    int maxEnvelopes(std::vector<std::pair<int, int>>& envelopes) {
        int size = envelopes.size();
        if(size == 0)
        {
            return 0;
        }
        if(size == 1)
        {
            return 1;
        }
        int max = 1;
        int letter_count[size];
        letter_count[0] = 1;
        /*for(int i = 0; i < size; i++)  //No need to run a separate array initialisation loop. We can initialise the array elements to 1 in the following for loop itself
        {
            letter_count[i] = 1;
        }*/
        std::sort(envelopes.begin(),envelopes.end());
        for(int i = 1; i < size; i++)
        {
            letter_count[i] = 1;
            for(int j = 0; j < i; j++)
            {
                if((envelopes[i].first > envelopes[j].first) && (envelopes[i].second > envelopes[j].second))
                {
                    if(letter_count[i] < (1 + letter_count[j]))
                    {
                        letter_count[i] = 1 + letter_count[j];
                        if(max < letter_count[i])
                        {
                            max = letter_count[i];
                        }
                    }
                }
            }
        }
        return (max);
    }
};


int main() {
   std::vector<std::pair<int, int>> input_vector = {
        {15,2}, {3,3}, {8,1}, {7,13}, {1,10}
    };

    Solution s1;
    std::cout<<s1.maxEnvelopes(input_vector)<<std::endl;
    return 0;
}

