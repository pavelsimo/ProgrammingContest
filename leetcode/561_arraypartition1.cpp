/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for(int i = 0; i < nums.size() - 1; i += 2) {
            res += nums[i];
        }
        return res;
    }
};
