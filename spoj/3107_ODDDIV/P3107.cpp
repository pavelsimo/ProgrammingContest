/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ ODDDIV C++ "Binary Search, Number Theory" */
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

const int MAXN = 100010;
llong D[MAXN];
bool P[MAXN];
vector<llong> M[10010];
vector<llong> primes;

void sieve() {
   for(int i = 0; i < MAXN; ++i)
      P[i] = true, D[i] = 1;
   P[0] = P[1] = false;
   for(llong i = 2; i <= 100000; ++i) {
      if(P[i]) {
         for(llong j = i; j <= 100000; j+=i) {  
            P[j] = false;
            llong x = j * j;
            llong cnt = 1;
            while(x % i == 0) {
               cnt++;
               x/=i;
            }
            D[j] = D[j] * cnt;
         }                  
      }
   }
   for(llong i = 1; i <= 100000; ++i)
      M[D[i]].push_back(i * i);
}

int main(int argc, char *argv[]) {    
   sieve();
   int TC;
   llong k, lo, hi;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%lld%lld%lld",&k,&lo,&hi);
      if(k <= 1323) {
         llong a = lower_bound(all(M[k]),lo)-M[k].begin();
         llong b = upper_bound(all(M[k]),hi)-M[k].begin();
         printf("%lld\n",b-a);                  
      } else {
         puts("0");
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
