/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size());
        int res = 1;
        for(int i = 0; i < dp.size(); ++i) {
            dp[i] = 1;
            for(int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }        
        return res;
    }
    
    /*
    int n;
    vector<vector<int> > memo;
    vector<int> a;

    // Approach #1 Memoization [Memory Limit Exceeded]
    int go(int cur, int prev) {
        if (cur >= n)
            return 0;
        if (memo[cur][prev + 1] != -1)
            return memo[cur][prev+1];
        int res = 0;
        if (prev < 0 || a[prev] < a[cur])
            res = 1 + go(cur + 1, cur);
        res = max(res, go(cur + 1, prev));                
        memo[cur][prev + 1] = res;
        return res;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        a = nums;
        n = nums.size();
        memo = vector<vector<int> >(n+1);
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= n; ++j)
                memo[i].push_back(-1);
        return go(0, -1);
    }
    */
};

int main() {

    vector<int> a = {10,9,2,5,3,7,101,18};
    Solution s;
    cout << s.lengthOfLIS(a) << endl;;

}
