#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

typedef long long llong;

const int MAXN = 10002;
const llong MOD = 1000000007LL;

llong A[MAXN], C[MAXN][MAXN];

int main(int argc, char *argv[]) { 
   for (int i = 0; i < MAXN; ++i) {
      for (int j = 0; j <= i; ++j) {
         if (j == 0 || j == i) 
            C[i][j] = 1LL;
         else 
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
      }
   }
   int TC, N, K;
   llong res;
   scanf("%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
      scanf("%d%d",&N,&K);
      for(int i = 0; i < N; ++i)
         scanf("%lld",&A[i]);
      sort(A, A + N);
      res = 0LL;
      for(int i = 0; i <= N - K; ++i)
         res = (res + A[N-i-1] * C[N-i-1][K-1]) % MOD;
      printf("Case #%d: %lld\n", tc, res);
   }
   return 0;
}
