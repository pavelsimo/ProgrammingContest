/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
            return NULL;

        ListNode *cur = head;
        ListNode *prev = NULL;
        while (cur != NULL) {
            ListNode *nxt = cur->next;
            cur->next = prev;            
            prev = cur;            
            cur = nxt;
        }

        return prev;
    }
};
