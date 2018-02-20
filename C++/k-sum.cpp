#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

std::vector<std::vector<int>> ksum_helper(std::vector<int> &input, int target, int k, int index)
{
    int input_size = input.size();
    std::vector<std::vector<int>> output;


    if(k == 1)
    {
        throw std::invalid_argument("Minimum 2 required");
    }

    if(k == 2)
    {
        int i = index; 
        int j = input_size - 1;

        std::set<std::vector<int>> temp;

        while(i < j)
        {
            if((input[i] + input[j]) == target)
            {
                output.push_back({input[i], input[j]});
                i++;
            }
            else if((input[i] + input[j]) > target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
    }
    else
    {
        // Handle upper cases
        for(int i = index; i < (input_size - k + 1); i++)
        {
            std::vector<std::vector<int>> temp = ksum_helper(input, target - input[i], k - 1, i + 1);
            for(int j = 0; j < temp.size(); j++)
            {
                temp[j].push_back(input[i]);
                output.push_back(temp[j]);
            }
        }
    }
    return output;
}

std::vector<std::vector<int>> ksum(std::vector<int> &input_vector, int target, int k)
{
    std::sort(input_vector.begin(), input_vector.end());

    std::vector<std::vector<int>> ret_vec = ksum_helper(input_vector, target, k, 0);

    std::set<std::vector<int>> s;

    for(auto i : ret_vec)
    {
        s.insert(i);
    }
    ret_vec.clear();
    for(auto i : s)
    {
         ret_vec.push_back(i);
    }
    return ret_vec;
}

int main()
{
    std::vector<int> input = {1, 0, -1, 0, -2, 2};
    std::vector<std::vector<int>> temp = ksum(input, 0, 4);

    for(int i = 0; i < temp.size(); i++)
    {
        std::sort(temp[i].begin(), temp[i].end());
        for(int j = 0; j < temp[i].size(); j++)
        {
            std::cout << temp[i][j] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
