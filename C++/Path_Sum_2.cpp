//https://leetcode.com/problems/path-sum-ii/
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
    void helper(TreeNode *root,int rsum, int &osum, std::vector<int> &temp, std::vector<std::vector<int>> &repo)
    {
        if(root == NULL)
        {
            return;
        }
            temp.push_back(root -> val);
            std::vector<int> vleft(temp);
            std::vector<int> vright(temp);
        if((root -> val + rsum) == osum)
        {
            if(root -> right == NULL && root -> left == NULL)
            {
                repo.push_back(temp);
            }
        }
            helper(root -> right,root -> val + rsum, osum, vright, repo);
            helper(root -> left, root -> val + rsum, osum, vleft, repo);
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        std::vector<std::vector<int>> k;
        if(root == NULL)
        {
            return k;
        }
        std::vector<int> p;
        helper(root, 0, sum, p, k);
        return k;
    }
};

//PLEASE WRITE YOUR OWN MAIN FUNCTION