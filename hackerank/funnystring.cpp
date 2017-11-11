/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main() {
    int q;
    cin >> q;
    for(int i = 0; i < q; ++i){
        string s;
        cin >> s;
        
        string r = s;
        reverse(r.begin(), r.end());

        bool ok = true;
        for(int i = 0; i < s.size() - 1; ++i) {
            if(abs(s[i] - s[i+1]) != abs(r[i] - r[i+1])) {
                ok = false;
                break;
            }
        }

        cout << (ok ? "Funny" : "Not Funny") << '\n';        
    }
    return 0;
}
