/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

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

    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return false;
        int rem = sum - root->val;
        if (root->left == NULL && root->right == NULL)
            return rem == 0;        
        return hasPathSum(root->left, rem) ||
               hasPathSum(root->right, rem);
    }        
};
