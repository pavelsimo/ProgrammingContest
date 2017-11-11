/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

// https://leetcode.com/problems/number-of-1-bits/solution/

class Solution {
public:
/*    
    int hammingWeight(uint32_t n) {
        int res = 0;
        for(int i = 0; i < 32; ++i) {
            uint32_t mask = (1 << i);
            if ((n & mask) != 0) res++;            
        }
        return res;
    }
*/   
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n > 0) {
            res++;
            n &= (n-1);
        }
        return res;
    }
    
};
