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

    int n, x;
    scanf("%d", &n);

    int freq[10];
    memset(freq, 0, sizeof(freq));
    
    for(int i = 0; i < n; ++i) {
        scanf("%d", &x);
        assert(x >= 1 && x <= 5);
        freq[x]++;
    }

    int best = 5;
    for(int i = 4; i >= 1; --i) {
        if(freq[i] >= freq[best]) {
            best = i;
        }
    }

    printf("%d\n", best);
    
    return 0;
}
