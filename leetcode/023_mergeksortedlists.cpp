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


bool cmp(ListNode *lhs, ListNode *rhs) {
    return lhs->val < rhs->val;
}

class Solution {
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> res;
        for(int i = 0; i < lists.size(); ++i) {
            ListNode *cur = lists[i];
            while(cur != NULL) {
                res.push_back(cur);
                cur = cur->next;
            }
        }

        if (res.size() == 0) {
            return NULL;
        }

        sort(res.begin(), res.end(), cmp);

        for(int i = 0; i < res.size() - 1; ++i) {
            ListNode *cur = res[i];
            ListNode *next = res[i + 1];
            cur->next = next;
        }
        
        res[res.size() - 1]->next = NULL;
        lists = res;
        
        return res[0];
    }
};
