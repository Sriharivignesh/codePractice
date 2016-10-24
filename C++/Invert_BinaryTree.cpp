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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
        {
            return NULL;
        }
        else if(root -> left == NULL && root -> right == NULL)
        {
            return root;
        }
        else
        {
            TreeNode *temp = root -> left;
            root -> left = root -> right;
            root -> right = temp;
            invertTree(root -> left);
            invertTree(root -> right);
        }
        return root;
    }
};


/* Please write your own main() function  to test my function */