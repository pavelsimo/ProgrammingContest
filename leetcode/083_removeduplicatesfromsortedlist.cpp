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


    // Approach #2
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *cur = head;
        while (cur != NULL && cur->next != NULL) {
            if (cur->next->val == cur->val) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
    
    // Approach #1
    /*
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *prev = NULL;
        ListNode *cur = head;
        while (cur != NULL) {
            if (prev != NULL) {
                while (cur != NULL && prev->val == cur->val) {
                    ListNode *tmp = cur;
                    prev->next = cur->next;
                    cur = cur->next;
                    delete tmp;
                }
            }
            prev = cur;
            if (cur != NULL)
                cur = cur->next;
        }
        return head;
    }
    */
};
