/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */


/*
  Delete Node at a given position in a linked list 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Delete(Node *head, int position) {
    
    if(head == NULL) {
        return NULL;
    }

    if(position == 0) {        
        if(head->next != NULL) {
            Node *next = head->next;
            delete head;
            head = next;
        } else {
            delete head;
            head = NULL;
        }
    } else {    
        Node *prev = NULL;
        Node *cur = head;
        for(int i = 0; cur != NULL; ++i) {
            if (i == position) {       
                if (prev != NULL) {
                    prev->next = cur->next;                    
                }
                delete cur;
                cur = NULL;
                break;
            }        
            prev = cur;
            cur = cur->next;            
        }
    }
    
    return head;
}
