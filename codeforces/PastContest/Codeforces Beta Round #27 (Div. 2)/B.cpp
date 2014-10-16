#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int n;
bool seen[52], adj[52][52], g[52][52];

bool dfs(int cur, int dst) {
	if(cur == dst) 
		return true;
	if(!seen[cur]) {
		seen[cur] = true;
		for(int nxt = 0; nxt < n; ++nxt) {
			if(adj[cur][nxt] && dfs(nxt, dst))
				return true;
		}
	}
	return false;
}

int main(int argc, char *argv[]) {
   memset(adj, false, sizeof(adj));
   memset(g, false, sizeof(g));
   int m, u, v;
   scanf("%d",&n);
   m = (n * (n-1)) / 2 - 1;
   for(int i = 0; i < m; ++i) {
	   cin >> u >> v;
	   --u; --v;
	   adj[u][v] = true;
	   g[u][v] = g[v][u] = true;
   }
   for(int i = 0; i < n; ++i) {
	   for(int j = 0; j < n; ++j) {   
		    if(i == j) continue;
			if(!g[i][j]) {
				memset(seen, false, sizeof(seen));
				if(dfs(i, j))
					printf("%d %d\n",i+1,j+1);
				else
					printf("%d %d\n",j+1,i+1);
				return 0;
			}
	   }
   }
   return 0;
}

