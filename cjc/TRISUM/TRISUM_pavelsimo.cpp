#include <iostream>
#include <algorithm>
#include <cassert>
#include <cstring>

using namespace std;

typedef long long llong;

const int MAXN = 3;
const int MOD = 10007;

struct Matrix {
   int mat[MAXN][MAXN];
};

inline Matrix multiply(const Matrix &a, const Matrix &b) {
   Matrix res;
   memset(res.mat, 0, sizeof(res.mat));
   for (int i = 0; i < MAXN; i++)
      for (int j = 0; j < MAXN; j++)
         for (int k = 0; k < MAXN; k++)
            res.mat[i][j] = (MOD + res.mat[i][j] + 
               llong(a.mat[i][k]) * llong(b.mat[k][j])) % MOD;
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

#define DEBUG(x) cout << #x << ": " << x << endl

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   int n, a0, b0, c0;
   Matrix x, y;
   cin >> n >> a0 >> b0 >> c0;
      
   x.mat[0][0] = 0;   x.mat[0][1] = 3; x.mat[0][2] = 3;
   x.mat[1][0] = 3;   x.mat[1][1] = 0; x.mat[1][2] = 3;
   x.mat[2][0] = 3;   x.mat[2][1] = 3; x.mat[2][2] = 0;
   
   y = mpow(x, n);
   
   int an = ((y.mat[0][0] * a0) + (y.mat[0][1] * b0) + (y.mat[0][2] * c0)) % MOD;
   int bn = ((y.mat[1][0] * a0) + (y.mat[1][1] * b0) + (y.mat[1][2] * c0)) % MOD;
   int cn = ((y.mat[2][0] * a0) + (y.mat[2][1] * b0) + (y.mat[2][2] * c0)) % MOD;
   
   cout << an << " " << bn << " " << cn << endl;
      
   return 0;
}

