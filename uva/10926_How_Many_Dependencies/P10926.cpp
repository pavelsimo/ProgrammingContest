/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10926  C++  "DFS" */
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
#include <list>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)

const int maxn = 101;
vector<int> adj[maxn];
int vis[maxn];
int memo[maxn];
int n;

int dfs(int cur) {
	int ans = 0;
	if(memo[cur]>=0) return memo[cur];
	for(int i = 0; i < adj[cur].size(); ++i) {
		int u = adj[cur][i];
		if(!vis[u]) {
			vis[cur] = 1;
			ans = max(ans,dfs(u)+1);
			vis[cur] = 0;
		}
	}
	return memo[cur]=ans;
}

int main(int argc, char *argv[]) {
	int best, ans, nedge, u, v;
	while(scanf("%d",&n)==1) {
      if(n==0)break;
		memset(vis,0,sizeof(vis));
		for(int i = 1; i <= n; ++i) adj[i].clear();
		for(v = 1; v <= n; ++v) {
			scanf("%d",&nedge);
			while(nedge-- > 0) {
				scanf("%d",&u);
				adj[v].push_back(u);
			}
		}
		ans=1;
		best=0;
		for(int i = 1 ; i <= n; ++i) {
			memset(memo,-1,sizeof(memo));
			int cnt = dfs(i);
			if(cnt > best) {
				best = cnt;
				ans = i;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

