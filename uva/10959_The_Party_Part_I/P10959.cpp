/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10959  C++  "Graph Theory, BFS" */
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
const int maxn = 1002;
vector<int> adj[maxn];
int D[maxn];
char buf[128];

int bfs(int src) {
	queue<int> Q;
	Q.push(src);
	D[src] = 0;
	while(!Q.empty()) {
		int cur = Q.front(); Q.pop();
		for(int i = 0; i < adj[cur].size(); ++i) {
			int nxt = adj[cur][i];
			if(D[nxt]==-1) {
				D[nxt] = D[cur]+1;
				Q.push(nxt);
			}
		}
	}
	return -1;
}

int main(int argc, char *argv[]) {
	int TC, n, m, v, u;
	scanf("%d",&TC);
	for(int tc=0; tc<TC; ++tc) { 
		if(tc>0) putchar('\n');
		scanf("%d%d",&n,&m);
		for(int i = 0; i <= n; ++i) adj[i].clear();
		memset(D,-1,sizeof(D));
		for(int i = 0; i < m; ++i) {
			scanf("%d%d",&v,&u);
			adj[v].push_back(u);
			adj[u].push_back(v);
		}
		bfs(0);
		for(int i = 1; i < n; ++i)
			printf("%d\n",D[i]);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

