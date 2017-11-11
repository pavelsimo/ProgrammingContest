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

    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        TreeNode *right = invertTree(root->right);
        TreeNode *left = invertTree(root->left);
        root->left = right;
        root->right = left;
        return root;
    }    
    
    /*
    void go(TreeNode *root) {
        if (root == NULL)
            return;
        swap(root->left, root->right);
        go(root->left);
        go(root->right);
    }
    
    TreeNode* invertTree(TreeNode* root) {
        go(root);     
        return root;
    }
    */
};
