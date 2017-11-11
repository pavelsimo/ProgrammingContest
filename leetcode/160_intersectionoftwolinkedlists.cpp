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


    //
    // Approach #2 Two Pointers
    //    
    int length(ListNode *root) {
        int res = 1;
        ListNode *cur = root;
        while (cur != NULL) {
            res++;
            cur = cur->next;
        }
        return res;
    }
    

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n = length(headA);
        int m = length(headB);
        if (n < m) {
           swap(headA, headB);
           swap(n, m);
        }            
        
        int d = n - m;
        for(int i = 0; i < d; ++i) {
            headA = headA->next;
        }

        while (headA != NULL && headB != NULL) {
            if (headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }

        return NULL;
    }
    
    /*
    //  
    // Approach #1 Set
    //
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> s;
        ListNode *cur = headA;
        while (cur != NULL) {
            s.insert(cur);
            cur = cur->next;
        }

        cur = headB;
        while (cur != NULL) {
            if (s.count(cur)) {
                return cur;
            }
            cur = cur->next;
        }                
        return NULL;
    }
    */
};
