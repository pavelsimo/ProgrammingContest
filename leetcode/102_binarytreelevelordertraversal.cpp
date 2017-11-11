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

    /*
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL)
            return vector<vector<int> >();
        vector<vector<int> > res;
        queue<pair<TreeNode*, int> > q;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            TreeNode *node = cur.first;
            int dist = cur.second;
            if (dist >= res.size())
                res.push_back(vector<int>());            
            res[dist].push_back(node->val);
            if (node->left != NULL)
                q.push(make_pair(node->left, dist + 1));
            if (node->right != NULL)
                q.push(make_pair(node->right, dist + 1));            
        }
        return res;
    }
    */

    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL)
            return vector<vector<int> >();
        vector<vector<int> > res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            res.push_back(vector<int>());
            int level = res.size() - 1;            
            for (int i = 0; i < n; ++i) {
                TreeNode *cur = q.front();
                q.pop();
                res[level].push_back(cur->val);
                if (cur->left != NULL)
                    q.push(cur->left);
                if (cur->right != NULL)
                    q.push(cur->right);                            
            }
        }
        return res;
    }        
    
};
