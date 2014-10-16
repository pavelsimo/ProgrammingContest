#include <cstdio>
#include <cmath>

#include <algorithm>

using namespace std;

typedef long long llong;

#define EPS 1e-10

int C, D;

int P[204];
int V[204];

int N;
int A[1000004];

bool check(double t) {
   double x = A[0] - t;
   for (int i = 1; i < N; ++i) {
      x += D;
      if (A[i] < x) {
         if (x-A[i] > t + EPS) return false;
      }
      else {
         x = max(x, A[i] - t);
      }
   }
   return true;
}

int main(int argc, char* argv[]) {
   int TC;
   scanf("%d", &TC);
   for (int tc = 1; tc <= TC; ++tc) {
      scanf("%d %d", &C, &D);
      N = 0;
      for (int i = 0; i < C; ++i) {
         scanf("%d %d", P+i, V+i);
         for (int n = 0; n < V[i]; ++n)
            A[N++] = P[i];
      }

      double lo = 0.0, hi = 1e10;
      for (int t = 0; t < 100; ++t) {
         double mid = lo + (hi-lo)/2;
         if (check(mid))
            hi = mid;
         else
            lo = mid;
      }
      printf("Case #%d: %.8lf\n", tc, lo);
   }
   return 0;
}
