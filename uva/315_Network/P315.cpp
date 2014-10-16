/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  315  C++  "Graph Theory, DFS, Articulation Point */
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

typedef vector<int> VI;

int N;
const int maxn = 102;
bool AP[maxn];
VI adj[maxn];
int root, rootChild, id, num[maxn], low[maxn], P[maxn];

// Articulation Points
int dfs(int cur) {
	num[cur]=low[cur]=++id;
	for(int i = 0; i < adj[cur].size(); ++i) {
		int nxt = adj[cur][i];
		if(!num[nxt]) {
			P[nxt] = cur;
			if(cur==root) 
				rootChild++;
			dfs(nxt);
			if(low[nxt] >= num[cur]) 
				AP[cur] = true;
			low[cur] = min(low[cur],low[nxt]);
		} else {
			if(P[cur] != nxt) 
				low[cur] = min(low[cur],num[nxt]);
		}	
	}
}

int main(int argc, char *argv[]) {
	string buf;
	int ans, u, v;
	while(getline(cin,buf)) {
		if(1!=sscanf(buf.c_str(),"%d",&N) || N==0) break;
		memset(num,0,sizeof(num));
		memset(low,0,sizeof(low));
		memset(P,0,sizeof(P));
		memset(AP,false,sizeof(AP));
		for(int i = 1; i <= N; ++i)
			adj[i].clear();
		while(getline(cin,buf)) {
			if(buf[0]=='0') break;
			istringstream in(buf);
			in >> u;
			while(in >> v) {
				adj[u].push_back(v);
				adj[v].push_back(u);
			}
		}
		ans=id=0;
		for(int i = 1; i <= N; ++i) {
			if(!num[i]) {
				rootChild = 0;
				root = i;
				dfs(root);
				AP[root] = (rootChild>1);
			}
		}
		for(int i = 1; i <= N; ++i)
			if(AP[i]) ans++;
		printf("%d\n",ans);
	}
	return 0; 
}
/* @END_OF_SOURCE_CODE */

