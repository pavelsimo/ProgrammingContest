/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
    
    // Approach #2: Two Pointers
    void merge(vector<int>& A, int n, vector<int>& B, int m) {
        int i = n - 1;
        int j = m - 1;
        int k = n + m - 1;
        while (i >= 0 && j >= 0) {
            if (A[i] > B[j])
                A[k--] = A[i--];
            else
                A[k--] = B[j--];
        }
        while (j >= 0)
            A[k--] = B[j--];
    }       

    /*
    // Approach #1: Sorting
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        if (nums1.size() == 0 || nums2.size() == 0)
            return;;
        int i = 0;
        for(i = 0; i < n; ++i) {
            if (nums2[0] < nums1[i]) {
                swap(nums1[i], nums2[0]);
                sort(nums2.begin(), nums2.end());
            }
        }
        for(int j = i; j < n + m; ++j) {
            nums1[j] = nums2[j-i];
        }
    }
    */
};

int main() {
    Solution s;
    vector<int> nums1 = {1,2,3,8,9,0,0,0};
    vector<int> nums2 = {2,5,6};
    s.merge(nums1, 5, nums2, 3);
    for(int i = 0; i < nums1.size(); ++i) {
        cout << nums1[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < nums2.size(); ++i) {
        cout << nums2[i] << " ";
    }
    cout << endl;

    

    return 0;
}
