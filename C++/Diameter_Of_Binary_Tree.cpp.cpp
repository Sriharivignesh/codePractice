//
// Created by Sri Hari Vignesh on 19/03/17.
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


//Credits - saffah (https://leetcode.com/saffah/)



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
	std::vector<int> do_traversal(TreeNode *root)
	{
		if(root != NULL)
		{
			auto left = do_traversal(root -> left);
			auto right = do_traversal(root -> right);
			return {std::max((left[1] + right[1] + 1), std::max(left[0], right[0])), std::max((left[1] + 1), (right[1] + 1))};
		}
		return {0,0};

	}
	int diameterOfBinaryTree(TreeNode* root) {
		if(root == NULL)
		{
			return 0;
		}
		return do_traversal(root)[0] - 1;


	}
};


//Roll your own main function please

