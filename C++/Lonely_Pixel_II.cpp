
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
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
#include <fstream>
#include <cstdint>
#include <random>
#include <valarray>
#include <numeric>
#include <sstream>
#include <list>

class Solution {
public:
	int findBlackPixel(std::vector<std::vector<char>> &picture, int N) {
		int rows = picture.size();
		int columns = picture[0].size();
		if(rows == 0 || columns == 0)
		{
			return 0;
		}
		int total = 0;
		std::vector<std::list<int>> colblacks(columns); //Store a list of rows where black pixels are present indexed by column number
		std::vector<int> brows(rows, 0); //For storing number of black pixel indexed by row
		std::vector<int> bcols(columns, 0); //For storing number of black pixel indexed by column
		std::unordered_set<int> satisfied_columns; //Storing columns that meet criteria mentioned in the problem for fast lookup
		std::vector<std::string> row_strings; //Store strings to hash and compare later.
		for(int i = 0; i < rows; i++)
		{
			std::string temp = "";
			for(int j = 0; j < columns; j++)
			{
				temp += picture[i][j];
				if(picture[i][j] == 'B')
				{
					brows[i]++;
					bcols[j]++;
					colblacks[j].push_back(i);
				}
			}
			row_strings.push_back(temp);
		}
		for(int i = 0; i < rows; i++)
		{
			for(int j = 0; j < columns; j++)
			{
				if(picture[i][j] == 'B')
				{
					if(brows[i] == N && bcols[j] == N)
					{
						if(satisfied_columns.count(j))
						{
							total += 1;
							continue;
						}
						bool all_same = 1;
						auto reference = std::hash<std::string>{}(row_strings[i]);
						for(auto p : colblacks[j])
						{
							if(std::hash<std::string>{}(row_strings[p]) != reference)
							{
								all_same = 0;
								break;
							}
						}
						if(all_same)
						{
							total += 1;
							satisfied_columns.insert(j);
						}
					}
				}
			}
		}
		return total;
	}
};



int main()
{
	Solution s1;
	std::vector<std::string> w = {"WBBWWBWWWWWBBWW", "WBBWWBWWWWWBBWW", "WWWWWBBBWBWWWWB", "WWBWBWWWWBBWBWW", "WBBWWBWWWWWBBWW", "WWBWBWWWWBBWBWW", "WWBWBWWWWBBWBWW", "WWBWBWWWWBBWBWW"};
	std::vector<std::vector<char>> p(w.size());
	for(int i = 0; i < w.size(); i++)
	{
		for(int j = 0; j < w[i].length(); j++)
		{
			p[i].push_back(w[i][j]);
		}
	}
	std::cout << s1.findBlackPixel(p, 5) << "\n";
	return 0;
}