/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  336  C++  "Graph Theory, BFS" */
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)

typedef pair<int,int> node;
const int maxn=50;
int vis[maxn];
vector<int> adj[maxn];
map<int, int> id;

void bfs(int src, int tle) {
	queue<node> Q;
	Q.push(make_pair(src,tle));
	vis[src]=1;
	while(!Q.empty()) {
		node cur = Q.front(); Q.pop();
		int v = cur.first;
		int stle = cur.second;
		if(stle==0) continue;
		for(int i=0; i < adj[v].size(); ++i) {
			int u = adj[v][i];
			if(!vis[u]) {
				vis[u]=1;
				Q.push(make_pair(u,stle-1));
			}
		}
	}
}

int main(int argc, char *argv[]) {
	int n, m, v, u, tle, src, cnt, tc=0;
	while(scanf("%d",&n)==1) {
		if(n==0)break;
		for(int i=0; i < maxn; ++i) adj[i].clear();
		id.clear();
		m=0;
		for(int i=0; i < n; ++i) {
			scanf("%d%d",&v,&u);
			if(id.count(v)==0)id[v]=m++;
			if(id.count(u)==0)id[u]=m++;
			adj[id[v]].push_back(id[u]);
			adj[id[u]].push_back(id[v]);
		}		
		while(scanf("%d%d",&v,&tle)==2) {
			if(v==0&&tle==0)break;
			memset(vis,0,sizeof(vis));
			src=id[v];
			bfs(src,tle);
			cnt=0;
			for(int i = 0; i < m; ++i) 
				if(!vis[i]) cnt++;
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",++tc,cnt,v,tle);
		}
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

