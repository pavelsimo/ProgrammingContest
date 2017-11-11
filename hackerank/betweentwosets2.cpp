/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

#include <stdio.h>

const int MAXN = 100;

int gcd(int a, int b) {
    while (a && b) {
        if (a >= b)
            a %= b;
        else
            b %= a;
    }
    return a + b;
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}


int main() {

    int n, m, x;
    scanf("%d %d", &n, &m);
    

    int A = 1;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &x);
        A = lcm(A, x);
        if(A > MAXN) {
            printf("0\n");
            return 0;
        }
    }

    int B = 0;
    for(int i = 0; i < m; ++i) {
        scanf("%d", &x);
        B = gcd(B, x);        
    }

    if(B % A != 0) {
        printf("0\n");
        return 0;
    }

    B /= A;
    int res = 0;
    for(int i = 1; i * i <= B; ++i) {
        if (B % i == 0) {
            ++res;
            if(i * i != B) {
                ++res;
            }
        }
    }
   
    printf("%d\n", res);
    
    
    return 0;
}
