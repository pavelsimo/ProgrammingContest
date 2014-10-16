/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  193 C++  "Backtracking" */
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
#include <bitset>
#include <utility>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

#define WHITE 0
#define BLACK 1
const int maxn = 102;
vector<int> adj[maxn];
int n, ans, color[maxn], sol[maxn];

bool valid(int v, int c) {
	for(int u = 0; u < adj[v].size(); ++u)
		if(color[adj[v][u]]==c) return false;
	return true;
}

void dfs(int cur, int k) {	
	if(cur>n+1) return;
	if(k > ans) {
		ans=k;
		for(int i=1,j=0; i<=n; ++i)
			if(color[i]==BLACK) sol[j++]=i;
	}
	if(valid(cur,BLACK)) {
		color[cur]=BLACK;
		dfs(cur+1,k+1);
		color[cur]=WHITE;
	}
	dfs(cur+1,k);
}

int main(int argc, char *argv[]) {
	int TC, k, v, u;
	scanf("%d",&TC);
	while(TC-- > 0) {
		scanf("%d%d",&n,&k);
		for(int i = 1; i <= n; ++i) adj[i].clear();
		memset(color,WHITE,sizeof(color));
		memset(sol,0,sizeof(sol));
		while(k-- > 0) {
			scanf("%d%d",&v,&u);
			adj[v].push_back(u);
			adj[u].push_back(v);
		}
		ans=0;
		dfs(1,0);
		printf("%d\n",ans);
		for(int i = 0; i < ans; ++i) {
			if(i>0)putchar(' ');
			printf("%d",sol[i]);
		}
		putchar('\n');
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

