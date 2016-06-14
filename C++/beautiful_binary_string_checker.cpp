/* BEAUTIFUL BINARY STRING CHECKER
**https://codefights.com/challenge/Z37bL7eBwG7HGYHeu/main
*/

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string.h>

bool beautiful_binary_strings(std::string BinaryString) {
    int length = BinaryString.length();
    if(length < 2 || length%2 != 0)
    {
        return 0;
    }
    if(length == 2)
    {
        return (BinaryString[0] == BinaryString[1]);
    }
    for(int i = 0; i < length; i++)
    {
        if(BinaryString[i] == BinaryString[i+1])
        {
            BinaryString.erase(i,2);
            length = length - 2;
            i = -1;
        }
    }

    return (BinaryString == "");

}


int main()
{
    std::cout<<beautiful_binary_strings("BABAA")<<std::endl;
}