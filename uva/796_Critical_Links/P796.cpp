/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  796  C++  "Graph Theory, DFS, Bridge" */
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
typedef vector<int> VI;
typedef vector<VI> VII;
typedef vector<ii> VPII;

int N, M, id;
VII adj;
VI num, low, prev;
VPII edges;

// Bridges
void dfs(int cur) {
	num[cur]=low[cur]=++id;
	for(int i = 0; i < adj[cur].size(); ++i) {
		int nxt = adj[cur][i];
		if(!num[nxt]) {
			prev[nxt] = cur;
			dfs(nxt);
			if(low[nxt] > num[cur]) 
				edges.push_back(ii(min(cur,nxt),max(cur,nxt)));
			low[cur] = min(low[cur],low[nxt]);
		} else {
			if(prev[cur]!=nxt)
				low[cur] = min(low[cur],num[nxt]);
		}
	}
}

int main(int argc, char *argv[]) {
	string buf, token;
	int u, v;
	while(getline(cin,buf)) {
		if(1!=sscanf(buf.c_str(),"%d",&N)) continue;
		adj = VII(N+1);
		low = VI(N+1);
		num = VI(N+1);
		prev = VI(N+1);
		edges.clear();
		for(int i = 0; i < N; ++i) {
			getline(cin,buf);
			istringstream in(buf);
			in >> token;
			sscanf(token.c_str(),"%d",&u);
			in >> token;
			sscanf(token.c_str(),"(%d)",&M);
			for(int j = 0; j < M; ++j) {
				in >> token;
				sscanf(token.c_str(),"%d",&v);
				if(v < N) {
					adj[u].push_back(v);
					adj[v].push_back(u);
				}				
			}
		}
		id=0;
		for(int i = 0; i < N; ++i)
			if(!num[i])
				dfs(i);
		sort(edges.begin(),edges.end());
		printf("%d critical links\n",edges.size());
		for(int i = 0; i < edges.size(); ++i)
			printf("%d - %d\n",edges[i].first,edges[i].second);
		putchar('\n');
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

