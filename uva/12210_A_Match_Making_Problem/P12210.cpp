/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12210  C++  "Ad Hoc, Math" */
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

const int INF = 0x3f3f3f3f;

int main(int argc, char *argv[]) {
   int m, w, x, res;
   for(int tc = 1; 2 == scanf("%d%d",&m,&w); ++tc) {
      if(!m && !w) break;
      res = INF;
      for(int i = 0; i < m; ++i) {
         scanf("%d",&x);
         res = min(res,x);
      }
      for(int i = 0; i < w; ++i) 
         scanf("%d",&x);
      printf("Case %d: ",tc);
      if(m <= w) puts("0");
      else printf("%d %d\n",m-w,res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
