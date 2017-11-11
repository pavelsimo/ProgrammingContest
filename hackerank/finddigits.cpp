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

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n, cnt = 0;
        cin >> n;
        int t = n;
        while(t > 0) {
            int d = t % 10;
            if (d != 0 && n % d == 0) cnt++;
            t /= 10;
        }
        cout << cnt << endl;
    }
    return 0;
}
