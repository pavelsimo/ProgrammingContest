/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

#include <bits/stdc++.h>
#include <set>

using namespace std;

int main() {

    int n;
    cin >> n;

    string s;
    cin >> s;
    
    int result = 0;    
    set<char> t;
    for(int i = 0; i < s.size(); ++i) {
        t.insert(s[i]);        
    }
    
    vector<char> letters(t.begin(), t.end());
    int res = 0;
    for(int i = 0; i < letters.size(); ++i) {
        for(int j = i + 1; j < letters.size(); ++j) {
            int k = 0;
            int size = 0;
            char prev = '\0';
            for(; k < s.size(); ++k) {
                if(s[k] == letters[i] ||
                   s[k] == letters[j]) {                    
                    if(prev != '\0' && prev == s[k]) {
                        break;
                    }
                    prev = s[k];
                    ++size;
                }
            }
            
            if (k >= s.size()) {
                res = max(res, size);
            }
        }
    }
    
    cout << res << '\n';
    
    return 0;
}
