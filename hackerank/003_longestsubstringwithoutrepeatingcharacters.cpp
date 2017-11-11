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
        int n = s.size();
        int m = 26;        
        vector<vector<int> > freq(m, vector<int>(n));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                freq[i][j] = 0;
            }
        }
        for(int i = 0; i < n; ++i) {
            int j = s[i] - 'a';
            freq[j][i]++;
            if (i - 1 >= 0)
                freq[j][i] += freq[j][i-1];
        }        

        int res = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                int k;
                for(k = 0; k < m; ++k) {
                    int from = freq[k][j];
                    int to = freq[k][i];
                    int f = to - from;
                    cout << f << endl;
                    if (f >= 2) break;                                            
                }
                if (k >= m) {
                    res = max(res, j - i + 1);
                }
            }
        }        
        return res;

    }
};

int main() {
    Solution s;
    cout << s.lengthOfLongestSubstring("abcabcbb") << endl; 
    return 0;
}
