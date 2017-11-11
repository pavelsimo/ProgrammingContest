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

    void perm(int lo, vector<int> &nums, vector<vector<int> > &res) {
        if (lo >= nums.size() - 1) {
            res.push_back(nums);
            return;
        }
        
        for(int k = lo; k <= nums.size() - 1; ++k) {            
            swap(nums[lo], nums[k]);
            perm(lo + 1, nums, res);
            swap(nums[lo], nums[k]);            
        }        
    }
    
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > res;
        perm(0, nums, res);
        return res;
    }
};

int main() {

    Solution s;
    vector<int> nums = {1, 2, 3};
    auto res = s.permute(nums);

    cout << res.size() << endl;
    for (int i = 0; i < res.size(); ++i) {
        vector<int> elems = res[i];
        for (int j = 0; j < elems.size(); ++j) {
            if (j > 0)
                cout << " ";
            cout << elems[j];
        }
        cout << endl;
    }

    return 0;
}




