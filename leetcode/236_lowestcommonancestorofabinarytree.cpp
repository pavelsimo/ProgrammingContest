/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

#include <iostream>
#include <stack>
#include <vector>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    vector<TreeNode*> PathToNode(TreeNode *root, TreeNode *q) {
        
        if (root == NULL)
            return vector<TreeNode*>();
        
        map<TreeNode*, TreeNode*> parent;
        
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()) {
            TreeNode *cur = s.top();
            s.pop();
            if (cur->left != NULL) {
                parent[cur->left] = cur;
                s.push(cur->left);
            }
            if (cur->right != NULL) {
                parent[cur->right] = cur;
                s.push(cur->right);
            }            
        }

        TreeNode *node = q;
        stack<TreeNode*> tmp;
        tmp.push(q);
        while (parent.count(node) > 0) {
            TreeNode *p = parent[node];
            tmp.push(p);
            node = p;
        }

        vector<TreeNode*> res;
        res.reserve(tmp.size());
        while (!tmp.empty()) {
            TreeNode *cur = tmp.top();
            tmp.pop();
            res.push_back(cur);
        }
        
        return res;        
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (root == NULL)
            return NULL;
               
        auto path1 = PathToNode(root, p);
        auto path2 = PathToNode(root, q);
        int n = min(path1.size(), path2.size());
        TreeNode *res = path1[0];
        for(int i = 1; i < n; ++i) {
            if (path1[i] != path2[i])
                break;
            res = path1[i];
        }

        return res;
    }
};

void PrintPath(TreeNode *root, TreeNode *q) {
    Solution s;    
    auto path = s.PathToNode(root, q);
    for(int i = 0; i < path.size(); ++i) {
        if (i > 0) cout << " -> ";
        cout << path[i]->val;
    }
    cout << endl;
}

int main() {


    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(6);            
    root->left->right = new TreeNode(2);
    
    root->right->left = new TreeNode(0);            
    root->right->right = new TreeNode(8);

    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);        


    Solution s;
    PrintPath(root, root->left->left);
    PrintPath(root, root->left->right->right);
    TreeNode *lca = s.lowestCommonAncestor(root, root->left->left, root->left->right->right);
    cout << lca->val << endl;    
    
    return 0;
}
