/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  383  C++  "Graph Theory, BFS" */
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

typedef pair<int, int> node;

const int maxn=32;
map<string, int> id;
vector<int> adj[maxn];
bool vis[maxn];

int bfs(int src, int dst, int sz) {
	queue<node> Q;
	Q.push(make_pair(src,0));
	vis[src]=true;
	while(!Q.empty()) {
		node cur = Q.front(); Q.pop();
		int v = cur.first;
		int legs = cur.second;
		if(v==dst) return sz*legs*100;
		for(int i = 0; i < adj[v].size(); ++i) {
			int u = adj[v][i];
			if(!vis[u]) {
				vis[u]=true;
				Q.push(make_pair(u,legs+1));
			}
		}
	}
	return -1;
}

int main(int argc, char *argv[]) {
	int TC, n, m, q, sz, ans;
	string v, u;
	cin >> TC;
	printf("SHIPPING ROUTES OUTPUT\n\n");
	for(int tc=1; tc<=TC; ++tc) {
		id.clear();
		for(int i = 0; i < maxn; ++i) adj[i].clear();
		cin >> n >> m >> q;
		for(int i=0; i < n; ++i) {
			cin >> v;
			id[v]=i;
		}
		for(int i=0; i < m; ++i) {
			cin >> v >> u;
			adj[id[v]].push_back(id[u]);
			adj[id[u]].push_back(id[v]);
		}
		printf("DATA SET  %d\n\n",tc);
		for(int i=0; i < q; ++i) {
			memset(vis,false,sizeof(vis));
			cin >> sz >> v >> u;
			ans=bfs(id[v],id[u],sz);
			if(ans>=0) printf("$%d\n",ans);
			else puts("NO SHIPMENT POSSIBLE");
		}
		putchar('\n');
	}
	printf("END OF OUTPUT\n");
	return 0;
}
/* @END_OF_SOURCE_CODE */

