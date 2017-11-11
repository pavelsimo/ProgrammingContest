/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());        

        vector<vector<int>> res;
        int n = nums.size();                        
        for(int i = 0; i < n; ++i) {
            int target = -nums[i];
            int lo = i + 1;
            int hi = n - 1;
            while (lo < hi) {
                int sum = nums[lo] + nums[hi];
                if (sum < target)
                    lo++;
                else if (sum > target)
                    hi--;
                else {
                    int a = nums[lo];
                    int b = nums[hi];
                    int c = nums[i];
                    res.push_back({a, b, c});
                    while (lo < hi && nums[lo] == a) lo++;
                    while (lo < hi && nums[hi] == b) --hi;                    
                }
            }
            while (i + 1 < n && -nums[i + 1] == target)
                ++i;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {-4, -1, -1, 0, 1, 2};
    auto res = s.threeSum(nums);
    for(int i = 0; i < res.size(); ++i) {
        for(int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
