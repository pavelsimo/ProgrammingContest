/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    int n;
    cin >> n;
    string s;
    map<string, int> words;
    
    for(int i = 0; i < n; ++i) {
        cin >> s;
        words[s]++;
    }


    int q;
    cin >> q;
    for(int i = 0; i < q; ++i) {
        cin >> s;        
        cout << words[s] << endl;
    }
    
    return 0;
}
