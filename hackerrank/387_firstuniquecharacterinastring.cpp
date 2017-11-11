/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26];
        memset(freq, 0, sizeof(freq));
        for(int i = 0; i < s.size(); ++i) {
            freq[s[i]-'a']++;
        }
        for(int i = 0; i < s.size(); ++i) {
            if (freq[s[i]-'a'] == 1)
                return i;
        }
        return -1;
    }
};
