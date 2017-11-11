/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

/*
  Insert Node at a given position in a linked list 
  head can be NULL 
  First element in the linked list is at position 0
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/

Node* InsertNth(Node *head, int data, int position) {
    if(head == NULL) {
        head = new Node();
        head->data = data;
    } else {
        if (position == 0) {
            Node *first = new Node();
            first->data = data;
            first->next = head;
            head = first;
        } else {
            Node *cur = head;
            Node *nxt = head->next;
            int k = 0;
            while(cur != NULL) {
                if (k+1 == position) {
                    Node *node = new Node();
                    cur->next = node;
                    node->data = data;
                    node->next = nxt;
                    break;
                }
                cur = cur->next;
                nxt = nxt->next;
                ++k;
            }
        }
    }    
    return head;
}
