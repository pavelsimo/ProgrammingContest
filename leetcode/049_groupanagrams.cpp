/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string> > anagrams;
        for(int i = 0; i < strs.size(); ++i) {
            string key = strs[i];
            sort(key.begin(), key.end());
            anagrams[key].push_back(strs[i]);
        }

        vector<vector<string>> res;
        for(auto it = anagrams.begin(); it != anagrams.end(); ++it) {
            res.push_back(it->second);
        }
        return res;
    }
};
