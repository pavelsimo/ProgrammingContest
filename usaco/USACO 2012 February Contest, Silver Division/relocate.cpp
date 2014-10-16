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

typedef pair<int,int> PII;
typedef vector<PII> VPII;

const int MAXM = 50010;
const int MAXN = 10010;
const int INF = 0x3f3f3f3f;
int market[MAXN];
int start, N, M, K;
int memo[MAXN][MAXM];
VPII adj[MAXN];
bool seen[MAXN];

int rec(int cur, int mask, int cnt) {
   if(mask == (1<<K)-1)
      return cur == start ? 0: INF;
   if(memo[cur][cnt] >= 0) 
      return memo[cur][cnt];
   int res = INF;
   for(int i = 0; i < sz(adj[cur]); ++i) {
      int nxt = adj[cur][i].first;
      int d = adj[cur][i].second;
      if(market[nxt] == -1) {
         res = min(res, rec(nxt, mask, cnt + 1) + d);  
      } else {
         res = min(res, rec(nxt, mask | (1<<market[nxt]), cnt) + d);
      }
   }
   return memo[cur][cnt] = res;
}

int main() {
    //freopen("relocate.in", "r", stdin);
    //freopen("relocate.out", "w", stdout);
    int u, v, cost;
    memset(market,-1,sizeof(market));
    scanf("%d%d%d",&N,&M,&K);
    for(int i = 0; i < K; ++i) {
       scanf("%d",&u);
       --u;
       market[u] = i;
    }
    
    for(int i = 0; i < M; ++i) {
       scanf("%d%d%d",&u,&v,&cost);
       --u; --v;
       //printf("%d - %d - %d\n",u,v,cost);
       adj[u].push_back(make_pair(v,cost));
       adj[v].push_back(make_pair(u,cost));
    }
    int res = INF;
    for(int i = 0; i < N; ++i) {
       if(market[i] == -1) {
          memset(seen,false,sizeof(seen));
          memset(memo,-1,sizeof(memo));
          start = i;
          res = min(res, rec(i, 0, 0));
       }
    }
    printf("%d\n",res);
    return 0;
}
