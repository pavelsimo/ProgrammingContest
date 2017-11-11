/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */


void postOrder(node *root) {

    if (root == NULL)
        return;
    
    if (root->left != NULL) {
        postOrder(root->left);
    }    

    if (root->right != NULL) {
        postOrder(root->right);
    }

    cout << root->data << " ";    
}
