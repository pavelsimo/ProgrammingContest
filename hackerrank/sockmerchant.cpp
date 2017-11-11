/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

const int MAXN = 102;

int main() {
    int n;
    scanf("%d", &n);

    int x;
    int c[MAXN];
    
    for(int i = 1; i <= MAXN; ++i) {
        c[i] = 0;
    }
    
    for(int i = 0; i < n; ++i) {
        scanf("%d", &x);
        assert(x >= 1 && x <= 100);
        c[x]++;        
    }

    int res = 0;
    for(int i = 1; i <= MAXN; ++i) {
        res += c[i]/2;
    }

    printf("%d\n", res);
    
    return 0;
}
