/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

class Solution {
public:
    
    int myAtoi(string s) {
        int i = 0;
        while(s[i] == ' ') ++i;
        int sign = 1;
        if (s[i] == '-') {
            sign = -1;
            ++i;
        } else if (s[i] == '+') {
            sign = 1;
            i++;
        }

        long long res = 0LL;
        for (; i < s.size() && (s[i] >= '0' && s[i] <= '9'); ++i) {
            res = res * 10LL + (s[i] - '0');
            if (res * sign > INT_MAX) break;
            if (res * sign < INT_MIN) break;                                          
        }
        res *= sign;
        if (res > INT_MAX) return INT_MAX;
        if (res < INT_MIN) return INT_MIN;
        return (int) res;
    }
};
