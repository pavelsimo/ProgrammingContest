/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */


class Solution {
public:

    void moveZeroes(vector<int>& nums) {        
        for (int lo = 0, hi = 0; hi < nums.size(); ++hi) {
            if (nums[hi] != 0) {
                swap(nums[lo], nums[hi]);
                lo++;
            }
        }
    }

    /*
    void moveZeroes(vector<int>& nums) {
        int cnt = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) cnt++;
        }
        
        for(int i = 0, j = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                nums[j] = nums[i];
                j++;
            }            
        }

        int hi = nums.size() - 1;
        while (cnt-- > 0) {
            nums[hi] = 0;
            hi--;
        }                
    }
    */
    
    /*
    void moveZeroes(vector<int>& nums) {
        for(int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] == 0) {
                for(int j = i; j < nums.size() - 1; ++j) {
                    if (nums[j+1] == 0) break;
                    swap(nums[j], nums[j+1]);
                }
            }
        }
    }
    */
};
