/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

#include <cstdio>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main() {
    
    int n;
    scanf("%d", &n);    
    
    vector<int> arr(n);
    int x;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    sort(arr.begin(), arr.end());       

    long long res = 1000000000000LL;    
    for(int i = 0; i < arr.size() - 1; ++i) {
        res = min(res, (long long) abs(arr[i] - arr[i+1]));
    }
    
    cout << res << endl;
    
    return 0;
}
