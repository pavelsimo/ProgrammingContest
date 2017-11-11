/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

#include <stdio.h>

int main() {

    int n, m;
    scanf("%d %d", &n, &m);
    
    int a[n];    
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);        
    }

    int b[m];    
    for(int i = 0; i < m; ++i) {
        scanf("%d", &b[i]);                
    }

    int res = 0;
    for(int k = 1; k <= 100; ++k)
    {
        int ok = 1;
        for(int i = 0; i < n; ++i) {
            if(k % a[i] != 0) {
                ok = 0;
                break;
            }
        }

        if(ok) {
            for(int i = 0; i < m; ++i) {
                if(b[i] % k != 0) {
                    ok = 0;
                    break;
                }
            }
        }

        if(ok) {
            res++;
        }
    }

    printf("%d\n", res);
    
    
    return 0;
}
