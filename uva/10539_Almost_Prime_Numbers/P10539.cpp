/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10539  C++  "Prime Numbers" */
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

const int MAXP = 1000000;
const llong MAXN = 1000000000000LL;
vector<bool> P;
vector<llong> primes, A;

void sieve() {
   P = vector<bool>(MAXP + 2, true);
   P[0] = P[1] = false;
   for(llong i = 2; i <= MAXP; ++i) {
      if(P[i]) {
         primes.push_back(i);
         for(llong j = i * i; j <= MAXP; j+=i) 
            P[j] = false;
         llong x = i;
         while(x <= MAXN) {
            x*=i;
            A.push_back(x);
         }
      }
   }
   sort(all(A));
}

int main(int argc, char *argv[]) {
   sieve();
   int TC;
   llong lo, hi;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%lld%lld",&lo,&hi);
      printf("%d\n",int(upper_bound(all(A),hi) - A.begin()) - int(lower_bound(all(A),lo) - A.begin()));
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

