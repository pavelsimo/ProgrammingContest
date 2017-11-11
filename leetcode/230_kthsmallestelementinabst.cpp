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

    void FindKth(TreeNode *root, int *k, int *ans) {
        if (root == NULL)
            return;

        FindKth(root->left, k, ans);
        --(*k);
        if (*k == 0) {
            *ans = root->val;
            return;
        }

        FindKth(root->right, k, ans);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int res = 0;
        FindKth(root, k, &res);
        return res;
    }
};

int main() {
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(8);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(9);

    Solution s;
    cout << s.kthSmallest(root, 1) << endl;
    
    return 0;
}
