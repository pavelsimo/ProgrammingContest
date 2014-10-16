/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  291  C++  "Graph Theory, DFS, Backtracking" */
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

int path[10];
int vis[6][6];
vector<int> adj[6];
int maxn = 9;

void dfs(int cur, int v) {
	if(cur==maxn) {
		for(int i = 0; i < 9; ++i)
			printf("%d",path[i]);
		putchar('\n');
	} else {
		for(int i = 0; i < adj[v].size(); ++i) {
			int u = adj[v][i];
			if(!vis[v][u] && !vis[u][v]) {
				vis[v][u] = 1;
				vis[u][v] = 1;
				path[cur] = u;
				dfs(cur+1,u);
				vis[v][u] = 0;
				vis[u][v] = 0;
			}
		}
	}
}

int main(int argc, char *argv[]) {
	
	memset(vis,0,sizeof(vis));
	
	// graph
	adj[1].push_back(2);
	adj[1].push_back(3);
	adj[1].push_back(5);
	
	adj[2].push_back(1);
	adj[2].push_back(3);
	adj[2].push_back(5);	

	adj[3].push_back(1);
	adj[3].push_back(2);
	adj[3].push_back(4);	
	adj[3].push_back(5);	
	
	adj[4].push_back(3);	
	adj[4].push_back(5);	
	
	adj[5].push_back(1);	
	adj[5].push_back(2);	
	adj[5].push_back(3);	
	adj[5].push_back(4);	
	
	path[0] = 1;
	
	dfs(1,1);
	
	return 0;
}
/* @END_OF_SOURCE_CODE */

