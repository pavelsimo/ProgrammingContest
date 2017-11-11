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
    
    int s; 
    int t; 
    scanf("%d %d",&s,&t);
    
    int a; 
    int b; 
    scanf("%d %d",&a,&b);
    
    int m; 
    int n; 
    scanf("%d %d",&m,&n);
    
    int apple;
    int cnt_apple = 0;
    for(int i = 0; i < m; i++){
       scanf("%d",&apple);
       if (a + apple >= s && a + apple <= t) {
           cnt_apple++;
       }
    }

    int orange;
    int cnt_orange = 0;
    for(int i = 0; i < n; i++){
       scanf("%d",&orange);
       if (b + orange >= s && b + orange <= t) {
           cnt_orange++;
       }       
    }

    printf("%d\n%d\n", cnt_apple, cnt_orange);
    
    return 0;
}
