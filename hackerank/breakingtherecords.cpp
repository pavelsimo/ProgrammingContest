/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int mi = 1000000000;
    int ma = -1;
    int lo = -1, hi = -1;
    int x;
    for(int i = 0; i < n; ++i) {
        scanf("%d",&x);
        if (x < mi) {
            mi = x;
            lo++;
        }
        if (x > ma) {
            ma = x;
            hi++;
        }        
    }
    printf("%d %d\n", hi, lo);
}
