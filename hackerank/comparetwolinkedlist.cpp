/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

/*
  Compare two linked lists A and B
  Return 1 if they are identical and 0 if they are not. 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int CompareLists(Node *headA, Node* headB)
{
    if (headA == NULL && headB == NULL)
        return 1;

    if (headA == NULL || headB == NULL)
        return 0;

    Node *c1 = headA;
    Node *c2 = headB;

    int ok = 1;
    while(c1 != NULL && c2 != NULL) {
        if (c1->data != c2->data) {
            ok = 0;
            break;
        }
        c1 = c1->next;
        c2 = c2->next;
    }
    
    return ok && c1 == NULL && c2 == NULL;
}
