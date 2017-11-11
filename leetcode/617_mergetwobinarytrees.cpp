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

    void merge(TreeNode** t1, TreeNode** t2) {        
        if ((*t1) != NULL && (*t2) != NULL) {
            (*t1)->val += (*t2)->val;
            merge(&(*t1)->left, &(*t2)->left);
            merge(&(*t1)->right, &(*t2)->right);                            
        }
        
        if ((*t1) == NULL && (*t2) != NULL) {
            (*t1) = (*t2);
        }
    }
    
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        merge(&t1, &t2);
        return t1;
    }
};
