/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int i, size;
        for(i = 0, size = 0; i < n; ++i) {
            if (i + 2 < n && nums[i] == nums[i + 1] && nums[i+1] == nums[i+2])
                continue;
            nums[size++] = nums[i];
        }
        return size;
    }
};
