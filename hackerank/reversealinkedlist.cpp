/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

#include <iostream>

using namespace std;

/*
  Reverse a linked list and return pointer to the head
  The input list will have at least one element  
  Node is defined as
*/  
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node* Reverse(Node *head)
{
    Node *cur = head;
    Node *prev = NULL;
    while(cur != NULL) {
        Node *nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;        
    }
    
    return prev;
}

void Print(Node *head) {
    if (head == NULL)
        return;
    cout << head->data << '\n';
    Print(head->next);
}

int main() {
    Node *root = new Node();
    root->data = 2;
    root->next = new Node();
    root->next->data = 3;
    Print(root);
    root = Reverse(root);
    Print(root);    
}
