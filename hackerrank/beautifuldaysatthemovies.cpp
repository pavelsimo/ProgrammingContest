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

int reversed(int n) {
    int t = n;
    int res = 0;    
    while(t > 0) {
        int d = t % 10;
        res*= 10;
        res = res + d;        
        t/=10;        
    }
    return res;
}

int main() {    
    int lo, hi, k;
    scanf("%d %d %d", &lo, &hi, &k);
    int res = 0;
    for (int i = lo; i <= hi; ++i) {
        int diff = abs(i - reversed(i));
        if (diff % k == 0) res++;
    }
    printf("%d\n", res);
    return 0;
}
