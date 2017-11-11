/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

map<char, int> freq;

bool cmp(char lhs, char rhs) {
    if (freq[lhs] != freq[rhs])
        return freq[lhs] > freq[rhs];
    return lhs > rhs;
}

class Solution {
public:
    
    string frequencySort(string s) {
        freq.clear();
        
        for(int i = 0; i < s.size(); ++i) {
            freq[s[i]]++;
        }

        sort(s.begin(), s.end(), cmp);

        return s;        
    }
};
