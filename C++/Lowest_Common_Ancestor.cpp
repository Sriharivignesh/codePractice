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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root -> val == p -> val)
        {
            return p;
        }
        else if(root -> val == q -> val)
        {
            return q;
        }       
        
        else if(((root -> val) < p -> val) && ((root -> val) < q -> val))
        {
            //root = root -> right;
            return lowestCommonAncestor(root -> right, p, q);
        }
        else if(((root -> val) > p -> val) && ((root -> val) > q -> val))
        {
            //root = root -> left;
            return lowestCommonAncestor(root -> left, p, q);
        }
        else
        {
            return root;
        }
        
        return root;
        
    }
};

/*Write your own main function to test my LCA function */