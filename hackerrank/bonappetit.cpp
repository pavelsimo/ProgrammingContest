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
    int k; 
    scanf("%i %i", &n, &k);

    int x;
    int sum = 0;
    int d = 0;
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        sum += x;
        if (i == k) d = x;
    }
    
    int charged; 
    scanf("%i", &charged);

    int res = charged - ((sum - d) / 2);
    if (res > 0) {        
        printf("%d\n", res);        
    } else {
        printf("Bon Appetit\n");
    }   

    return 0;
}

