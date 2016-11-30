//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

//REFERENCE: https://www.youtube.com/watch?v=13m9ZCB8gjw&list=PLrmLmBdmIlpv_jNDXtJGYTPNQ2L1gdHxu&index=17

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
    TreeNode* lca_helper(TreeNode *node, TreeNode *p, TreeNode *q)
    {
        if(node == NULL)
        {
            return NULL;
        }
        if(node == p)
        {
            return p;
        }
        if(node == q)
        {
            return q;
        }
        auto a = lca_helper(node -> left, p, q);
        auto b = lca_helper(node -> right, p, q);
        if(a == NULL && b == NULL)
        {
            return NULL;
        }
        if((a == p && b == q) || (a == q && b == p))
        {
            return node;
        }
        return a?a:b;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
        {
            return NULL;
        }
        if(root == p || root == q)
        {
            return root;
        }
        auto a = lca_helper(root -> left, p, q);
        auto b = lca_helper(root -> right, p, q);
        if((a == p && b == q) || (a == q && b == p))
        {
            return root;
        }
        if(a == p || a == q)
        {
            return a;
        }
        if(b == p || b == q)
        {
            return b;
        }
        return a?a:b;
    }
};

//PLEASE IMPLEMENT YOUR OWN MAIN FUNCTION