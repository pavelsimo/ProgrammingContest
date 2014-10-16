/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11709  C++  "Graph Theory, DFS, SCC, Topological Sort" */
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
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

typedef vector<int> vi;
const int maxn = 1002;
vi adj[maxn], adjT[maxn];
bool vis[maxn];
map<string,int> id;
stack<int> L;

void dfs1(int cur) {
	vis[cur] = true;
	for(int i = 0; i < adj[cur].size(); ++i) {
		int nxt = adj[cur][i];
		if(!vis[nxt])
			dfs1(nxt);
	}
	L.push(cur);
}

void dfs2(int cur) {
	vis[cur] = true;
	for(int i = 0; i < adjT[cur].size(); ++i) {
		int nxt = adjT[cur][i];
		if(!vis[nxt])
			dfs2(nxt);
	}
}

int main(int argc, char *argv[]) {
	int N, M, u, v, ans;
	string buf;
	while(getline(cin,buf)) {
		sscanf(buf.c_str(),"%d%d",&N,&M);
		if(N==0&&M==0)break;
		id.clear();
		for(int i = 0; i <= N; ++i) {
			adj[i].clear();
			adjT[i].clear();
		}
		for(int i = 0; i < N; ++i) {
			getline(cin,buf);
			id[buf] = i;
		}
		for(int j = 0; j < M; ++j) {
			getline(cin,buf);
			u = id[buf];
			getline(cin,buf);
			v = id[buf];
			adj[u].push_back(v);
			adjT[v].push_back(u);
		}
		memset(vis,false,sizeof(vis));
		for(int i = 0; i < N; ++i) {
			if(!vis[i]) 
				dfs1(i);
		}		
		memset(vis,false,sizeof(vis));
		ans = 0;
		while(!L.empty()) {
			int u = L.top(); L.pop();
			if(!vis[u]) {
				ans++;
				dfs2(u);
			}
		}
		printf("%d\n",ans);
	}
	return 0; 
}
/* @END_OF_SOURCE_CODE */

