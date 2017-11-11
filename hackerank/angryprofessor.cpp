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

using namespace std;

int main(){
    int TC;
    cin >> TC;
    for(int tc = 0; tc < TC; tc++){
        int n, k, x;
        cin >> n >> k;
        int cnt = 0;        
        for(int i = 0; i < n; i++){
            cin >> x;
            if(x > 0) cnt++;
        }
        cout << ((n - cnt < k) ? "YES": "NO") << endl;
    }
    return 0;
}
