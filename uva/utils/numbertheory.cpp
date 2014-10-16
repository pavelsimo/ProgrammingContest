#include <map>
#include <vector>
#include <bitset>

using namespace std;


// ============================================================================
// Number Theory
// ============================================================================


// GCD
//#include <algorithm>
//#define gcd(a, b) __gcd(a, b)

template<typename INT>
INT gcd(INT a, INT b) {
   if (a < 0) a = -a;
   if (b < 0) b = -b;
   if (a < b) swap(a, b);
   while (b > 0) {
      INT t = b;
      b = a % b;
      a = t;
   }
   return a > 0 ? a : 1;
}

// Recursive GCD
template<typename INT>
INT rgcd(INT a, INT b) {
   return b == 0 ? a : rgcd(b, a % b);
}

// LCM
template<typename INT>
INT lcm(INT a, INT b) {
// a*b/gcd(a,b) overflows !!!
   return a / gcd(a,b) * b;
}

template<typename INT>
struct TripleDXY {
   INT d, x, y;
   TripleDXY(INT _d = 0, INT _x = 0, INT _y = 0) : d(_d), x(_x), y(_y) {}
};

// Extended GCD, solves ax + by = GCD(a,b)
// if GCD(a,b) = 1, solves ax == 1 (mod b)  and  by == 1 (mod a)
//   ie, the modular inverse of a is x (and for b is y)
template<typename INT>
TripleDXY<INT> egcd(INT a, INT b) {
   INT x = 0, lastx = 1;
   INT y = 1, lasty = 0;
   while (b != 0) {
      INT t = b;
      INT q = a / b;
      b = a % b;
      a = t;

      t = x;
      x = lastx - q*x;
      lastx = t;

      t = y;
      y = lasty - q*y;
      lasty = t;
   }
   return TripleDXY<INT>(a, lastx, lasty);
}

// Recursive Extended GCD
template<typename INT>
TripleDXY<INT> regcd(INT a, INT b) {
   if (b == 0)
      return TripleDXY<INT>(a, INT(1), INT(0));
   TripleDXY<INT> t = regcd(b, a % b);
   return TripleDXY<INT>( t.d, t.y, t.x - (a/b)*t.y );
}


// Solve system of modular linear equations
//   x = Ai (mod Mi)
class LinearCongruence {
   //   x = A  (mod M)   cumulative equation
   //   x = Ai (mod Mi)  new equation
   bool _substitute(long long& A, long long& M, long long Ai, long long Mi) {
      // Solve A + M*j == Ai (mod Mi)

      // substract A from both sides
      Ai = (Ai - A) % Mi;
      if (Ai < 0) Ai += Mi;

      long long d = gcd(M, Mi);

      // no solution if gcd(M, Mi) does not divide Ai
      if (Ai % d != 0)
         return false;

      // divide by gcd of M and Mi
      Ai /= d;
      Mi /= d;
      long long Md = M / d;

      // find multiplicative inverse of M/d mod Mi
      TripleDXY<long long> res = egcd(Md, Mi);
      if (res.x < 0)
         res.x += Mi;

      // multiply both sides by multiplicate inverse mod Mi
      Ai = (Ai * res.x) % Mi;

      // ... to obtain j = Ai (mod Mi) = Ai + Mi*k

      // substitute back into original equation X = A + M*j
      //  X = A + M*(Ai + Mi*k) = A + M*Ai + M*Mi*k = (A + M*Ai) + (M*Mi)*k
      //  which reduces to X = A + M*k for next iterations
      //  where A = A + M*Ai,  M = M*Mi
      A += M*Ai;
      M *= Mi;
      A %= M;

      return true;
   }
public:
   int solve(const vector<int>& A, const vector<int>& M) {
      int N = (int) A.size();
      long long x = 0;
      long long m = 1;
      for (int i = 0; i < N; ++i) {
         if (!_substitute(x, m, (long long) A[i], (long long) M[i]))
            return -1;
      }
      return (int) x;
   }
};


// Solve system of modular linear equations where ni are pairwise relative prime:
//   x = Ai (mod Mi)
// http://en.wikipedia.org/wiki/Chinese_remainder_theorem
int chinese_remainder(const vector<int>& A, const vector<int>& M) {
   int N = (int) M.size();

   // P = Product of Mi
   long long P = 1;
   for (int i = 0; i < N; ++i)
      P *= M[i];

   // x = Sum i=0..k-1 Ai * ei
   long long x = 0;
   for (int i = 0; i < N; ++i) {
      TripleDXY<long long> res = egcd((long long) M[i], P/M[i]);
      assert(res.d == 1);
      x += A[i] * res.y * (P/M[i]);
      x %= P;
      if (x < 0) x += P;
   }
   return (int) x;
}

// Recursive Power Mod
unsigned int powmod(unsigned int x, unsigned int n, unsigned int m) {
   if (n == 0) return 1;
   return (n & 1) ?
      (powmod((x*x) % m, (n-1)/2, m) * x) % m :
      powmod((x*x) % m, n/2, m);
}

// Iterative Power Mod
unsigned int powmod(unsigned long long x, unsigned int n, unsigned int m) {
   unsigned long long res = 1;
   x %= m;
   while (true) {
      if (n & 1) {
         res = (res * x) % m;
      // n--;
      }
      n >>= 1;
      if (n == 0) break;
      x = (x * x) % m;
   }
   return (unsigned int) res;
}

typedef unsigned long long ullong;
// returns (x*y)%m where x*y might overflow 64-bit
ullong mulmod(ullong x, ullong y, ullong m) {
   ullong res = 0;
   x %= m;
   while (y) {
      if (y & 1) {
         res += x;
         res %= m;
      }
      x <<= 1;
      x %= m;
      y >>= 1;
   }
   return res;
}

ullong powmod(ullong x, ullong n, ullong m) {
   ullong res = 1;
   x %= m;
   while (n) {
      if (n & 1) {
         res = mulmod(res, x, m);
         n--;
      }
      x = mulmod(x, x, m);
      n >>= 1;
   }
   return res;
}


// Prime
bool is_prime(long long x) {
   if (x <= 3)
      return x >= 2;
   if ((x & 1) == 0)
      return false;
   for (unsigned long long d = 3; d*d <= x; d += 2) {
      if (x % d == 0)
         return false;
   }
   return true;
}

bool is_prime(int x) {
   int k;
   unsigned long long d;
   if (x <= 3)
      return x >= 2;
   if ((x & 1) == 0 || (x % 3) == 0)
      return false;
   for (k = 0, d = 5; d*d <= x; d += 1 << (1 << (k++ & 1))) {
      if (x % d == 0)
         return false;
   }
   return true;
}

// Prime
bool is_prime(int x) {
   /* 0010 0000 1000 1010 0010 1000 1010 1100 */
   static unsigned int isprime = 0x208A28AC;
   static unsigned int coprimes[] = {
     1, 7, 11, 13, 17, 19, 23, 29
   };

   if (x <= 31)
      return (isprime & (1 << x)) != 0;
   if ((x & 1) == 0 ||
       (x % 3) == 0 &&
       (x % 5) == 0 &&
       (x % 7) == 0 &&
       (x % 11) == 0 &&
       (x % 13) == 0 &&
       (x % 17) == 0 &&
       (x % 19) == 0 &&
       (x % 23) == 0 &&
       (x % 29) == 0)
      return false;

   for (int d = 30; ; d += 30) {
      for (int j = 0; j < 8; ++j) {
         int dd = d + coprimes[j];
         if (dd*dd > x) return true;
         if ((x % dd) == 0)
            return false;
      }
   }
   return true;
}

bool rabin_miller_test(ullong a, ullong x, ullong s, int r) {
   ullong y = powmod(a, s, x);
   if (y == 1) 
      return true;
   for (int j = 0; j < r; ++j) {
      if (y == x-1)
         return true;
      y = powmod(y, 2, x);
   // if (y == 1) return false;
   }
   return false;
}

bool is_prime_rabin_miller(ullong x, int niter=100) {
   if (x <= 3)
      return x >= 2;
   if ((x & 1) == 0 || (x % 3) == 0)
      return false;
// if ((x % 6) != 1 && (x % 6) != 5)
//    return false;

   // first few primes
   unsigned int primes[] = {
      2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43,
      47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97
   };

   int nprimes = sizeof(primes)/sizeof(unsigned int);

   if (binary_search(primes, primes+nprimes, x))
      return true;

   for (int i = 0; i < nprimes; ++i) {
   // if ((ullong(primes[i]) * primes[i]) > x) break;
      if ((x % primes[i]) == 0)
         return false;
   }

   ullong s = x-1;
   int r = 1;
   for (; !(s & 1); s >>= 1)
      ++r;

   for (int i = min(nprimes, 7)-1; i >= 0; --i) {
      ullong a = 1 + (primes[i] % (x-1));
      if (!rabin_miller_test(a, x, s, r))
         return false;
   }

   // random testing
   while (niter-- > 0) {
   // unsigned long long rnd = (((unsigned long long) rand()) << 32) | rand();
      ullong rnd = rand();
      ullong a = 1 + (rnd % (x-1));
      if (!rabin_miller_test(a, x, s, r))
         return false;
   }

   return true;
}

//
// Sieve of Erastothenes
//
#include <cmath>

#include <vector>

using namespace std;

typedef unsigned long long ullong;

vector<int> primes;

#define MAXP 1000000

//
// Sieve of Erastothenes 0
//
bool sieve[MAXP+1];
#define NOTPRIME(b) (sieve[(b)])

void sieve_erastothenes() {
   register unsigned int p;

   primes.clear();
   primes.reserve((int) ceil((MAXP+1)/log(MAXP+1)*(1 + 1.2762/log(MAXP+1))));

// memset(sieve, 0, sizeof(sieve));
   sieve[0] = sieve[1] = true;
   for (p = 2; ; ++p) {
      ullong p2 = ((ullong) p) * ((ullong) p);
      if (p2 > MAXP) break;
      if (NOTPRIME(p)) continue;
      primes.push_back(p);
      for (ullong k = p2; k <= MAXP; k += p)
         sieve[k] = true;
   }
   for (; p <= MAXP; ++p) {
      if (NOTPRIME(p)) continue;
      primes.push_back(p);
   }
}

//
// Sieve of Erastothenes 1: bitmask
//
#define P1    ((MAXP+31)/32)
unsigned int sieve[P1];
#define NOTPRIME(b) ((sieve[(b)>>5] >> ((b)&31)) & 1)

void sieve_erastothenes() {
   register unsigned int p;

   primes.clear();
   primes.reserve((int) ceil((MAXP+1)/log(MAXP+1)*(1 + 1.2762/log(MAXP+1))));

// memset(sieve, 0, sizeof(sieve));
   sieve[0] |= (1 << 0) | (1 << 1);
   for (p = 2; ; ++p) {
      ullong p2 = ((ullong) p) * ((ullong) p);
      if (p2 > MAXP) break;
      if (NOTPRIME(p)) continue;
      primes.push_back(p);
      for (ullong k = p2; k <= MAXP; k += p)
         sieve[k >> 5] |= 1 << (k & 31);
   }
   for (; p <= MAXP; ++p) {
      if (NOTPRIME(p)) continue;
      primes.push_back(p);
   }
}

//
// Sieve of Erastothenes 2: primes > 2 are odd
//
#define P1    ((MAXP+63)/64)
unsigned int sieve[P1];
#define SIEVE(b) ((sieve[(b)>>5] >> ((b)&31)) & 1)

bool isprime(int p) {
   return p==2 || (p&1) && !SIEVE((p-1)>>1);
}

void sieve_erastothenes() {
   register unsigned int p;

   primes.clear();
   primes.reserve((int) ceil((MAXP+1)/log(MAXP+1)*(1 + 1.2762/log(MAXP+1))));
   primes.push_back(2);

// memset(sieve, 0, sizeof(sieve));
   sieve[0] |= 1;
   for (p = 3; ; p += 2) {
      ullong p2 = ((ullong) p) * ((ullong) p);
      if (p2 > MAXP) break;
      if (SIEVE((p-1)>>1)) continue;
      primes.push_back(p);
      for (ullong k = p2; k <= MAXP; k += (p<<1))
         sieve[((k-1)>>1) >> 5] |= 1 << (((k-1)>>1) & 31);
   }
   for (; p <= MAXP; p += 2) {
      if (SIEVE((p-1)>>1)) continue;
      primes.push_back(p);
   }
}

//
// Sieve of Erastothenes 3
//
#define P1    ((MAXP+63)/64)
#define P2    (MAXP+1)/2

unsigned int sieve[P1];
#define SIEVE(b) ((sieve[(b)>>5] >> ((b)&31)) & 1)

bool isprime(int p) {
   return p==2 || (p&1) && !SIEVE((p-1)>>1);
}

void sieve_erastothenes() {
   register unsigned int i, j, k;

   primes.clear();
   primes.reserve((int) ceil((MAXP+1)/log(MAXP+1)*(1 + 1.2762/log(MAXP+1))));
   primes.push_back(2);

// memset(sieve, 0, sizeof(sieve));
   sieve[0] |= 1;
   const int P3 = ((int) ceil(sqrt(MAXP))+1)/2;
   for (k = 1; k <= P3; k++) {
      if (SIEVE(k)) continue;
      j = 2*k+1;
      primes.push_back(j);
      for (i = 2*k*(k+1); i < P2; i += j)
         sieve[i>>5] |= 1 << (i & 31);
   }
   for (j = 2*k+1; j <= MAXP; j += 2) {
      if (SIEVE((j-1)>>1)) continue;
      primes.push_back(j);
   }
}

//
// Sieve of Atkin
//
#define P1    ((MAXP+31)/32)
unsigned int sieve[P1];
#define PRIME(b) ((sieve[(b)>>5] >> ((b)&31)) & 1)

void sieve_atkin() {
   primes.clear();
   primes.reserve((int) ceil((MAXP+1)/log(MAXP+1)*(1 + 1.2762/log(MAXP+1))));
   primes.push_back(2);
   primes.push_back(3);

// memset(sieve, 0, sizeof(sieve));
   sieve[0] |= (1 << 2) | (1 << 3);

   int x, y, x2, y2;
   for (x = 1; (x2 = x*x) <= MAXP; ++x) {
      for (y = 1; (y2 = y*y) <= MAXP; ++y) {
         int n = 4*x2 + y2;
         int nmod12 = n % 12;
         if (n <= MAXP && (nmod12 == 1 || nmod12 == 5))
            sieve[n >> 5] ^= 1 << (n & 31);
         n = 3*x2 + y2;
         if (n <= MAXP && (n % 12) == 7)
            sieve[n >> 5] ^= 1 << (n & 31);
         if (x > y) {
            n = 3*x2 - y2;
            if (n <= MAXP && (n % 12) == 11)
               sieve[n >> 5] ^= 1 << (n & 31);
         }
      }
   }

   int n, n2;
   for (n = 5; (n2 = n*n) <= MAXP; n += 2) {
      if (PRIME(n)) {
         primes.push_back(n);
         for (int k = n2; k <= MAXP; k += n2)
            sieve[k >> 5] &= ~(1 << (k & 31));
      }
   }
   for (; n <= MAXP; n += 2)
      if (PRIME(n))
         primes.push_back(n);
}

//
// Factorization
void factorization(int n, vector<II>& fv) {
   fv.clear();
   for (int i = 0; i < primes.size(); ++i) {
      ullong p = primes[i];
      if (p*p > n) break;
      int cnt = 0;
      for (; (n % p) == 0; n /= p)
         ++cnt;
      if (cnt)
         fv.push_back(II((int) p, cnt));
   }
   if (n > 1)
      fv.push_back(II(n, 1));
}


//
// Euler's totient function
int phi(int n) { 
   int res = n; 
   for (ullong i=2; i*i <= n; ++i) { 
      if (n % i == 0) {
         res -= res / i; 
         do {
            n /= i;
         } while (n % i == 0); 
      }
   } 
   if (n > 1)
      res -= re / n; 
   return res;
} 

//
// Euler's totient function
int phi(int n) {
   int res = n;
   for (int i = 0; i < primes.size(); ++i) {
      ullong p = primes[i];
      ullong p2 = p * p;
      if (p2 > n) break;
      if (n % p == 0) {
         res -= res / p;
         do {
            n /= p;
         } while ((n % p) == 0);
      }
   }
   if (n > 1)
      res -= res / n;
   return res;
}


int main() {
   sieve_erastothenes();
   printf("Number of primes upto %d: %d\n", MAXP, (int) primes.size());
   puts("First 20 primes");
   for (int i = 0; i < primes.size() && i < 20; ++i)
      printf("%d\n", primes[i]);


   int _A[] = {2, 3, 1};
   int _M[] = {3, 4, 5};

   vector<int> A( _A, _A + sizeof(_A)/sizeof(_A[0]) );
   vector<int> M( _M, _M + sizeof(_M)/sizeof(_M[0]) );

   printf("Chinese Remainder Theorem Result: %d\n", chinese_remainder(A, M));

   printf("Linear Congruence Substitution Result: %d\n", solve_linear_congr(A, M));

   return 0;
}
