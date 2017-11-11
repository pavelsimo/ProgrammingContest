/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

#include <bits/stdc++.h>
#include <cassert>

using namespace std;

typedef long long llong;
const llong INF = 10000000000000000LL;

llong tonum(const string &s, int index, int n) {
    assert(index >= 0 && index < s.size());
   
    int j = index + n;    
    if (j >= s.size())
        j = s.size();
    
    llong res = 0LL;    
    for(int i = index; i < j; ++i) {
        res = res*10LL + (s[i] - '0');        
    }
    
    return res;
}

int main() {
    int q;
    cin >> q;
    for(int tc = 0; tc < q; ++tc){
        string s;
        cin >> s;

        llong first = -1;
        bool ok = false;        
        for(int sz = 1; sz <= s.size() / 2; ++sz) {
            bool found = true;
            llong prev = -1;
            for(int i = 0; i < s.size(); i+=sz) {
                if (prev == -1) {
                    prev = tonum(s, i, sz);
                    first = prev;
                    continue;
                }

                if (s[i] == '0') {
                    found = false;
                    break;
                }
                
                llong x1 = tonum(s, i, sz);
                llong x2 = tonum(s, i, sz + 1);
                if (x1 - prev == 1) {
                    prev = x1;                    
                } else if(x2 - prev == 1) {
                    prev = x2;
                    ++i;
                } else {
                    found = false;
                    break;
                }
            }
            if(found) {
                ok = true;
                break;
            }
        }
        
        if(ok) {
            cout << "YES " << first << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
