/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> freq;
        for(int i = 0; i < nums.size(); ++i) {

        }
        int threshold = nums.size();
        for(int i = 0; i < nums.size(); ++i) {
            freq[nums[i]]++;
            if (2 * freq[nums[i]] >= threshold)
                return nums[i];
        }
        return -1;
    }
};

