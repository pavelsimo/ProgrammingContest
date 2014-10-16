/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12470  C++  "Tribonacci, Matrix Exponentiation" */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long llong;

const int MAXN = 3;
const int MOD = 1000000009;

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

int main(int argc, char *argv[]) {
   llong N;
   while(cin >> N) {
      if(!N) break;
      Matrix m1, m2;
      memset(m1.mat, 0, sizeof(m1.mat));
      m1.mat[0][0] = 1; m1.mat[0][1] = 1; m1.mat[0][2] = 1; 
      m1.mat[1][0] = 1; m1.mat[2][1] = 1;
      m2 = mpow(m1, N - 1);   
      cout << (2LL * m2.mat[2][0] + m2.mat[2][1]) % MOD << endl;      
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
