/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10791  C++  "LCM, Prime Factors" */
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

typedef long long llong;

const llong MAXN = 46342;
vector<bool> P;
vector<llong> primes;

void sieve() {
   P = vector<bool>(MAXN + 10, true);
   P[0] = P[1] = false;
   for(llong i = 2; i <= MAXN; ++i) {
      if(P[i]) {
         primes.push_back(llong(i));
         for(llong j = i + i; j <= MAXN; j+=i)
            P[j] = false;                    
      }
   }
}

int main(int argc, char *argv[]) {
   sieve();
   llong n, res, x;
   int tc = 0;
   while(1 == scanf("%lld",&n)) {
      if(!n) break;     
      if(n == 1) {
         res = 2;
      } else {
         res = 0LL;
         x = n;
         int factors = 0;
         for(int i = 0; primes[i]*primes[i] <= x && i < sz(primes); ++i) {
            llong prod = 0;
            for(int j = 0; x % primes[i] == 0; ++j) {
               if(j == 0) 
                  prod=primes[i],factors++;
               else 
                  prod*=primes[i]; 
               x/=primes[i];
            }
            res+=prod;
         }
         if(x > 1) res+=x, factors++;
         if(factors <= 1) res++;
      }
      printf("Case %d: %lld\n",++tc,res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

