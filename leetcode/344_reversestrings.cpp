/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

class Solution {
public:
    string reverseString(string s) {
        int lo = 0;
        int hi = s.size() - 1;
        string res = s;
        while (lo < hi) {
            swap(res[lo], res[hi]);
            lo++;
            hi--;
        }
        return res;
    }
};
