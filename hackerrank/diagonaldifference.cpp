/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

const int MAXN = 102;

int main() {    
    int n;
    scanf("%d", &n);    
    int m[n][n];    
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            scanf("%d", &m[i][j]);                              
        }
    }

    int d1 = 0;
    int d2 = 0;
    for(int i = 0; i < n; ++i)
    {
        d1 += m[i][i];
        d2 += m[i][n-i-1];
    }
    printf("%d\n", abs(d1 - d2));
    
    return 0;
}
