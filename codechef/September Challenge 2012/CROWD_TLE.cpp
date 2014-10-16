#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <deque>
#include <numeric>
#include <iterator>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <climits>
#include <sys/time.h>

using namespace std;

typedef long long llong;

const int MAXN = 5;
const int MOD = 1000000007;

struct Matrix {
   int mat[MAXN][MAXN];
};


inline Matrix multiply(const Matrix &a, const Matrix &b) {
   Matrix res;
   memset(res.mat, 0, sizeof(res.mat));
   for (int i = 0; i < MAXN; i++)
      for (int j = 0; j < MAXN; j++)
         for (int k = 0; k < MAXN; k++)
            res.mat[i][j] = (MOD + res.mat[i][j] + llong(a.mat[i][k]) * llong(b.mat[k][j])) % MOD;
   return res;
}

inline Matrix mpow(Matrix X, llong N) {
   Matrix res;
   memset(res.mat, 0, sizeof(res.mat));
   for (int i = 0; i < MAXN; i++)
      res.mat[i][i] = 1;
   while (N > 0LL) {
      if (N & 1LL)
         res = multiply(res, X);
      X = multiply(X, X);
      N >>= 1LL;
   }
   return res;
}

/*

a(n) = 3*a(n-1) - a(n-2) - a(n-3) - 2 * a(n-4)
 
X =

   3  -1  -1  -2   0
   1   0   0   0   0
   0   1   0   0   0
   0   0   1   0   0
   0   0   0   0   0

Y = 

   3
   1
   0
   0
   0

*/

int main() { 
   int TC;
   llong N;
   Matrix m1, m2;
   scanf("%d",&TC);  
   while(TC-- > 0) {
      scanf("%lld",&N);  
      memset(m1.mat, 0, sizeof(m1.mat));
      m1.mat[0][0] = 3LL; m1.mat[0][1] = -1LL; m1.mat[0][2] = -1LL; m1.mat[0][3] = -2LL;
      m1.mat[1][0] = 1LL; m1.mat[2][1] = 1LL;  m1.mat[3][2] = 1LL;
      m2 = mpow(m1, N);
      printf("%d\n", m2.mat[3][0]);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
