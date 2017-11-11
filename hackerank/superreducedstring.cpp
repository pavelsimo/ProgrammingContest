/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string super_reduced_string(string s) {
    string res = s;
    while (true) {
        bool pairs = false;
        string t = "";
        for(int i = 0; i < res.length(); ++i) {
            if(i + 1 < res.length() && res[i] == res[i+1]) {
                ++i;
                pairs = true;
            } else {
                t += res[i];
            }
        }
        res = t;
        if (!pairs) break;
    }
    
    return res.length() > 0 ? res: "Empty String";
}

int main() {
    string s;
    cin >> s;
    string result = super_reduced_string(s);
    cout << result << endl;
    return 0;
}
