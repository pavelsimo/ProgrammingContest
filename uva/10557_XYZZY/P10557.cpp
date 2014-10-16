/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10557  C++  "Graph Theory, Shortest Path, Bellman Ford" */
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
#include <utility>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
const int maxn = 110;
int N, M;
vii adj[maxn];
int D[maxn];

int bellman_ford(int src, int dst) {
	memset(D,0x3f,sizeof(D));
	D[src] = 100;
	for(int k = 0; k < N-1; ++k) {
		for(int u = 1; u <= N; ++u) {
			for(int i = 0; i < adj[u].size(); ++i) {
				ii nxt = adj[u][i];
				int v = nxt.first;
				int cost = nxt.second;
				if(D[u]+cost < D[v])
					D[v] = D[u]+cost;
			}
		}
	}
	// DEBUG
	for(int i = 1; i <= N; ++i) printf("D[%d]=%d\n",i,D[i]);
	
	for(int u = 1; u <= N; ++u) {
		for(int i = 0; i < adj[u].size(); ++i) {
			ii nxt = adj[u][i];
			int v = nxt.first;
			int cost = nxt.second;
			if(D[u]+cost < D[v]) return -1;
		}
	}
	// implement positive cycles
	return D[dst];
}

int main(int argc, char *argv[]) {
	int u, v, d;
	while(scanf("%d",&N)==1) {
		if(N<0) break;
		for(int i = 0; i < maxn; ++i) 
			adj[i].clear();
		for(u = 1; u <= N; ++u) {
			scanf("%d%d",&d,&M);
			while(M-- > 0) {
				scanf("%d",&v);
				adj[u].push_back(ii(v,d));
			}
		}
		if(bellman_ford(1,N)>0) puts("winnable");
		else puts("hopeless");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

