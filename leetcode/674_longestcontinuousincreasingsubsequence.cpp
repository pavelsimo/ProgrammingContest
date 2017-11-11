/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int res = 0;
        int cnt = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if (i == 0 || nums[i-1] < nums[i])
                ++cnt;
            else
                cnt = 1;
            res = max(res, cnt);
        }
        return res;
    }
};
