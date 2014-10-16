/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ MISERMAN C++ "Simple DP" */
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

const int INF = 10000000;
const int MAXN = 102;
int N, M, a[MAXN][MAXN];
int memo[MAXN][MAXN];

int doit(int i, int j) {
   if(j >= M || j < 0) return INF;
   if(i >= N) return 0;
   if(memo[i][j] >= 0) return memo[i][j];
   return memo[i][j] = a[i][j] + min(doit(i+1,j-1),min(doit(i+1,j),doit(i+1,j+1)));
}

int main(int argc, char *argv[]) {
   int res;
   while(scanf("%d%d",&N,&M)==2) {
      for(int i = 0; i < N; ++i) {
         for(int j = 0; j < M; ++j)
            scanf("%d",&a[i][j]);
      }
      res = INF;
      for(int j = 0; j < M; ++j) {
         memset(memo,-1,sizeof(memo));
         res = min(res,doit(0,j));
      }
      printf("%d\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
