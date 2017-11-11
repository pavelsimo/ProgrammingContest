/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN;
        int prod = 1;
        for(int i = 0; i < nums.size(); ++i) {
            prod *= nums[i];
            res = max(res, prod);
            if (prod <= 0) prod = 1;            
        }
        return res;
    }
};
