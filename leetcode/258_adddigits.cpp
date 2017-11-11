/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

class Solution {
public:

    // Approach #1: Digital Root
    int addDigits(int num) {
        return 1 + (num - 1) % 9;
    }
    
    /*      
    int addDigits(int num) {
        while (num >= 10) {
            int sum = 0;
            int x = num;
            while (x > 0) {
                int d = x % 10;
                sum += d;
                x/=10;
            }
            num = sum;
        }
        return num;
    }
    */
};
