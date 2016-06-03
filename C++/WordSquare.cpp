/* WordSquares problem from codefight website: https://codefights.com/challenge/K7sNTB32u3A68mCnA/main */

/* HINT: NUMBER OF MISMATCHED CHARACTERS CANNOT BE MORE THAN THE ORDER OF THE MATRIX OR SQUARE */

#include <iostream>
#include <string.h>
#include <vector>
#include <map>
#include <math.h>

using namespace std;

bool WordSquare(std::string letters) {
    int length = letters.length(); 
    int square_length = 0;  //Length of the side of the square
    int count = 0; //Count of mismatched characters in the string
    for(int i = 3; i < 11; i++) //Is efficient way to find square root since word length is guaranteed never to exceed 100*/
    {
        if((i*i) == length)
        {
            square_length = i;
            break;
        }
    }
    if(square_length == 0)  //no perfect squares found
    {
        return 0;
    }
    std::map<char, int> char_count; //Index that keeps count of every character in the input string
    for(int i = 0; i < length; i++)
    {
       char_count[letters[i]]++;
    }
    for(int i = 65; i < 91; i++)
    {
         if((char_count.find((char) i) != char_count.end()) && char_count[(char) i] %2 != 0)
        {
            count ++; //If character count is odd then it is mismatched so increase count
        }
    }
    if(count <= square_length)
    {
        return 1;
    }
    else
    {
        return 0;
    } 
}

int main()
{
    string letters = "SATORAREPOTENETOPERAROTAS";
    cout<<WordSquare(letters)<<endl;
    return 0;
}