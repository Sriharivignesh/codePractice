//
// Created by Sri Hari Vignesh on 18/03/17.
//





#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
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
#include <list>

//Credits - Saffah (https://leetcode.com/saffah/)




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
	int do_traversal(TreeNode *root, int sum)
	{
		if(root != NULL)
		{
			sum = do_dfs(root -> right, sum);
			sum += root -> val;
			root -> val += (sum - root -> val);
			sum = do_dfs(root -> left, sum);
		}
		return sum;
	}
	TreeNode* convertBST(TreeNode* root) {
		int sum = 0;
		do_traversal(root, sum);
		return root;

	}
};


//Roll your own main function please.
