/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  350  C++  "Math, Cycle, MOD" */
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

int main(int argc, char *argv[]) {
   llong Z, I, M, L, t;
   for(int tc = 1; scanf("%lld%lld%lld%lld",&Z,&I,&M,&L) == 4; ++tc) {
      if(!Z && !I && !M && !L) break;
      for(int i = 0; i < M; ++i) 
         L = (Z * L + I) % M;
      t = L;
      for(int i = 1; i <= M; ++i) {
         t = (Z * t + I) % M;
         if(L == t) {
            printf("Case %d: %d\n",tc,i);
            break;
         }
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

