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
    int n; 
    scanf("%d",&n);
    int a[n];
    for(int i = 0; i < n; i++) {        
       scanf("%d",&a[i]);
    }

    int res = 1;
    for(int i = 0; i < n; ++i) {
        int cnt = 1;
        int mi = a[i];
        int ma = a[i];
        for(int j = 0; j < n; ++j) {
            if(i == j) continue;
            if (abs(mi - a[j]) <= 1 && abs(ma - a[j]) <= 1) {
                cnt++;
                if (a[j] < mi) mi = a[j];
                if (a[j] > ma) ma = a[j];
            }
        }
        if (cnt > res) {
            res = cnt;
        }
    }

    printf("%d\n", res);
    
    return 0;
}
