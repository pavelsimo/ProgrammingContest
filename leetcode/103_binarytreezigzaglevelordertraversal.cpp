/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    int maxdepth(TreeNode *root) {
        if (root == NULL)
            return 0;            
        return 1 + max(maxdepth(root->left), maxdepth(root->right));        
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        int n = maxdepth(root);        
        vector<vector<int> > res(n);

        if (root == NULL) {
            return res;
        }

        queue<pair<TreeNode*, int> > q;
        q.push(make_pair(root, 0));        
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();

            TreeNode *node = cur.first;
            int dist = cur.second;

            if (dist & 1)
                res[dist].insert(res[dist].begin(), node->val);
            else
                res[dist].push_back(node->val);

            if (node->left != NULL)
                q.push(make_pair(node->left, dist + 1));
            if (node->right != NULL)
                q.push(make_pair(node->right, dist + 1));
        }


        return res;
    }
};

int main() {
    /*
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);    
    root->left->left = new TreeNode(4);        
    root->right->right = new TreeNode(5);
    */

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);            
    root->right->right = new TreeNode(7);


    Solution s;
    auto res = s.zigzagLevelOrder(root);
    cout << "[" << endl;
    for (int i = 0; i < res.size(); ++i) {
        cout << "[";        
        for(int j = 0; j < res[i].size(); ++j) {
            if (j > 0) cout << ", ";
            cout << res[i][j];
        }
        cout << "]" << endl;        
    }
    cout << "]" << endl;

    return 0;
}
