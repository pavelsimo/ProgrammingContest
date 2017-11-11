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

int main() {

    int n, k;    
    scanf("%d %d", &n, &k);
    assert(k > 0);

    int a[n];
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    int res = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            if ((a[i] + a[j]) % k == 0) {
                res++;
            }
        }        
    }

    printf("%d\n", res);
    
    return 0;
}
