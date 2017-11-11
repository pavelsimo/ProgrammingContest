/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

class Solution {
public:
    
    string normalize(const string &s) {
        string res = "";
        for(int i = 0; i < s.size(); ++i) {
            if (isalpha(s[i]) || isdigit(s[i])) {
                res += tolower(s[i]);
            }
        }        
        return res;
    }
    
    bool isPalindrome(string s) {
        s = normalize(s);        
        int lo = 0;
        int hi = s.size() - 1;
        while (lo < hi) {
            if (s[lo] != s[hi])
                return false;
            ++lo;
            --hi;
        }
        return true;
    }
};
