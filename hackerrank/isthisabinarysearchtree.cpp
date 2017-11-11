/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

#include <iostream>

using namespace std;

typedef struct Node {
    int data;
    Node* left;
    Node* right;
} Node;


int max(Node *root) {
    int res = 0;
    
    if (root != NULL) {
        if(root->data > res)
            res = root->data;

        if(root->left != NULL) {
            int lmax = max(root->left);
            if (lmax > res)
                res = lmax;
        }

        if(root->right != NULL) {
            int rmax = max(root->right);
            if (rmax > res)
                res = rmax;
        }        
    }
    return res;
}

int min(Node *root) {
    int res = 1000000;
    
    if (root != NULL) {
        if(root->data < res)
            res = root->data;

        if(root->left != NULL) {
            int lmin = min(root->left);
            if (lmin < res)
                res = lmin;
        }

        if(root->right != NULL) {
            int rmin = min(root->right);
            if (rmin < res)
                res = rmin;
        }        
    }
    return res;
}

bool isbst(Node *root) {
   if(root == NULL)
        return true;

    if(root->left != NULL && max(root->left) > root->data)
        return false;

    if(root->right != NULL && min(root->right) < root->data)
        return false;

    if(!isbst(root->left) || !isbst(root->right))
        return false;    

    return true;
}

void calcfreq(Node *root, int *freq) {
    if (root != NULL) {
        freq[root->data]++;    
        calcfreq(root->left, freq);
        calcfreq(root->right, freq);
    }
}


bool checkBST(Node* root)
{
    bool res = isbst(root);
    
    int freq[10002];
    for(int i = 0; i < 10002; ++i)
        freq[i] = 0;

    calcfreq(root, freq);

    for(int i = 0; i < 10002; ++i) {
        if(freq[i] > 1) {
            res = false;
            break;
        }
    }

    return res;    
}
    
int main() {
    //
    // case #1
    //

    //
    //          8
    //     4         10
    //  1     5   3     20
    //
    //
    //
    
    Node *root = new Node();
    root->data = 4;

    root->left = new Node();
    root->left->data = 2;
    root->left->left = new Node();
    root->left->left->data = 1;    
    root->left->right = new Node();
    root->left->right->data = 3;    
    

    root->right = new Node();
    root->right->data = 6;
    root->right->left = new Node();
    root->right->left->data = 5;    
    root->right->right = new Node();
    root->right->right->data = 7;        

    bool res = checkBST(root);
    cout << res << endl;

    cout << max(root) << endl;
    cout << min(root) << endl;    

    //
    // case #1
    //        
}
