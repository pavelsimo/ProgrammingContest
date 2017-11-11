/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

/*
  Print elements of a linked list in reverse order as standard output
  head pointer could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
void ReversePrint(Node *head)
{
    int n = 0;
    Node *cur = head;
    while(cur != NULL) {
        n++;
        cur = cur->next;
    }

    int *arr = new int[n];
    cur = head;
    for(int i = 0; i < n && cur != NULL; ++i) {
        arr[i] = cur->data;
        cur = cur->next;
    }

    for(int i = n-1; i >= 0; --i) {
        cout << arr[i] << '\n';
    }       
}
