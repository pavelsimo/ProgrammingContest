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

// Floyd’s Tortoise and Hare cycle-finding algorithm
bool has_cycle(Node* head) {
    if(head == NULL) 
        return false;    
    Node *fast = head->next;
    Node *slow = head;    
    while(fast != NULL && fast->next != NULL && slow != NULL) {
        if(fast == slow) {
            return true;
        }
        fast = fast->next->next;
        slow = slow->next;
    }
    return false;
}
