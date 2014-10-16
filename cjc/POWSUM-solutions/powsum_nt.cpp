#include <iostream>

using namespace std;

/*
http://en.wikipedia.org/wiki/Geometric_progression#Geometric_series
  S(x, n) = (1 - x^(n+1)) / (1-x)

Fermat's Little Theorem
  a^(p-1) = 1 (mod p)
  a^(p-2) * a = 1 (mod p)
  a^(p-2) is modular inverse of a (mod p)  if p is prime
*/

const unsigned int P = 1000000007;

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
   // case where x == 1 leads to non existence of inverse
   //   fortunately, S(1, n) == n+1 (easy to compute)
   if (x == 1) return n+1;

   ullong a = (1LL - x + P) % P;
   // a must be co-prime of M
   uint inv = powmod(a, P-2, P);
   uint xn1 = powmod(x, n+1, P);
// cout << "a = " << a << "  inv = " << inv << "  rn1 = " << rn1 << endl;
// avoid overflow by converting to 64-bit integer before multiplication
   return (ullong(1LL - xn1 + P) * inv) % P;
}

int main(int argc, char* argv[]) {
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
