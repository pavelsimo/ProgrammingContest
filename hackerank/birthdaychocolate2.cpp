/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */


#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    int sum[n];    
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        sum[i] = a[i];
    }
    
    for(int i = 1; i < n; ++i) {
        sum[i] += sum[i-1];
    }

    int d, m;
    scanf("%d %d", &d, &m);

    int res = (sum[m-1] == d ? 1: 0);
    for(int i = m; i < n; ++i) {
        if (sum[i] - sum[i - m] == d) {
            res++;
        }
    }
    
    printf("%d\n", res);
    
    return 0;
}
