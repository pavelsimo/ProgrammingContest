/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

#include <stdio.h>

int main() {
    int n;
    long long x;
    long long sum = 0;
    scanf("%d", &n);
    for(int i  = 0; i < n; ++i) {
        scanf("%ld", &x);
        sum += x;
    }
    printf("%ld\n", sum);
}
