/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11984  C++  "Ad Hoc, Simple Math" */
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


int main(int argc, char *argv[]) {
   int TC, C, d;
   double F, res;
   scanf("%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
      scanf("%d%d",&C,&d);
      F = (9/5.0)*C + 32 + d;
      res = (5/9.0)*(F - 32);
      printf("Case %d: %.2lf\n",tc,res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
