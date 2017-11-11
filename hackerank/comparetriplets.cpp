/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

#include <stdio.h>

int main() {
    int alice = 0;
    int bob = 0;
    int a[3];
    int b[3];
    
    scanf("%d %d %d", &a[0], &a[1], &a[2]);    
    scanf("%d %d %d", &b[0], &b[1], &b[2]);
    
    for(int i = 0; i < 3; ++i) {
        if (a[i] > b[i]) alice++;
        else if (a[i] < b[i]) bob++;
    }
    
    printf("%d %d\n", alice, bob);
    
    return 0;
}
