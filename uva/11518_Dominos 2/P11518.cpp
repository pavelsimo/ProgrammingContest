/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11518  C++  "DFS" */
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

const int maxn=10002;
vector<int> G[maxn];
int vis[maxn];

void dfs(int cur) {
   if(vis[cur]) return;
	vis[cur]=1;
	for(int i = 0; i < G[cur].size(); ++i) {
		if(!vis[G[cur][i]])
			dfs(G[cur][i]);
	}
}

int main(int argc, char *argv[]) {
	int TC, ans, n, m, l,u,v;
	scanf("%d",&TC);
	while(TC-- > 0) {
      for(int i = 0; i < maxn; ++i) G[i].clear();
		memset(vis,0,sizeof(vis));
		scanf("%d%d%d",&n,&m,&l);
		for(int i = 0; i < m; ++i) {
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
		}
		ans=0;		
		for(int i = 0; i < l; ++i) {
			scanf("%d",&u);
			dfs(u);
		}
		for(int i = 1; i <= n; ++i) 
		    if(vis[i]) ans++;
		printf("%d\n",ans);
	}
	return 0; 
}
/* @END_OF_SOURCE_CODE */

