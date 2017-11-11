/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();        
        if(n == 0 && m == 0) {
            return 0;
        }
        int res = -1;
        for(int i = 0; i < n; ++i) {
            int j;
            for(j = 0; j < m && i + j < n; ++j) {
                if (haystack[i+j] != needle[j])
                    break;
            }
            if (j >= m) {
                res = i;
                break;
            }
        }
        return res;
    }
};
