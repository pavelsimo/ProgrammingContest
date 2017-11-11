/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

#include <cmath>
#include <cstdio>
#include <cassert>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 102;

int main() {
    
    vector<int> a(MAXN, 0);    
    int n, x;
    cin >> n;

    for(int i = 0; i < n; ++i) {
        cin >> x;
        a[x]++;        
    }


    int cnt = 0;
    vector<int> freq;
    for(int i = 0; i <= 100; ++i) {
        if(a[i] > 0) {
            cnt++;
            freq.push_back(a[i]);
        }
    }
    
    sort(freq.begin(), freq.end());

    int res = 0;
    for(int i = 0; i < cnt - 1; ++i) {
        res += freq[i];
    }

    cout << res << endl;
    
    return 0;
}
