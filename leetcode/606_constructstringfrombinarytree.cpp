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


    string tostr(int num) {
        string res = "";
        while (num > 0) {
            int d = num % 10;
            char ch = (char) ('0' + d);
            res = ch + res;
            num /= 10;
        }
        return res;
    }
    
    void preorder(TreeNode *root, string &s) {
        if (root == NULL)
            return;
        s += tostr(root->val);

        if (root->left != NULL) {
            s += "(";            
            preorder(root->left, s);
            s += ")";                    
        }

        if (root->right != NULL) {
            s += "(";
            preorder(root->right, s);
            s += ")";                        
        }
    }
    
    string tree2str(TreeNode* t) {
        string s = "";        
        preorder(t, s);
        string res = "";
        
        for(int i = 0; i < s.size(); ++i) {
            /*
              if (i + 1 < s.size() && s[i] == '(' && s[i+1] == ')')
              ++i;
              else
            */
            res += s[i];            
        }        
        return res;
    }
};
