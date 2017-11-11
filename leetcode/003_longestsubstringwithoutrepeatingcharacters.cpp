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

    int lengthOfLongestSubstring(string s) {
        int lo = 0;
        int hi = 0;
        set<char> letters;
        int res = 0;
        while (hi < s.size()) {
            if (letters.count(s[hi]) == 0) {
                res = max(res, hi - lo + 1);
                letters.insert(s[hi]);
                ++hi;                
            } else {
                letters.erase(s[lo++]);
            }            
        }

        return res;
    }
    
    /*
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int m = 256;        
        vector<vector<int> > freq(m, vector<int>(n));
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                freq[i][j] = 0;
            }
        }
        
        for(int i = 0; i < n; ++i) {
            if (i - 1 >= 0) {
                for (int j = 0; j < m; ++j)
                    freq[j][i] = freq[j][i-1];            
            }
            freq[s[i]][i]++;
        }

        int lo = 0;
        int hi = 0;
        int res = 0;
        while (hi < s.size()) {
            int k;
            for(k = 0; k < m; ++k) {                
                int r = freq[k][hi];
                int l = 0;
                if (lo - 1 >= 0)
                    l = freq[k][lo - 1];                    
                int f = r - l;
                if (f >= 2) break;                                            
            }
            if (k >= m) {
                res = max(res, hi - lo + 1);
                ++hi;                            
            } else {
                ++lo;
            }
        }        
        return res;

    }
    */
};

int main() {

    Solution s;
    cout << s.lengthOfLongestSubstring("abcabcbb") << endl;

    return 0;
}
