/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

string letters[12] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

class Solution {
public:

    void go(int cur, int n, string s, const string &digits, vector<string> &ans) {
        if (cur >= n) {
            ans.push_back(s);
            return;
        }
        string p = letters[digits[cur] - '0'];
        for(int i = 0; i < p.size(); ++i) {
            char ch = p[i];
            go(cur + 1, n, s + ch, digits, ans);
        }
    }
    
    vector<string> letterCombinations(string digits) {        
        vector<string> res;
        if (digits.size() == 0)
            return res;
        go(0, digits.size(), "", digits, res);
        return res;
    }
};
