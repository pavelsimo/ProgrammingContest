/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

class Solution {
public:

    vector<int> toarr(int num) {
        int x = num;        
        vector<int> res;        
        while (x > 0) {
            int d = x % 10;
            res.push_back(d);
            x /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    int tonum(vector<int> &arr) {
        int res = 0;
        for(int i = 0; i < arr.size(); ++i) {
            res = res * 10 + arr[i];
        }
        return res;
    }
    
    int maximumSwap(int num) {
        vector<int> a = toarr(num);
        int n = a.size();
        vector<int> best(n);
        int ind = n - 1;
        best[n - 1] = ind;
        for(int i = n - 2; i >= 0; --i) {
            if (a[i] > a[ind])
                ind = i;
            best[i] = ind;
        }
        for(int i = 0; i < n - 1; i++) {
            if (a[i] < a[best[i+1]]) {
                swap(a[i], a[best[i+1]]);
                break;
            }
        }
        return tonum(a);
    }
};
