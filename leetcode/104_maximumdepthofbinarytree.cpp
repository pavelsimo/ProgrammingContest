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
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }        
        return max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);                
    }
    */

    int maxDepth(TreeNode* root) {
        
        if (root == NULL)
            return 0;
        
        queue<pair<TreeNode *, int> > q;
        q.push(make_pair(root, 1));
        int res = 0;
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            
            TreeNode *node = cur.first;
            int dist = cur.second;
            res = max(res, dist);
            
            if (node->left != NULL)
                q.push(make_pair(node->left, dist + 1));
            if (node->right != NULL)
                q.push(make_pair(node->right, dist + 1));            
        }
        return res;
    }    
    
};
