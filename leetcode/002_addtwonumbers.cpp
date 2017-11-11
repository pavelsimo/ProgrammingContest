/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    ListNode* tolist(vector<int> &nums) {
        if (nums.size() == 0)
            return NULL;
        ListNode *cur = new ListNode(nums[0]);
        ListNode *root = cur;        
        for(int i = 1; i < nums.size(); ++i) {
            cur->next = new ListNode(nums[i]);
            cur = cur->next;
        }
        return root;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *cur = new ListNode((l1->val + l2->val) % 10);
        ListNode *root = cur;
        int carry = (l1->val + l2->val) / 10;
        l1 = l1->next;
        l2 = l2->next;
        while (l1 != NULL || l2 != NULL || carry > 0) {
            int a = (l1 != NULL) ? l1->val: 0;
            int b = (l2 != NULL) ? l2->val: 0;
            int c = a + b + carry;
            cur->next = new ListNode(c % 10);            
            carry = c / 10;
            if (l1 != NULL)
                l1 = l1->next;
            if (l2 != NULL)
                l2 = l2->next;            
            cur = cur->next;
        }
        return root;        
    }
};

int main() {

    Solution s;

    vector<int> a = {0,8,6,5,6,8,3,5,7};
    ListNode *l1 = s.tolist(a);

    
    vector<int> b = {6,7,8,0,8,5,8,9,7};
    ListNode *l2 = s.tolist(b);

        
    cout << s.tonum(l1) << endl;
    cout << s.tonum(l2) << endl;
    cout << s.tonum(l1) + s.tonum(l2) << endl;            


    return 0;
}
