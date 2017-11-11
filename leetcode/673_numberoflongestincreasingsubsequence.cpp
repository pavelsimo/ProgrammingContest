/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:


    void printArray(vector<int>& nums, string label = "") {
        cout << label;
        for(int i = 0; i < nums.size(); ++i) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
    
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> len(nums.size());
        vector<int> cnt(nums.size());        
        
        for(int i = 0; i < len.size(); ++i) {
            cnt[i] = 1;
            len[i] = 1;
            for(int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {                    
                    if (len[i] == len[j] + 1) {
                        cnt[i] += cnt[j];
                    }                
                    if (len[i] < len[j] + 1) {
                        len[i] = len[j] + 1;                                            
                        cnt[i] = cnt[j];
                    }
                }
            }
            printArray(nums, "num: ");
            printArray(len, "len: ");
            printArray(cnt, "cnt: ");
            cout << endl;
            
        }

        int res = 0;
        
        return res;
    }
};


int main() {
    Solution s;
    vector<int> a = {1,2,4,3,5,4,7,2};
    cout << s.findNumberOfLIS(a) << endl;
    return 0;
}
