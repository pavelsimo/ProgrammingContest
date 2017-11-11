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

    // Aproach #1
    int maxdepth(TreeNode *root) {
        if (root == NULL)
            return 0;
        int res = 0;
        res = max(res, maxdepth(root->left) + 1);
        res = max(res, maxdepth(root->right) + 1);
        return res;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;
        int res = maxdepth(root->left) + maxdepth(root->right);
        res = max(res, diameterOfBinaryTree(root->left));
        res = max(res, diameterOfBinaryTree(root->right));
        return res;        
    }
};
