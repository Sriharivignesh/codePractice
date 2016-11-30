//https://leetcode.com/problems/binary-tree-preorder-traversal/

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
    std::vector<int> container;
    void preorder_helper(TreeNode *node)
    {
        if(node != NULL)
        {
            container.push_back(node -> val);
            preorder_helper(node -> left);
            preorder_helper(node -> right);
        }
        return;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == NULL)
        {
            return {};
        }
        preorder_helper(root);
        return container;
    }
};

//PLEASE IMPLEMENT YOUR OWN MAIN FUNCTION