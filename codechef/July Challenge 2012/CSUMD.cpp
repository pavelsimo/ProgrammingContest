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

struct Matrix {
   llong mat[2][2];
};

llong MOD = 1000000007LL;

Matrix multiply(Matrix a, Matrix b) {
   Matrix res;
   memset(res.mat, 0, sizeof(res.mat));
   for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++)
         for (int k = 0; k < 2; k++)
            res.mat[i][j] = (res.mat[i][j] + (a.mat[i][k] % MOD) * (b.mat[k][j] % MOD)) % MOD;
   return res;
}

Matrix mpow(Matrix X, llong N) {
   Matrix res;
   memset(res.mat, 0, sizeof(res.mat));
   for (int i = 0; i < 2; i++)
      res.mat[i][i] = 1;
   while (N > 0) {
      if (N & 1)
         res = multiply(res, X);
      X = multiply(X, X);
      N >>= 1;
   }
   return res;
}


int main() { 
   int TC;
   llong N;
   scanf("%d",&TC);  
   while(TC-- > 0) {
      scanf("%lld",&N);  
      Matrix m1, m2;
      m1.mat[0][0] = 2; m1.mat[0][1] = 2;
      m1.mat[1][0] = 1; m1.mat[1][1] = 0;      
      m2 = mpow(m1, N - 1);
      printf("%lld\n",(3LL * m2.mat[1][0] + m2.mat[1][1]) % MOD);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
