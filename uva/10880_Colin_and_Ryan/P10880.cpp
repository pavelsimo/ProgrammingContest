/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10880  C++  "Ad Hoc, Number Theory, Divisors" */
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
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

typedef long long llong;

int main(int argc, char *argv[]) {
   int TC;
   llong C, R;
   scanf("%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
      scanf("%lld%lld",&C,&R);
      printf("Case #%d:",tc);
      set<int> ans;
      llong X = C - R;
      if(X <= 0) {
	 printf(" 0");
      } else {
	 for(llong G = 1; G * G <= X; ++G) {
	    if(X % G == 0) {
	       int q1 = G;
	       int q2 = X/G;
	       if(R < q1) ans.insert(q1);
	       if(R < q2) ans.insert(q2);
	    }
	 }
	 foreach(it, ans)
	    printf(" %d",*it);
      }
      printf("\n");
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

