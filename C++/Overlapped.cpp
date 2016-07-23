/* https://codefights.com/challenge/PtL34SmGLAoE48pq5/main*/

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
#include <queue>
#include <sstream>
#include <stdlib.h>

/* The first part of the code stores the dictionary word lengths in an array. It also stores the positions where the words in the dictionary occur in the given string.
*  The second part performs a O(n^2) comparison between every dictionary word occurence to see if there are overlaps.
*/

int overlapped(std::string s, std::vector<std::string> d) {
    int count = 0;
    std::vector<int> sizes;
    std::vector<std::vector <int> > positions;
    for(int i = 0; i < d.size(); i++)
    {
        std::vector<int> temp;
        int length = d[i].length();
        sizes.push_back(length);
        size_t nPos = s.find(d[i], 0);
        if(nPos != std::string::npos)
        temp.push_back(nPos);
        while(1)
        {
            nPos = s.find(d[i], nPos+1);
            if(nPos != std::string::npos)
            temp.push_back(nPos);
            else
            break;
        }
        positions.push_back(temp);
    }
    int size = positions.size();
    for(int i = 0; i < size; i++)
    {
        int i_size = positions[i].size();
        if(i_size > 1)
        {
            for(int q = 0; q < i_size; q++)
            {
                for(int r = q + 1; r < i_size; r++)
                {
                    if(positions[i][r] < (positions[i][q] + sizes[i]))
                    {
                        count++;
                    }
                }
            }
        }
        //std::cout<<"Count1:"<<count<<std::endl;
        for(int j = i+1; j < size; j++)
        {
            int j_size = positions[j].size();
            //int bound = i_size<=j_size?i_size:j_size;
            for(int a = 0; a < i_size; a++)
            {
                for(int b = 0; b < j_size; b++)
                {
                    if(positions[i][a] == positions[j][b])
                    {
                        count++;
                    }
                    if(positions[i][a] < positions[j][b])
                    {
                        if(positions[j][b] < (positions[i][a] + sizes[i]))
                        {
                            count++;
                        }
                     }
                     if(positions[i][a] > positions[j][b])
                    {
                        if(positions[i][a] < (positions[j][b] + sizes[j]))
                        {
                           count++;
                        }
                    }
                }
            }
        }
    }
    return count;
}

int main()
{
    std::string s = "feebee";
    std::vector<std::string> d = {"feebee","ee","meh"};
    std::cout<<overlapped(s,d)<<std::endl;
    return 0;

}