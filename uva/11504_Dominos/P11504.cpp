/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11504  C++  "Graph Theory, DFS, SCC, Topological Sort" */
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
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

const int maxn = 100002;
vector<int> adj[maxn];
bool vis[maxn];
stack<int> L;

// topological sort
void dfs1(int cur) {
	vis[cur] = true;
	for(int i = 0; i < adj[cur].size(); ++i) {
		int nxt = adj[cur][i];
		if(!vis[nxt]) 
			dfs1(nxt);
	}
	L.push(cur);
}

void dfs2(int cur) {
	vis[cur] = true;
	for(int i = 0; i < adj[cur].size(); ++i) {
		int nxt = adj[cur][i];
		if(!vis[nxt]) 
			dfs2(nxt);
	}
}

int main(int argc, char *argv[]) {
	int TC, N, M, u, v, ans;
	scanf("%d",&TC);
	while(TC-- > 0) {
		scanf("%d%d",&N,&M);
		for(int i = 0; i <= N; ++i)
			adj[i].clear();
		for(int i = 0; i < M; ++i) {
			scanf("%d%d",&u,&v);
			adj[u].push_back(v);
		}
		memset(vis,false,sizeof(vis));
		for(int i = 1; i <= N; ++i) {
			if(!vis[i])
				dfs1(i);
		}
		ans=0;
		memset(vis,false,sizeof(vis));
		while(!L.empty()) {
			int cur = L.top(); L.pop();
			if(!vis[cur]) {
				dfs2(cur);
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0; 
}
/* @END_OF_SOURCE_CODE */

