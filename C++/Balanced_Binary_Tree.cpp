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
    int height_of_node(TreeNode *root)
    {
        if(root == NULL)
        {
            return 0;
        }
        return (1 + std::max(height_of_node(root -> right), height_of_node(root -> left)));
    }
    bool Balance_Check(TreeNode *root)
    {
        if(root == NULL)
        {
            return 1;
        }
        int lheight = 1 + height_of_node(root -> left);
        int rheight = 1 + height_of_node(root -> right);
        if(std::abs(lheight - rheight) > 1)
        {
            return 0;
        }
        if(!Balance_Check(root -> left) || !Balance_Check(root -> right))
        {
            return 0;
        }
        return 1;
        
    }
    bool isBalanced(TreeNode* root) {
        return (Balance_Check(root));
    }
};

//PLEASE IMPLEMENT BINARY TREE TESTING UNITS YOURSELF