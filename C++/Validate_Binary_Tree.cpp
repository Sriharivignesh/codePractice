//https://leetcode.com/problems/validate-binary-search-tree/

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
    bool valid_checker(TreeNode *root, long left, long right)
    {
            return ((root -> val < right && root -> val > left) && (root->left?valid_checker(root -> left,left, root -> val):1) && (root->right?valid_checker(root -> right,root -> val, right):1));
    }
    bool isValidBST(TreeNode* root) {
        if(root == NULL)
        {
            return 1;
        }
        return valid_checker(root,-LONG_MAX, LONG_MAX);        
    }
};