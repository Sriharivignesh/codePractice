// Given a 2D matrix comprising of integers,
// group all the positive integers to the first
// (number of positive integer) places.
// For example if the matrix is a 3x3 matrix
// and has 3 positive integers scattered througout
// the matrix, partition the matrix in such a way 
// that the first 3 numbers are positive and the
// rest are negative or 0 when scanned via traditional
// for loop.

#include <iostream>
#include <vector>
#include <random>
#include <limits>

void partition(std::vector<std::vector<int>>& input, int rows, int columns)
{
    int covered_row = 0;
    int covered_column = 0;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            if(input[i][j] > 0)
            {
                std::swap(input[i][j], input[covered_row][covered_column]);
                covered_column = (covered_column + 1) % columns;
                covered_row = covered_column == 0? covered_row + 1 : covered_row;
            }
        }
    }
}

int main()
{
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> random_distribution(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());

    int rows = 3;
    int columns = 3;

    std::vector<std::vector<int>> input;

    for(int i = 0; i < rows; i++)
    {
        std::vector<int> column_vector;
        for(int j = 0; j < columns; j++)
        {
            column_vector.push_back(random_distribution(rng));
        }
        input.push_back(column_vector);
    }

    std::cout << "Unpartitioned matrix: " << "\n";
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            std::cout << input[i][j] << "\t";
        }
        std::cout << "\n";
    }

    partition(input, rows, columns);

    std::cout << "Partitioned matrix: " << "\n";
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            std::cout << input[i][j] << "\t";
        }
        std::cout << "\n";
    }

    return 0;
}