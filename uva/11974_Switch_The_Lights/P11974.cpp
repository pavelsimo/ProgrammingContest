/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11974  C++  "Graph Theory, BFS, DP" */
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
const int MAXN = 102;

int N, M, S[MAXN];
int memo[102][1<<16];

int rec(int cur, int mask) {
   if(cur==M) return mask==0 ? 0: INF;
   if(memo[cur][mask] >= 0) 
      return memo[cur][mask];
   return memo[cur][mask] = min(rec(cur + 1, mask), rec(cur + 1, mask^S[cur]) + 1);
}

int main(int argc, char *argv[]) {
   int TC, mask, bit, res;
   scanf("%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
      scanf("%d%d",&N,&M);
      for(int i = 0; i < M; ++i) {
         mask = 0;
         for(int j = 0; j < N; ++j) {
             scanf("%d",&bit); 
             if(bit) mask|=(1<<j);
         }
         S[i] = mask;
      }
      printf("Case %d: ",tc);
      memset(memo,-1,sizeof(memo));
      res = rec(0,(1<<N)-1);
      if(res==INF) puts("IMPOSSIBLE");
      else printf("%d\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
