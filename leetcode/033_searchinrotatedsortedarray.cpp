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

    int search_pivot(vector<int> &nums) {
        int lo = 0;
        int hi = nums.size() - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (mid + 1 <= hi && nums[mid] > nums[mid + 1]) {
                return mid + 1;
            } else if (mid - 1 >= lo && nums[mid-1] > nums[mid]) {
                return mid;
            } else if (nums[lo] >= nums[mid]) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return 0;
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = search_pivot(nums);        
        int lo = 0;
        int hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int lo2 = (pivot + lo) % n;
            int hi2 = (pivot + hi) % n;
            int mid2 = (mid + pivot) % n;
            if (nums[mid2] == target) {
                return mid2;
            }            
            else if (target > nums[mid2]) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }            
        }
        return -1;
    }
};

int main() {

    vector<int> a = {3, 1};
    Solution s;
    cout << s.search(a, 1) << endl;
    return 0;
}
