/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <sstream>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

class Solution {
public:

    void treePaths(TreeNode *cur, string path, vector<string> &ans) {
        if (cur == NULL) {
            return;
        }

        path += tostr(cur->val);        
        if (cur->left == NULL && cur->right == NULL) {
            ans.push_back(path);
            return;
        }

        path += "->";
        treePaths(cur->left, path, ans);
        treePaths(cur->right, path, ans);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        treePaths(root, "", res);
        return res;
    }
    
    /*
    vector<string> binaryTreePaths(TreeNode* root) {

        if (root == NULL)
            return vector<string>();
        
        vector<string> res;
        map<TreeNode*, TreeNode*> parent;
        parent[root] = NULL;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *cur = q.front();
            q.pop();

            if (cur->left != NULL) {
                parent[cur->left] = cur;
                q.push(cur->left);
            }

            if (cur->right != NULL) {
                parent[cur->right] = cur;
                q.push(cur->right);
            }                        
        }

        q.push(root);
        while (!q.empty()) {
            TreeNode *cur = q.front();
            q.pop();

            bool isleaf = true;
            if (cur->left != NULL) {
                q.push(cur->left);
                isleaf = false;
            }

            if (cur->right != NULL) {
                q.push(cur->right);
                isleaf = false;
            }
            
            if (isleaf) {
                TreeNode *child = cur;
                stack<TreeNode*> tmp;
                while (child != NULL) {
                    tmp.push(child);
                    child = parent[child];
                }

                string path = "";
                for (int i = 0; !tmp.empty(); ++i) {
                    if (i > 0) path += "->";
                    TreeNode *node = tmp.top();
                    tmp.pop();
                    path += tostr(node->val);
                }

                res.push_back(path);
            }                        
        }

        return res;
    }
    */
};

int main(int argc, char **argv) {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    Solution s;
    auto paths = s.binaryTreePaths(root);
    for (int i = 0; i < paths.size(); ++i) {
        cout << paths[i] << endl;
    }
    return 0;
}
