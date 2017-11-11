/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

class Solution {
public:

    // Approach #2
    int countSegments(string s) {
        int res = 0;
        for(int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ' && (i == 0 || s[i-1] == ' '))
                ++res;
        }
        return res;        
    }
    
    // Approach #1
    /*
    int countSegments(string s) {
        int res = 0;
        bool prev = true;
        bool cur = true;
        s = " " + s + " ";
        for(int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') cur = true;
            else if (s[i] != ' ') cur = false;
            if (prev == false && cur == true) ++res;
            prev = cur;
        }
        return res;        
    }
    */
};
