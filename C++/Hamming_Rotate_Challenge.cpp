/* https://codefights.com/challenge/GFYjkhHDsp3PyRYKc/main */


#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>
#include <limits>

int Hamming_Rotate(std::string a, std::string b) {
    int minimum_count = 20;
    int result = 0;
    int length = a.length();
    for(int i = 0; i < length; i++)
    {
        int count = 0;
        for(int j = 0; j < length; j++)
        {
            if(a[j] != b[j])
            {
                count++;
            }
        }
        if(count == 0) //If count is 0 then we have reached minimum hamming distance. Distance cannot be lesser than 0
        {
            return i;
        }
        if(count < minimum_count)
        {
            result = i;
            minimum_count = count;
        }
       std::rotate(a.rbegin(),a.rbegin() + 1,a.rend()); //Rotate string to the right.
    }
    return result;

}


int main()
{
    std::cout<<Hamming_Rotate("100","001")<<std::endl;
    return 0;
}