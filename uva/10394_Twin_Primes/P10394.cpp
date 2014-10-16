/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10394  C++  "Prime Numbers" */
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

#define MAXP 20000000
#define P1    ((MAXP+63)/64)
#define P2    (MAXP+1)/2

unsigned int sieve[P1];
#define SIEVE(b) ((sieve[(b)>>5] >> ((b)&31)) & 1)

vector<int> primes;
vector<int> A;

bool isprime(int p) {
   return p==2 || (p&1) && !SIEVE((p-1)>>1);
}

void sieve_erastothenes() {
   register unsigned int i, j, k;
   primes.clear();
   primes.reserve((int) ceil((MAXP+1)/log(MAXP+1)*(1 + 1.2762/log(MAXP+1))));
   primes.push_back(2);
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

int main(int argc, char *argv[]) {
   sieve_erastothenes();
   A.push_back(0);
   for(int i = 0, j = 0; i < sz(primes) - 1; ++i) {
      if(primes[i] + 2 == primes[i+1]) {
         j++;
         A.push_back(primes[i]);
      }
      if(j == 100002) break;
   }
   int N;
   while(1 == scanf("%d",&N))
      printf("(%d, %d)\n",A[N],A[N]+2);
   return 0;
}
/* @END_OF_SOURCE_CODE */

