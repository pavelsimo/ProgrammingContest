/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  567  C++  "Graph Theory, BFS" */
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
const int maxn=25;
vector<int> adj[maxn];
bool vis[maxn];

int bfs(int src, int dst) {
	queue<node> Q;
	Q.push(make_pair(src,0));
	vis[src]=true;
	while(!Q.empty()) {
		node cur = Q.front(); Q.pop();
		int v = cur.first;
		int d = cur.second;
		if(v==dst) return d;
		for(int i = 0; i < adj[v].size(); ++i) {
			int u = adj[v][i];
			if(!vis[u]) {
				vis[u]=true;
				Q.push(make_pair(u,d+1));
			}
		}
	}
	return -1;
}

int main(int argc, char *argv[]) {
	int n=19, tc=0, stop=0, m, v, u, q, ans;
	while(1) {
		for(int i=0; i < maxn; ++i) adj[i].clear();
		for(v = 1; v <= n; ++v) {
			if(scanf("%d",&m)!=1) {
				stop=1;
				break;
			}
			for(int j =0; j < m; ++j) {
				scanf("%d",&u);
				adj[v].push_back(u);
				adj[u].push_back(v);
			}
		}
		if(stop) break;
		scanf("%d",&q);
		printf("Test Set #%d\n",++tc);
		for(int i = 0; i < q; ++i) {
			scanf("%d%d",&v,&u);
			memset(vis,false,sizeof(vis));
			ans=bfs(v,u);
			printf("%2d to %2d:%2d\n",v,u,ans);
		}
		putchar('\n');
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

