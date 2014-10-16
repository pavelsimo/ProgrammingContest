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
vector<int> adj[maxn], st;
int C[maxn], D[maxn];
int N, S;

void bfs(int src) {
	memset(D,INF,sizeof(int)*(N+2));
	int ans = 0;
	queue<int> Q;
	Q.push(src);
	D[src] = 0;
	while(!Q.empty()) {
		int cur = Q.front(); Q.pop();
		for(int i = 0; i < adj[cur].size(); ++i) {
			int nxt = adj[cur][i];
			if(D[nxt]==INF) {
				D[nxt] = D[cur] + 1;
				Q.push(nxt);
			}
		}
	}
}

int main(int argc, char *argv[]) {	
	int TC, cur, prev, ans, best;
	scanf("%d",&TC);
	while(TC-- > 0) {
		scanf("%d%d",&N,&S);
		for(int i = 0; i <= N; ++i) adj[i].clear();
      memset(C,0,sizeof(int)*(N+2));
		st.clear();
		for(int i = 0; i < S; ++i) {
			prev=0;
			while(scanf("%d",&cur)==1) {
				if(cur==0) break;
				C[cur]++;
				if(prev==0) {
					prev = cur;
					continue;
				}
				adj[prev].push_back(cur);
				adj[cur].push_back(prev);
				prev = cur;
			}
		}
		for(int i = 1; i <= N; ++i)
			if(C[i]>1) st.push_back(i);
		best = 100000000;
		ans = 1;
		for(int i = 0; i < st.size(); ++i) {
			bfs(st[i]);
			int cost=0;
			for(int j = 0; j < st.size(); ++j) 
				cost+=D[st[j]];
			if(cost < best) {
				ans = st[i];
				best = cost;
			}
		}		
		printf("Krochanska is in: %d\n",ans);
	}
}
/* @END_OF_SOURCE_CODE */



