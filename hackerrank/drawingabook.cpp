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
    scanf("%d", &n);
    int p; 
    scanf("%d", &p);

    int p1 = p / 2;
    int p2 = (n / 2) - p1;
    printf("%d\n", (p1 < p2) ? p1: p2);    
    return 0;
}
