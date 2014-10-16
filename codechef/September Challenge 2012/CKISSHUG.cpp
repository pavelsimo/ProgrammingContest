#include <cstdio>

using namespace std;

typedef long long int64;

const int64 MOD = 1000000007LL;

int64 powmod(int64 x, int64 n, int64 m) {
   int64 res = 1LL;
   x %= m;
   while (true) {
      if (n & 1LL)
         res = (res * x) % m;
      n >>= 1LL;
      if (n == 0LL) break;
      x = (x * x) % m;
   }
   return res;
}

int main(int argc, char *argv[]) {  
   int TC;
   int64 n;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%lld",&n);
      int64 pow2 = powmod(2LL, n>>1LL, MOD);
      int64 sum  = powmod(2LL, (n>>1LL) + 1, MOD) - 2LL;
      if(n & 1) pow2 <<= 1LL;
      printf("%lld\n",(pow2 + sum) % MOD);
   }
   return 0;
}
