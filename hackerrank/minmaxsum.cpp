/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

#include <stdio.h>

int main() {
    
    int n = 5;
    long long sum = 0;
    long long mi = 100000000000LL;
    long long ma = 0;
    long long x;    
    for(int i = 0; i < n; ++i) {
        scanf("%lld", &x);
        sum += x;
        if (x > ma) ma = x;
        if (x < mi) mi = x;
    }

    long long s1 = sum - ma;
    long long s2 = sum - mi;
    printf("%lld %lld\n", s1, s2);    
    return 0;
}
