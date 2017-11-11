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

typedef long long llong;

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if (root == NULL)
            return res;        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            llong sum = 0;
            for(int i = 0; i < n; ++i) {
                TreeNode *cur = q.front();
                q.pop();
                sum += cur->val;
                if (cur->left != NULL)
                    q.push(cur->left);
                if (cur->right != NULL)
                    q.push(cur->right);                
            }
            if (n > 0)
                res.push_back(1.0*sum / n);
        }
        return res;
    }
};
