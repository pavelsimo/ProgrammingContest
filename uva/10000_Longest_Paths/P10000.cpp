/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10000  C++  "Longest Path" */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <cmath>
#include <complex>
#include <stack>
#include <utility>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)
#define BITCOUNT(mask) ( __builtin_popcount((mask)) )
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

typedef vector<int> vi;

struct node {
	int cur;
	int d;
	node() {
      cur = 0;
		d = 0;
   }
	node(int _cur, int _d) {
		cur = _cur;
		d = _d;
	}
};

const int maxn = 110;
vi adj[maxn];
int vis[maxn][maxn];
node memo[maxn][maxn];
int n, s, end;

node dfs(int cur, int d) {
	node res(cur,d);
	if(vis[cur][d]) return memo[cur][d];
	vis[cur][d] = 1;
	for(int i = 0; i < adj[cur].size(); ++i) {
	   int v = adj[cur][i];
		node a = dfs(v,d+1);
		if(a.d == res.d && a.cur < res.cur)
			res = a;
		if(a.d > res.d)
			res = a;
	}
	return memo[cur][d]=res;
}

int main(int argc, char *argv[]) {
	int u, v;
	int tc=0;
	while(scanf("%d",&n)==1) {
		if(n==0) break;
		memset(vis,0,sizeof(vis));
		for(int i = 0; i <= n; ++i) adj[i].clear();
		scanf("%d",&s);
		while(scanf("%d%d",&u,&v)==2) {
			if(u==0 || v==0) break;
			adj[u].push_back(v);
		}
		node ans = dfs(s,0);
		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n",++tc,s,ans.d,ans.cur);
		putchar('\n');
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
