/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

class Solution {
public:

    void go(int cur, string s, string word, vector<string> &ans) {
        if (cur >= word.size()) {
            ans.push_back(s);
            return;
        }

        bool ok = (s.size() == 0 || (s.size() >= 1 && !isdigit(s[s.size()-1])));
        if (ok) {
            int rem = word.size() - cur;        
            for (int i = 1; i <= word.size(); ++i) {
                string num = tostr(i);
                if (i <= rem) {
                    go(cur + i, s + num, word, ans);                
                }
            }        
        }
        go(cur + 1, s + word[cur], word, ans);
    }
    
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        go(0, "", word, res);
        return res;
    }
};
