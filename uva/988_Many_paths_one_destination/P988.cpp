/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  988  C++  "Graph Theory, DFS" */
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

const int maxn  = 1000;
vector<int> adj[maxn];
int vis[maxn];
int memo[maxn];

int dfs(int v) {
	if(memo[v]>=0) return memo[v];
	if(adj[v].size()==0) return 1;
	int ans = 0;
	for(int i = 0; i < adj[v].size(); ++i) {
		int u = adj[v][i];
		if(!vis[u]) {
         vis[u] = 1;                  
			ans+=dfs(u);
			vis[u] = 0;
		}
	}
	return memo[v]=ans;
}

int main(int argc, char *argv[]) {
	int n, nedge, v, u, tc=0;
	while(scanf("%d",&n)==1) {
      if(tc++>0) putchar('\n');
		memset(vis,0,sizeof(vis));
		memset(memo,-1,sizeof(memo));
		for(int i = 0; i <= n; ++i) adj[i].clear();
		for(v = 0; v < n; ++v) {
			scanf("%d",&nedge);
			while(nedge-- > 0) {
				scanf("%d",&u);
				adj[v].push_back(u);
			}
		}
		vis[0] = 1;
		printf("%d\n",max(1,dfs(0)));
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

