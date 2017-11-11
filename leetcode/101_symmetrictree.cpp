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

    bool isSym(TreeNode *p, TreeNode *q) {
        if (p == NULL && q == NULL)
            return true;
        if (p == NULL && q != NULL)
            return false;
        if (p != NULL && q == NULL)
            return false;
        if (p->val != q->val)
            return false;                
        return isSym(p->left, q->right) && isSym(p->right, q->left);        
    }
    
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        return isSym(root->left, root->right);
    }
};
