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
    ListNode* oddEvenList(ListNode* head) {

        if (head == NULL) {
            return NULL;
        }

        ListNode *odd = new ListNode(0);
        ListNode *even = new ListNode(0);
        ListNode *root_even = NULL;
        ListNode *root_odd = NULL;
        while (head != NULL) {            
            if (head->val % 2 == 0) {
                even->next = new ListNode(head->val);
                even = even->next;
                if (root_even == NULL) 
                    root_even = even;
            } else {                
                odd->next = new ListNode(head->val);
                odd = odd->next;
                if (root_odd == NULL) 
                    root_odd = odd;
            }
            head = head->next;
        }        
        odd->next = root_even;
        return root_odd;
    }
};
