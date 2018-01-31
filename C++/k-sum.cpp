#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<std::vector<int>> ksum_helper(std::vector<int> input, int target, int k, int index)
{
    std::vector<std::vector<int>> output;

    if(k == 1)
    {
        for(int i = index; i < input.size(); i++)
        {
            if(input[i] == target)
            {
                output.push_back({input[i]});
            }
        }
    }

    if(k == 2)
    {
        //Handle base case
        std::unordered_map<int, bool> presence_lookup;
        for(int i = index; i < input.size(); i++)
        {
            presence_lookup[input[i]] = false;
        }
        
        for(int i = index; i < input.size(); i++)
        {
            if(presence_lookup[input[i]] || presence_lookup[target - input[i]])
            {
                continue;
            }

            output.push_back({input[i], target - input[i]});
            presence_lookup[input[i]] = true;
            presence_lookup[target - input[i]] = true;
        }
    }
    else
    {
        // Handle upper cases
        for(int i = index; i < (input.size() - k + 1); i++)
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
    // Make vector unique
    std::vector<int>::iterator it;
    it = std::unique(input_vector.begin(), input_vector.end());
    input_vector.resize(std::distance(input_vector.begin(), it));

    std::sort(input_vector.begin(), input_vector.end());

    return ksum_helper(input_vector, target, k, 0);
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