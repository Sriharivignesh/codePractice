/* 

https://codefights.com/challenge/T3hZPzxtZ4pg3XJMk/main


Two players, Lan and Tu, play the "Break-the-log game"

Initially there are n logs, each one is exactly m meters long. The players move in turns. Each turn, the player whose turn it is chooses a log and breaks it into some number (greater than 1) of equal parts, so that the length of each part is an integer not smaller than k.

Each resulting part is also a log which can be broken in the future by any player. If the player has no log to break, he loses the game, and the other player wins.

Lan makes the first move. Tu and Lan are so clever that they both play optimally. Who will win the game?

Example

For n = 1, m = 15 and k = 4, the output should be
BreakTheLog(n, m, k) = "Lan".

Initially there's only one one log of length 15. Since the minimum length of the resulting log is 4, Lan can only break the log into 3 logs of length 5 each.
Since the length of each log is 5, there's no way for Tu to break any log into smaller pieces of equal integer length, so Tu loses the game, and Lan wins.

Input/Output

[time limit] 500ms (cpp)
[input] integer n

The number of logs.

Constraints:
1 ≤ n ≤ 109.

[input] integer m

The length of each initial log.

Constraints:
1 ≤ m ≤ 109.

[input] integer k

The minimum length of a log.

Contraints:
1 ≤ k ≤ 109.

[output] string

The name of the winner, either "Tu" or "Lan". 
*/


#include<iostream>
#include<string>
#include<math.h>

using namespace std;


std::string BreakTheLog(int number, int size, int default_minimum_size) {
    bool player = 0; /* 0 - LAN, 1 - TU */
    if((size < (2 * default_minimum_size)) || number <= 0)
    {
        return "Tu";
    }
    int minimum_size = default_minimum_size;
    bool incomputable = 0;
    while(1)
    {
        if(size < (2*minimum_size))
        {
            break;
        }
        while(1)
        {
            if(minimum_size > size/2)
            {
                incomputable = 1;
                break;
            }
            else if(size % minimum_size == 0)
            {
                size = minimum_size;
                break;
            }
            else
            {
                minimum_size ++;
            }
        }
        if(incomputable)
        {
            break;
        }
        minimum_size = default_minimum_size;
        player = !player;
    }
    if(number == 1 || (incomputable && number == 1))
    {
        if(player)
        {
            return "Lan";
        }
        else
        {
            return "Tu";
        }
    }
    if(incomputable)
    {
        if(number % 2 == 0)
        {
           if(player)
           {
               return "Tu";
           }
           else
           {
               return "Lan";
           } 
        }
        else
        {
            if(player)
            {
                return "Lan";
            }
            else
            {
                return "Tu";
            }
            
        }
    }
    
    if(number%2 == 0)
    {
        if(player)
        {
            return "Tu";
        }
        else
        {
            return "Lan";
        }
    }
    else
    {
        if(player)
        {
            return "Lan";
        }
        else
        {
            return "Tu";
        }
    }
}

int main()
{
    cout<<BreakTheLog(501,850,11)<<endl;
    return 0;
}

