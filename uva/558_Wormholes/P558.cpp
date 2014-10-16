/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  558  C++  "Graph Theory, Shortest Path, Bellman Ford" */
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
const int maxn = 1010;
int N, M;
vii adj[maxn];
int D[maxn];

bool bellman_ford(int src) {
	memset(D,0x3f,sizeof(D));
	D[src]=0;
	for(int i = 0; i < N-1; ++i) {
		for(int u = 0; u < N; ++u) {
			for(int j = 0; j < adj[u].size(); ++j) {
				ii nxt = adj[u][j];
				int v = nxt.first;
				int cost = nxt.second;
				if( D[u]+cost < D[v] )
					D[v] = D[u] + cost;
			}
		}
	}
	for(int u = 0; u < N; ++u) {
		for(int j = 0; j < adj[u].size(); ++j) {
			ii nxt = adj[u][j];
			int v = nxt.first;
			int cost = nxt.second;
			if( D[u]+cost < D[v] ) return false;
		}
	}
	return true;
}


int main(int argc, char *argv[]) {
	int TC, u, v, d;
	scanf("%d",&TC);
	while(TC-- > 0) {
		scanf("%d%d",&N,&M);
		for(int i = 0; i <= N; ++i)
			adj[i].clear();
		for(int i = 0; i < M; ++i) {
			scanf("%d%d%d",&u,&v,&d);
			adj[u].push_back(ii(v,d));
		}
		if(bellman_ford(0))puts("not possible");
		else puts("possible");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

