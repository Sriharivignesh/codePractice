//https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

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
    std::vector<int> ncopy;
    void populate_bst(TreeNode *node, int left, int right)
    {
        if(left >= right)
        {
            return;
        }
        int num = ncopy[(left + right)/2];
        if(num == node -> val)
        {
            return;
        }
        TreeNode *temp = (TreeNode *)malloc(sizeof(struct TreeNode));
        temp -> right = NULL;
        temp -> left = NULL;
        temp -> val = num;
        if(num < (node -> val))
        {
            node -> left = temp;
        }
        if(num > (node -> val))
        {
            node -> right = temp;
        }
        populate_bst(temp, left, (left + right)/2);
        populate_bst(temp, ((left + right)/2) + 1, right);
        return;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int size = nums.size();
        if(size == 0)
        {
            return NULL;
        }
        TreeNode *root = (TreeNode *)malloc(sizeof(struct TreeNode));
        root -> right = NULL;
        root -> left = NULL;
        root -> val = nums[size/2];
        ncopy = nums;
        if(size == 1)
        {
            return root;
        }
        populate_bst(root,0, size/2);
        populate_bst(root, (size/2) + 1, size);
        return root;
    }
};


/* PLEASE DO THE BST INSERTION AND CHECKING YOURSELF */