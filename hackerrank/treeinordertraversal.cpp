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

void inOrder(node *root) {

    if (root == NULL)
        return;
    
    if (root->left != NULL) {
        inOrder(root->left);
    }

    cout << root->data << " ";        

    if (root->right != NULL) {
        inOrder(root->right);
    }
}
