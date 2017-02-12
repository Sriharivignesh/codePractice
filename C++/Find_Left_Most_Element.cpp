
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
#include <fstream>
#include <cstdint>
#include <random>
#include <valarray>
#include <numeric>
#include <sstream>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int findLeftMostNode(TreeNode* root) {
        if(root -> left == NULL && root -> right == NULL)
        {
            return root -> val;
        }
        std::queue<TreeNode *> keeper;
        keeper.push(root);
        while(!keeper.empty())
        {
            std::queue<TreeNode *> temp;
            while(!keeper.empty())
            {
                auto k = keeper.front();
                if(k -> left)
                {
                    temp.push(k -> left);
                }
                if(k -> right)
                {
                    temp.push(k -> right);
                }
                keeper.pop();
            }
            bool all_nulls = 1;
            auto t = temp.front();
            while(!temp.empty())
            {
                auto k = temp.front();
                if(k -> left || k -> right)
                {
                    all_nulls = 0;
                }
                keeper.push(k);
                temp.pop();
            }
            if(all_nulls)
            {
                return t -> val;
            }
        }
        
    }
};