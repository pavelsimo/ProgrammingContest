/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

#include <stdio.h>

int main() {

    int n, x, best = 0, res = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &x);
        if(x == best) {            
            res++;
        } else if(x > best) {
            best = x;
            res = 0;
            res++;            
        }        
    }
    
    printf("%d\n", res);

    return 0;
}
