#include <iostream>

using namespace std;

/*
S(n) = 1 + x + x^2 + ... + x^n

if n is even:
S(n) = ( 1 + x + x^2 + ... + x^(n/2) ) + 
       ( x^(n/2+1) + ... + x^n )
     = ( 1 + x + x^2 + ... + x^(n/2) ) +
       x^(n/2) * ( x + x^2 + ... x^(n/2) )
     = ( 1 + x + x^2 + ... + x^(n/2) ) +
       x^(n/2) * ( 1 + x + x^2 + ... x^(n/2) - 1 )
     = S(n/2) + x^(n/2) * (S(n/2) - 1)

if n is odd:
S(n) = ( 1 + x + x^2 + ... + x^((n-1)/2) ) + 
       ( x^((n-1)/2+1) + ... + x^n )
     = ( 1 + x + x^2 + ... + x^((n-1)/2) ) +
       ( x^((n+1)/2) + ... + x^n )
     = ( 1 + x + x^2 + ... + x^((n-1)/2) ) +
       x^((n+1)/2) * ( 1 + ... + x^((n-1)/2) )
     = S((n-1)/2) + x^((n+1)/2) * S((n-1)/2)
     = S((n-1)/2) * (1 + x^((n+1)/2))
*/


const unsigned int MOD = 1000000007;

typedef unsigned long long ullong;
typedef unsigned int uint;

uint powmod(ullong x, uint n, uint M) {
   ullong res = 1;
   x %= M;
   while (true) {
      if (n & 1) {
         res = (res * x) % M;
      // n--;
      }
      n >>= 1;
      if (n == 0) break;
      x = (x * x) % M;
   }
   return (uint) res;
}

uint S(ullong x, uint n) {
   if (n == 0) return 1;
   if (n & 1) {
      ullong Sn2 = S(x, (n-1)/2);
      ullong xn2 = powmod(x, (n+1)/2, MOD);
      return (Sn2 * (1 + xn2)) % MOD;
   }
   else {
      ullong Sn2 = S(x, n/2);
      ullong xn2 = powmod(x, n/2, MOD);
      return (Sn2 + (xn2 * ((Sn2 + MOD - 1) % MOD) % MOD)) % MOD;
   }
}

int main() {
   ios_base::sync_with_stdio(false);
   int TC;
   cin >> TC;
   for (int tc = 1; tc <= TC; ++tc) {
      int x, n;
      cin >> x >> n;
      uint res = S(x, n);
      cout << res << endl;
   }

   return 0;
}