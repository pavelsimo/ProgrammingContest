/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11792  C++  "Graph Theory, BFS" */
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
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)

const int maxn=10010, INF=-1;
set<int> adj[maxn], st;
int C[maxn], D[maxn];
int n, s;

int bfs(int src, int k) {
	memset(D,INF,(n+2)*sizeof(int));
	int ans = 0;
	queue<int> Q;
	Q.push(src);
	D[src] = 0;
	while(!Q.empty()) {
		int cur = Q.front(); Q.pop();
		if(k<=0) break;
		if(st.count(cur)>0) {
			k--;
			ans+=D[cur];
		}
		FORE(adj[cur],it) {
			int nxt = *it;
			if(D[nxt]==INF) {
				D[nxt] = D[cur] + 1;
				Q.push(nxt);
			}
		}
	}
	return ans;
}

int main(int argc, char *argv[]) {	
	int TC, cur, prev, ans, best;
	scanf("%d",&TC);
	while(TC-- > 0) {
		scanf("%d%d",&n,&s);
		for(int i = 0; i < maxn; ++i) adj[i].clear();
		memset(C,0,(n+2)*sizeof(int));
		st.clear();
		for(int i = 0; i < s; ++i) {
			prev=0;
			while(scanf("%d",&cur)==1) {
				if(cur==0) break;
				C[cur]++;
				if(C[cur]>1) st.insert(cur);
				if(prev==0) {
					prev = cur;
					continue;
				}
				adj[prev].insert(cur);
				adj[cur].insert(prev);
				prev = cur;
			}
		}
		best = 100000000;
		ans = 1;
		FORE(st,it) {	
			int cost = bfs(*it,st.size());
			if(cost < best) {
				ans = *it;
				best = cost;
			}
		}		
		printf("Krochanska is in: %d\n",ans);
	}
}
/* @END_OF_SOURCE_CODE */



