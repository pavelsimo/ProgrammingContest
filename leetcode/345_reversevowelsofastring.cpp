/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

class Solution {
public:

    bool isvowel(char ch) {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    
    string reverseVowels(string s) {
        int lo = 0;
        int hi = s.size() - 1;
        while (lo < hi) {
            if (isvowel(s[lo]) && isvowel(s[hi])) {
                swap(s[lo], s[hi]);
                ++lo;
                --hi;                
            }
            while (lo < hi && !isvowel(s[lo])) lo++;
            while (lo < hi && !isvowel(s[hi])) --hi;            
        }        
        return s;
    }
};
