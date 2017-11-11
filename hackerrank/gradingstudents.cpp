/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

#include <stdio.h>

int main() {

    int n, x;
    scanf("%d", &n);
    
    while(n-- > 0) {
        scanf("%d", &x);
        if (x < 38) {
            printf("%d\n", x);
        } else {
            if ((x + 1) % 5 == 0) printf("%d\n", x+1);
            else if ((x + 2) % 5 == 0) printf("%d\n", x+2);
            else printf("%d\n", x);                        
        }
    }   

    return 0;
}
