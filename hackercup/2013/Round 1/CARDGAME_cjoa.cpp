#include <cstdio>

#include <algorithm>

using namespace std;

typedef long long llong;

#define MAXN 10004
#define MOD 1000000007

int N, K;
int A[MAXN];

// Pascal's Triangle
int PT[MAXN][MAXN+1];
void build_pascal_triangle() {
   PT[0][0] = 1;
   for (int n = 1; n < MAXN; ++n) {
      PT[n][0] = 1;
      for (int k = 1; k < n; ++k) {
         PT[n][k] = (PT[n-1][k-1] + PT[n-1][k]) % MOD;
      // assert(PT[n][k] >= 1);
      }
      PT[n][n] = 1;
   }
}

llong Choose(int n, int k) {
   if (n < 0 || k < 0 || k > n)  // invalid n or k
      return 0;
   return PT[n][k];
}

int main(int argc, char* argv[]) {
   build_pascal_triangle();
// fprintf(stderr, "%lld\n", Choose(10000, 5000));

   int TC;
   scanf("%d", &TC);
   for (int tc = 1; tc <= TC; ++tc) {
      scanf("%d %d", &N, &K);
      for (int i = 1; i <= N; ++i)
         scanf("%d", A+i);
      sort(A+1, A+1+N);
      llong res = 0;
      for (int n = K; n <= N; ++n) {
         res = (res + A[n] * Choose(n-1, K-1)) % MOD;
      }
      printf("Case #%d: %lld\n", tc, res);
   }

   return 0;
}
