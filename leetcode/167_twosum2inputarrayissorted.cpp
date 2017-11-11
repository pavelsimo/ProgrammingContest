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

    vector<int> twoSum(vector<int>& numbers, int target) {
        int lo = 0;
        int hi = numbers.size() - 1;
        while (lo < hi) {
            int sum = numbers[lo] + numbers[hi];
            if (sum == target)
                return {lo + 1, hi + 1};
            if (sum > target)
                hi--;
            else
                lo++;
        }
        return {-1, -1};
    }
    
    /*
    int bsearch(vector<int>& numbers, int start, int end, int target) {
        int lo = start;
        int hi = end;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (numbers[mid] == target)
                return mid;                        
            else if (numbers[mid] < target)
                lo = mid + 1;
            else
                hi = mid - 1;                                
        }
        return -1;
    }
    
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        for(int i = 0; i < numbers.size() - 1; ++i) {
            int rem = target - numbers[i];
            int j = bsearch(numbers, i + 1, numbers.size() - 1, rem);
            if (j != -1) {
                res.push_back(i + 1);
                res.push_back(j + 1);
                break;
            }
        }

        return res;        
    }
    */
};

int main() {
    vector<int> numbers = {2, 3, 4};
    
    Solution s;
    auto res = s.twoSum(numbers, 6);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << endl;
    }


}
