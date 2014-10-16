/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10849  C++  "Math, Chess, Ad Hoc, Bishops" */
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
   int TC, C;
   llong N, r1, c1, r2, c2;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d%lld",&C,&N);
      while(C-- > 0) {
         scanf("%lld%lld%lld%lld",&r1,&c1,&r2,&c2);
         if(r1 == r2 && c1 == c2) {
            puts("0"); 
         } else if(((r1 + c1) % 2LL) == ((r2 + c2) % 2LL) ) {
            if(abs(r1 - r2) == abs(c1 - c2)) puts("1");
            else puts("2");
         } else {
            puts("no move");
         }
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

