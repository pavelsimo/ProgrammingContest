/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11970  C++  "Ad Hoc, Frequency" */
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
vector<llong> psquare;
stack<llong> S;

int main(int argc, char *argv[]) {
   for(llong i = 0; i * i <= 1000000000LL; ++i)
      psquare.push_back(i * i);
   int TC;
   scanf("%d",&TC);
   llong n, x;
   for(int tc = 1; tc <= TC; ++tc) {
      scanf("%lld",&n);
      for(int i = 1; i < sz(psquare); ++i) {
         x = n - psquare[i];
         if(x <= 0) break;
         if(x % i == 0) S.push(x);
      }
      printf("Case %d: ",tc);
      for(int i = 0; !S.empty(); ++i) {
         if(i > 0) putchar(' ');
         printf("%lld",S.top());
         S.pop();
      }
      putchar('\n');
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
