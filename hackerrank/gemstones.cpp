/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 102;
const int NCHARS = 26;

int freq[MAXN][NCHARS];

int main() {

    memset(freq, 0, sizeof(freq));
    
    int n;
    cin >> n;

    string s;
    for(int i = 0; i < n; ++i){
        cin >> s;
        for(int j = 0; j < s.size(); ++j) {
            freq[i][s[j]-'a']++;
        }
    }

    int res = 0;
    for(int i = 0; i < NCHARS; ++i) {
        int j;
        
        for(j = 0; j < n; ++j) {
            if (!freq[j][i]) break;
        }
        
        if(j >= n) {
            ++res;
        }
    }
    
    cout << res << endl;
    return 0;
}
