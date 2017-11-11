/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

#include <bits/stdc++.h>

using namespace std;

int main(){
    int q;
    string pattern = "hackerrank";
    cin >> q;
    while(q-- > 0){
        string s;
        cin >> s;
        int k = 0;
        for(int i = 0; i < s.length(); ++i) {
            if (s[i] == pattern[k]) k++;
            if (k >= pattern.length()) break;                        
        }
        cout << (k >= pattern.length() ? "YES": "NO") << endl;
    }
    return 0;
}
