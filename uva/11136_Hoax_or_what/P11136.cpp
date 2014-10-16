/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11136  C++  "Ad Hoc, Set" */
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
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define pb push_back

typedef long long llong;

int N, M;
multiset<int> L;
multiset<int>::iterator it;

int main(int argc, char *argv[]) {
   int x, lb, ub; 
   llong ans;
   while(1==scanf("%d",&N)) {
      if(N==0)break;
      ans=0LL;
      L.clear();
      for(int i = 0; i < N; ++i) {
         scanf("%d",&M);
         for(int j = 0; j < M; ++j) {
            scanf("%d",&x);  
            L.insert(x);
         }
         it = L.begin(); lb = *it; L.erase(it);
         it = L.end(); --it; ub = *it; L.erase(it);
         ans += ub-lb;
      }
      printf("%lld\n",ans);
   }
	return 0;
}
/* @END_OF_SOURCE_CODE */

