/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */


/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/


bool has_cycle(Node* head) {    
    Node *cur = head;
    if (cur) {
        if(cur->data == -1)
            return true;        
        int tmp = cur->data;
        cur->data = -1;        
        bool res = has_cycle(cur->next);        
        cur->data = tmp;                        
        return res;
    }
    return false;
}
