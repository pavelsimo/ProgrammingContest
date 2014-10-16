/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10469  C++  "Ad Hoc" */
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
   int TC;
   llong x, y, n;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%lld%lld",&x,&y);
      llong dist = abs(y-x);
      if(dist & 1) {
         dist--;
         n = sqrt(1.0 + 4.0*dist);
         n--;
         n/=2LL;
         printf("%lld\n", n + n + 1);
      } else {
         n = llong(sqrt(1.0 + 4.0*dist));
         n--;
         n/=2LL;
         printf("%lld\n", n + n);           
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
