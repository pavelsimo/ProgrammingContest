/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10140  C++  "Math, Prime Numbers, Segmented Sieve" */
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

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

typedef long long llong;

const int MAXN = 46600;
bool P[MAXN];
bool S[1000100];
vector<llong> primes;

void sieve() {
   memset(P,false,sizeof(P));
   for(int i = 4; i < MAXN; i+=2)
      P[i] = true;
   primes.push_back(2);
   for(llong i = 3; i < MAXN; i+=2) {
      if(!P[i]) {
         primes.push_back(i);
         for(llong j = i * i; j < MAXN; j+=2*i)
            P[j] = true;
      }
   }
}

/* 
 * Segmented Sieve
 * The idea is eliminate the multiples inside the range, taking care of not eliminate a prime number in the process,
 * if L is divisible by the current prime, it means is composite in that case with begin in L or prime[i]^2, otherwise
 * if L is not divisible by prime[i] we don't know it its composite or prime until we don't try all the possible primes
 * under sqrt(2^31 - 1) in that case we go to the next multiple of prime[i] (inside the range) by adding the remainder of
 * the division by prime[i] to L or take the sq(prime[i]) if is greater.
*/
int main(int argc, char *argv[]) {
   sieve();
   llong L, R, lo, hi, prev, c1, c2, d1, d2;
   while(2 == scanf("%lld%lld",&L,&R)) {
      prev = hi = c1 = c2 = d1 = d2 = 0LL;
      lo = 0x3f3f3f3f;
      // Segmented Sieve
      memset(S,false,sizeof(S));
      if(L == 1) 
         S[0] = true;
      for(int i = 0; i < sz(primes); ++i) {
         llong sq = primes[i]*primes[i];
         llong st = L%primes[i]==0 ? max(L,sq) : max(L + primes[i]-(L%primes[i]),sq);
         for(llong j = st; j >= L && j <= R; j+=primes[i])
            S[j-L] = true;           
      }
      for(llong i = L; i <= R; ++i) {
         if(!S[i-L]) {
            if(prev) {
               if(i - prev < lo) {
                  lo = i - prev;
                  c1 = prev;
                  c2 = i;
               }
               if(i - prev > hi) {
                  hi = i - prev;
                  d1 = prev;
                  d2 = i;
               }
            }
            prev = i;
         }
      }
      if(hi) 
         printf("%lld,%lld are closest, %lld,%lld are most distant.\n",c1,c2,d1,d2);
      else 
         puts("There are no adjacent primes.");
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
