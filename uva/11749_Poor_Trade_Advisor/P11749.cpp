/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11749  C++  "Graph Theory, DFS" */
#include <iostream>
#include <cstring> 
#include <algorithm>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <cmath>
#include <complex>
#include <stack>
#include <bitset>
#include <utility>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)

typedef long long llong;

int N, M, cnt;
const int maxn = 520;
const llong INF = 1000000000000LL;
llong adj[maxn][maxn], best;
bool vis[maxn];

void dfs(int cur) {
	vis[cur] = true;
	cnt++;
	for(int i = 1; i <= N; ++i) {
		llong cost = adj[cur][i];
		if(cost==best && !vis[i]) dfs(i);
	}
}

int main() {
	int u, v, ans;
	llong cost;
	while(scanf("%d%d",&N,&M)==2) {
		if(N==0 && M==0) break;
		memset(vis,false,sizeof(vis));
		for(int i = 0; i <= N; ++i)
		for(int j = 0; j <= N; ++j)
			adj[i][j] = -INF;
		ans=0;
		best=-INF;
		while(M-- > 0) {
			scanf("%d%d%lld",&u,&v,&cost);
			adj[u][v] = max(adj[u][v],cost);
			adj[v][u] = max(adj[v][u],cost);
			best=max(best,cost);
		}
		for(int i = 1; i <= N; ++i) {			
			if(!vis[i]) {
				cnt = 0;
				dfs(i);
				ans = max(ans,cnt);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

