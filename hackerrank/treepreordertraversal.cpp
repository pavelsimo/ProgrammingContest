/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

/* you only have to complete the function given below.  
Node is defined as  

struct node
{
    int data;
    node* left;
    node* right;
};

*/

void preOrder(node *root) {

    if (root == NULL)
        return;

    cout << root->data << " ";
    
    if (root->left != NULL) {
        preOrder(root->left);
    }    

    if (root->right != NULL) {
        preOrder(root->right);
    }    

}
