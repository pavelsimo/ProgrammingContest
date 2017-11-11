/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */


#include <cstdio>
#include <algorithm>

using namespace std;

int main() {

    int s; 
    int n; 
    int m; 
    scanf("%d %d %d", &s, &n, &m);    

    int k[n];
    for(int i = 0; i < n; i++) {
       scanf("%d", &k[i]);
    }
    
    int d[m];
    for(int i = 0; i < m; i++){
       scanf("%d", &d[i]);
    }

    int res = -1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (k[i] + d[j] <= s) {
                res = max(res, k[i] + d[j]);
            }            
        }
    }

    printf("%d\n", res);    

    return 0;
}
