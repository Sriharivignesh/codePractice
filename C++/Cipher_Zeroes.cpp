/* Cipher Zeroes problem from Codefights : https://codefights.com/challenge/x9TcPgiFRmgN22W44/main */

#include <iostream> 

using namespace std;

int Cipher_Zeroes(std::string N) {
    long long count = 0; // Keeping count of visible zeroes for very large numbers
    for(int i = 0; i < N.length(); i++)
    {
        if(N[i] == '0' || N[i] == '6' || N[i] == '9')
        {
            count++;
        }
        if(N[i] == '8')
        {
            count = count + 2;
        }
        
    }
    if(count == 0)
    {
        return 0; //0 is even but if negative number is converted to binary it will yield weird results
    }
    if(count > 0 && count%2 == 0)
    {
        count--;
    }
    else
    {
        count++;
    }
    std::string temp = std::bitset<10>(count).to_string();  //Number in angular brackets indicated the number of bits that are represented
    return (std::stol(temp)); //Convert to long in case int overflow occurs
}


int main()
{
    cout<<Cipher_Zeroes("4096")<<endl;
    return 0;
}