/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11466  C++  "Prime Numbers" */
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
#include <regex.h>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

typedef unsigned long long ullong;
typedef long long llong;

const ullong MAXP = 10001000LL;
vector<llong> primes, pf;

#define P1    ((MAXP+31)/32)
unsigned int sieve[P1];
#define NOTPRIME(b) ((sieve[(b)>>5] >> ((b)&31)) & 1)

void sieve_erastothenes() {
   register unsigned int p;
   primes.clear();
   primes.reserve((int) ceil((MAXP+1)/log(MAXP+1)*(1 + 1.2762/log(MAXP+1))));
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

int main(int argc, char *argv[]) {
   sieve_erastothenes();
   llong n, x;
   while(1 == scanf("%lld",&n)) {
      if(n == -1) break;
      x = n;
      for(int i = 0; i < sz(primes) && primes[i]*primes[i] <= x; ++i) {
         while(x % primes[i] == 0) {
            printf("    %lld\n",primes[i]);
            x/=primes[i];
         }
      }
      if(x > 1) printf("    %lld\n",x);
      putchar('\n');
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

