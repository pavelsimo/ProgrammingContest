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
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    int d, m;
    scanf("%d %d", &d, &m);

    int res = 0;
    for(int i = 0; i <= n - m; ++i) {
        int sum = 0;
        for(int j = i; j < n; ++j) {
            if(j - i + 1 > m) break;
            sum += a[j];
        }        
        if (sum == d) res++;    
    }
    
    printf("%d\n", res);
    
    return 0;
}
