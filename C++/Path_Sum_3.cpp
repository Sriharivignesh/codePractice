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
    int pcounter;
    void checker(TreeNode * qroot, int rsum, int &osum)
    {
        if(qroot == NULL)
        {
            return;
        }
        if(qroot -> val + rsum == osum)
        {
            pcounter++;
        }
        checker(qroot -> right, qroot -> val + rsum, osum);
        checker(qroot -> left, qroot -> val + rsum, osum);
        
    }
    void helper(TreeNode * proot, int &osum)
    {
        if(proot == NULL)
        {
            return;
        }
        checker(proot, 0, osum);
        helper(proot -> right, osum);
        helper(proot -> left, osum);
        return;
    }
    int pathSum(TreeNode* root, int sum) {
        if(root == NULL)
        {
            return 0;
        }
        pcounter = 0;
        helper(root, sum);
        return pcounter;
    }
};

//Write your own main function please