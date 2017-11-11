/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

bool checkBST(Node *root, int min, int max) {
    if (root == NULL)
        return true;

    if (root->data < min || root->data > max)
        return false;

    return checkBST(root->left, min, root->data - 1)
        && checkBST(root->right, root->data + 1, max);
}


bool checkBST(Node* root)
{
    bool res = checkBST(root, 0, 100002);
    return res;    
}
