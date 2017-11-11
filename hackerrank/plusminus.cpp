/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

#include <stdio.h>

int main() {
    int n, x;
    scanf("%d", &n);    
    int ps = 0;
    int ng = 0;
    int zr = 0;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &x);
        if(x > 0) ps++;
        else if(x < 0) ng++;
        else zr++;
    }
    printf("%.6f\n%.6f\n%.6f\n", (ps / (double)n), (ng / (double)n), (zr / (double)n));
                                                    
    return 0;
}
