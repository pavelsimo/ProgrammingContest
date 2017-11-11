/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    //https://leetcode.com/problems/binary-tree-upside-down/discuss/
    
    TreeNode* upsideDownBinaryTree(TreeNode* root) {

        TreeNode *left = NULL;
        if (root->left != NULL)
            left = postorder(root->left);

        TreeNode *right = NULL;        
        if (root->right != NULL)
            right = postorder(root->right);
                
        return root;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution s;
    s.postorder(root);    

    return 0;
}
