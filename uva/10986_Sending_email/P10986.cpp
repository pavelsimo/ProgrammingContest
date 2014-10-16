/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10986  C++  "SSSP, Dijkstra" */
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

typedef long long llong;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 20010;
const int INF = 2147483630;
vii adj[maxn];
int D[maxn];

int dijkstra(int src, int dst) {
	priority_queue<ii,vector<ii>,greater<ii> > Q;
	Q.push(ii(0,src));
	D[src]=0;
	while(!Q.empty()) {
		ii cur = Q.top(); Q.pop();
		int d = cur.first;
		int v = cur.second;
		if(v==dst) return d;
		if(d <= D[v]) {
			for(int i = 0; i < adj[v].size(); ++i) {
				ii nxt = adj[v][i];
				int cost = nxt.first;
            int u = nxt.second;
				if(D[v]+cost < D[u]) {
					D[u] = D[v]+cost;
					Q.push(ii(D[u],u));
				}
			}
		}
	}
	return -1;
}

int main(int argc, char *argv[]) {
	int TC, n, m, src, dst, v, u, d, ans;
	scanf("%d",&TC);
	for(int tc=1; tc<=TC; ++tc) {
		scanf("%d%d%d%d",&n,&m,&src,&dst);
		for(int i = 0; i <= n; ++i) {
			adj[i].clear();
			D[i]=INF;
		}
		for(int i = 0; i < m; ++i) {
			scanf("%d%d%d",&v,&u,&d);
			adj[v].push_back(ii(d,u));
			adj[u].push_back(ii(d,v));
		}
		ans=dijkstra(src,dst);
		printf("Case #%d: ",tc);
		if(ans>=0) printf("%d\n",ans);
		else printf("unreachable\n");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

