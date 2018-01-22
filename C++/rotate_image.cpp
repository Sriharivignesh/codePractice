#include<iostream>
#include<vector>
#include <algorithm>

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        
        int rows = matrix.size();
        if(rows <= 0)
        {
            return;
        }
        int columns = matrix[0].size();
        
       // Swap around the diagonal 
        for(int i = 0; i < rows; i++)
        {
            for(int j = (i + 1); j < columns; j++)
            {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
        // Mirror output
        for(int i = 0; i < rows; i++)
        {
            std::reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

int main()
{
    Solution s1;
    std::vector<std::vector<int>> input_vector = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    s1.rotate(input_vector);
    
    for(int i = 0; i < input_vector.size(); i++)
    {
        for(int j = 0; j < input_vector[i].size(); j++)
            {
                std::cout << input_vector[i][j];
            }
        std::cout << "\n";
    }
    return 0;
}
