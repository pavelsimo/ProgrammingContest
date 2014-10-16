/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  924  C++  "Graph Theory, BFS" */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <utility>
using namespace std;

typedef pair<int,int> node;
const int maxn = 2510;
vector<int> adj[maxn];
bool vis[maxn];
int memo[maxn];
int M, D;

void bfs(int src) {
	queue<node> Q;
	Q.push(make_pair(src,1));
	vis[src]=true;
	while(!Q.empty()) {
		node cur = Q.front(); Q.pop();
		int boomsize = 0;
		int day = cur.second;
		for(int i = 0; i < adj[cur.first].size(); ++i) {
			int nxt = adj[cur.first][i];
			if(!vis[nxt]) {
				boomsize++;
				vis[nxt]=true;
				Q.push(make_pair(nxt,day+1));
			}
		}
		memo[day]+=boomsize;
	}
	for(int d = 1; d < maxn; ++d) {
		if(memo[d] > M) {
			M = memo[d];
			D = d;
		}
	}
}

int main(int argc, char *argv[]) {
	int n, nedge, v, u, q, src;
	while(scanf("%d",&n)==1) {
		for(v = 0; v < n; ++v) {
			scanf("%d",&nedge);
			while(nedge-- > 0) {
				scanf("%d",&u);
				adj[v].push_back(u);
			}
		}
		scanf("%d",&q);
		for(int i = 0; i < q; ++i) {
			memset(vis,false,sizeof(vis));
			memset(memo,0,sizeof(memo));
			M=D=0;
			scanf("%d",&src);
			bfs(src);
			if(M==0&&D==0) puts("0");
			else printf("%d %d\n",M,D);
		}
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
