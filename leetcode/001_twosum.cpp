/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

class Solution {
public:


    // Approach #2: Complement Map
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> sum;
        for(int i = 0; i < nums.size(); ++i) {
            int x = target - nums[i];
            if (sum.find(x) != sum.end()) {
                int lo = i;
                int hi = sum[x];
                if (lo > hi)
                    swap(lo, hi);
                return {lo, hi};
            }
            sum[nums[i]] = i;
        }
        return {-1,-1};
    }
    
    /*
    // Approach #1: Two Pointers
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int> > numbers(nums.size());
        for(int i = 0; i < nums.size(); ++i) {
            numbers[i].first = nums[i];
            numbers[i].second = i;
        }

        sort(numbers.begin(), numbers.end());

        int lo = 0;
        int hi = numbers.size() - 1;
        while (lo < hi) {
            if (numbers[lo].first + numbers[hi].first == target)
                return {numbers[lo].second, numbers[hi].second};
            else if (numbers[lo].first + numbers[hi].first > target)
                hi--;
            else
                lo++;            
        }
        return {-1, -1};
    }
    */
};
