/* https://leetcode.com/problems/intersection-of-two-arrays-ii/ */

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>
#include <limits>


class Solution {
public:
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        if(size1 == 0 || size2 == 0)
        {
             std::vector<int> v;
             return v;
        }
        if(size1 == 1 && size2 == 1)
        {
            if(nums1[0] == nums2[0])
            {
                 std::vector<int> v(1,nums1[0]);
                 return v;
            }
            else
            {
                 std::vector<int> v;
                 return v;
            }
        }
        std::unordered_map<int,int> number_index1;
        std::unordered_map<int,int> number_index2;
        std::vector<int> result;
        for(int i = 0; i < (size1>=size2?size1:size2); i++)
        {
            if(i < size1)
            number_index1[nums1[i]]++;
            if(i < size2)
            number_index2[nums2[i]]++;
        }
        if(size1 <= size2)
        {
                for(int i = 0; i < size1; i++)
                {
                    if(number_index2.find(nums1[i]) != number_index2.end())
                    {
                        int count = number_index1[nums1[i]] <= number_index2[nums1[i]]?number_index1[nums1[i]]:number_index2[nums1[i]];
                        for(int j = 0; j < count; j++)
                        {
                            result.push_back(nums1[i]);
                        }
                        number_index2.erase(nums1[i]);
                    }
                }
        }
        
        else
        {
                for(int i = 0; i < size2; i++)
                {
                    if(number_index1.find(nums2[i]) != number_index1.end())
                    {
                        int count = number_index1[nums2[i]] <= number_index2[nums2[i]]?number_index1[nums2[i]]:number_index2[nums2[i]];
                        for(int j = 0; j < count; j++)
                        {
                            result.push_back(nums2[i]);
                        }
                        number_index1.erase(nums2[i]);
                    }
                }
        }
        
        return result;
    }
};


int main()
{
    Solution s1;
    std::vector<int> n1;
    std::vector<int> n2;
    std::vector<int> n;
    n1.push_back(1);
    n1.push_back(2);
    n1.push_back(1);
    n1.push_back(1);
    n1.push_back(1);
    n1.push_back(3);
    n2.push_back(1);
    n2.push_back(2);
    n2.push_back(1);
    n2.push_back(1);
    n2.push_back(1);
    n2.push_back(3);
    n = s1.intersect(n1,n2);
    std::vector<int>::iterator control = n.begin();
    for(control = n.begin(); control < n.end(); control++)
    {
        std::cout<<*control<<std::endl;
    }
    return 0;
}

