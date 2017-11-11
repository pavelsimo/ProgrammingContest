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

    bool findTarget(TreeNode *root, int target) {

        if (root == NULL)
            return false;
        
        set<int> s;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *cur = q.front();
            q.pop();

            if (s.count(target - cur->val))
                return true;
            
            s.insert(cur->val);            
            if (cur->left != NULL)
                q.push(cur->left);
            if (cur->right != NULL)
                q.push(cur->right);
        }

        return false;
    }

    /*
    bool twoSum(vector<int>& numbers, int target) {
        int lo = 0;
        int hi = numbers.size() - 1;
        while (lo < hi) {
            int sum = numbers[lo] + numbers[hi];
            if (sum == target)
                return true;
            if (sum > target)
                hi--;
            else
                lo++;
        }
        return false;
    }
    
    void inorder(TreeNode *root, vector<int> &res) {
        if (root == NULL) {
            return;
        }
        if (root->left != NULL)
            inorder(root->left, res);        
        res.push_back(root->val);
        if (root->right != NULL)
            inorder(root->right, res);                
    }
    
    bool findTarget(TreeNode* root, int target) {
        vector<int> numbers;
        inorder(root, numbers);        
        return twoSum(numbers, target);
    }
    */
};
