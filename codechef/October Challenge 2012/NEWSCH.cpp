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

const int MAXN = 2;
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

inline Matrix mpow(Matrix &X, llong N) {
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

X =

   2   3
   1   0

f(n) = 2f(n - 1) + 3f(n-2)
ans = 12f(n) 

*/

#define DEBUG(x) cout << #x << ": " << x << endl

int main() { 
   int TC, res;
   llong N;
   Matrix m1, m2;
   scanf("%d",&TC);  
   while(TC-- > 0) {
      scanf("%lld",&N);  
      memset(m1.mat, 0, sizeof(m1.mat));
      m1.mat[0][0] = 2; m1.mat[0][1] = 3;
      m1.mat[1][0] = 1; m1.mat[1][1] = 0;
      m2 = mpow(m1, N - 1);
      res = (12LL * m2.mat[1][0]) % MOD;
      printf("%d\n", res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
