/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  627  C++  "Graph Theory, BFS" */
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
const int maxn = 310;
vector<int> adj[maxn];
bool vis[maxn];
int parent[maxn];
stack<int> path;

bool bfs(int src, int dst) {
	queue<int> Q;
	Q.push(src);
	vis[src]=true;
	while(!Q.empty()) {
		int cur = Q.front(); Q.pop();
		if(cur==dst) return true;
		for(int i = 0; i < adj[cur].size(); ++i) {
			int u = adj[cur][i];
			if(!vis[u]) {
				vis[u]=true;
				parent[u]=cur;
				Q.push(u);
			}
		}
	}
	return false;
}

int main(int argc, char *argv[]) {
	int n, q, v, u;
	string buf, node, routers, token;
	while(getline(cin,buf)) {
		for(int i = 0; i < maxn; ++i) 
			adj[i].clear();
		istringstream(buf) >> n;
		for(int i = 0; i < n; ++i) {
			getline(cin,buf);
			istringstream ncin(buf);
			getline(ncin,node,'-');
			getline(ncin,routers,'-');
			istringstream ncin2(routers);
			istringstream(node) >> v;
			
			while(getline(ncin2,token,',')) {
				istringstream(token) >> u;			
				adj[v].push_back(u);
			}
		}
		getline(cin,buf);
		istringstream(buf) >> q;
		puts("-----");
		for(int i = 0; i < q; ++i) {
			memset(vis,false,sizeof(vis));
			memset(parent,0,sizeof(parent));
			getline(cin,buf);
			istringstream ncin(buf);
			getline(ncin,token,' ');
			istringstream(token) >> v;
			getline(ncin,token,' ');
			istringstream(token) >> u;
			if(bfs(v,u)) {
				for(int k = u; k != v; k=parent[k]) 
					path.push(k);
				printf("%d",v);
				for(int k = 0; !path.empty(); ++k) {
					putchar(' ');
					printf("%d",path.top());
					path.pop();
				}
				putchar('\n');
			} else { 
				puts("connection impossible");
			}
		}
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

