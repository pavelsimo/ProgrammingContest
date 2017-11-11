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

    // Approach #2: Horizontal Scanning    
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        string prefix = strs[0];
        for(int i = 1; i < strs.size(); ++i) {
            while (strs[i].find(prefix) != 0) {                
                prefix = prefix.substr(0, prefix.size() - 1);
                if (prefix == "")
                    return "";
            }
        }
        return prefix;
    }
    
    // Approach #1: Hashing
    string longestCommonPrefix(vector<string>& strs) {
        map<string, int> freq;
        for(int i = 0; i < strs.size(); ++i) {
            for(int j = 0; j <= strs[i].size(); ++j) {
                string key = strs[i].substr(0, j);
                freq[key]++;
            }
        }
        string res = "";
        int best = 0;
        for(auto it = freq.begin(); it != freq.end(); ++it) {
            string s = it->first;
            int cnt = it->second;
            if (cnt >= best) {
                if (s.size() >= res.size()) {
                    res = s;
                    best = cnt;                
                }
            }
        }
        return res;
    }
};

int main() {

    vector<string> arr = {"a"};
    Solution s;
    cout << s.longestCommonPrefix(arr) << endl;

    return 0;
}
