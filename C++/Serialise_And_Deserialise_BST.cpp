// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

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
class Codec {
public:

    // Encodes a tree to a single string.
    
    void serialise_helper(TreeNode *root, std::ostringstream &working)
    {
        if(root == NULL)
        {
            working << "| ";
            return;
        }
        else
        {
            //working += std::to_string(root -> val);
            //working += (root -> val + '0');
            working << (root -> val) << " "; 
            serialise_helper(root -> left, working);
            serialise_helper(root -> right, working);
        }
            return;
    }
    string serialize(TreeNode* root) {
        //std::string working = "";
        std::ostringstream serialised;
        serialise_helper(root, serialised);
        //std::cout << working << "\n";
        return serialised.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialise_helper(std::istringstream &serialised)
    {
        std::string temp = "";
        serialised >> temp;
        if(temp == "|")
        {
            return NULL;
        }
            TreeNode *node = (TreeNode *)malloc(sizeof(struct TreeNode));
            node -> val = std::stoi(temp);
            node -> left = deserialise_helper(serialised);
            node -> right = deserialise_helper(serialised);
            return node;
    }
    TreeNode* deserialize(string data) {
        std::string t = "";
        std::istringstream serialised(data);
        TreeNode *root = deserialise_helper(serialised);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));


//IMPLEMENT THE BST PROGRAM YOURSELF PLEASE

//REFERENCES:
//https://gist.github.com/xuelangZF/051b7c9bf2dbeb457ea619f34f5d27a1/