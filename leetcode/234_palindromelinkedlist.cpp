/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

#include <iostream>
#include <cassert>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    ListNode* reverse(ListNode *head) {
        ListNode *cur = head;
        ListNode *prev = NULL;
        while (cur != NULL) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL)
            return true;
        if (head->next == NULL)
            return true;
        
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }        
        
        ListNode *lo = head;
        ListNode *hi = slow;
        if (fast != NULL) { // odd elements
            hi = slow->next;
        }        
        hi = reverse(hi);
        assert(hi != NULL);        
        while (hi != NULL) {
            assert(lo != NULL && hi != NULL);
            if (lo->val != hi->val)
                return false;
            lo = lo->next;
            hi = hi->next;
        }        
        return true;
    }


    
    /*
    //  
    // Approach #1: Calculating the middle position
    //
    int length(ListNode *head) {
        ListNode *cur = head;
        int res = 1;
        while(cur != NULL) {
            ++res;
            cur = cur->next;
        }
        return res;
    }


    bool isPalindrome(ListNode* head) {
        if (head == NULL)
            return true;
        if (head->next == NULL)
            return true;

        ListNode *lo = head;
        ListNode *hi = head;
        int n = length(head);
        int k = ((n % 2) == 0) ? (n / 2) - 1: (n / 2);
        for(int i = 0; i < k; ++i) {
            hi = hi->next;
        }
        hi = reverse(hi);
        assert(hi != NULL);        
        while (hi != NULL) {
            assert(lo != NULL && hi != NULL);
            if (lo->val != hi->val)
                return false;
            lo = lo->next;
            hi = hi->next;
        }        
        return true;
    }
    */
};

int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next = new ListNode(1);

    Solution s;
    cout << s.isPalindrome(head) << endl;
    return 0;
}
