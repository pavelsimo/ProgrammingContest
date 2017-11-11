/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

class Solution {
public:

    void reverse(string &s, int i, int j) {
        int lo = i;
        int hi = j;
        while (lo < hi) {
            swap(s[lo], s[hi]);
            ++lo;
            --hi;
        }        
    }
    
    string reverseWords(string s) {
        int lo = 0;
        int hi = 0;
        for(int i = 0; i < s.size(); ++i) {
            if (i == 0 || s[i-1] == ' ' && s[i] != ' ') {
                lo = i;                
            }
            
            if (s[i-1] != ' ' && s[i] == ' ') {
                hi = i - 1;
                reverse(s, lo, hi);
            }
            
            if (i == s.size() - 1) {
                hi = i;
                reverse(s, lo, hi);
            }            
        }
        return s;
    }
};
