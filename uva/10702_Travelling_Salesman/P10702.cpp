/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10702  C++  "DP, Graph Theory" */
#include <iostream>
#include <cstring> 
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;
ll memo[1010][110];
int F[110]; // set of final states
int adj[110][110];
int ncities, src, ndst, nvisit;
ll INF = 100000000000LL;

ll profit(int cur, int v) {
	if(cur==0) return F[v] ? 0LL: -INF;
	if(memo[cur][v] >= 0LL) return memo[cur][v];
	ll ans = 0LL;
	for(int u = 1; u <= ncities; ++u) {
		if(v==u) continue;
		ans = max(ans,profit(cur-1,u)+adj[v][u]);
	}
	return memo[cur][v] = ans;
}

int main(int argc, char *argv[]) {
	int tc=0,k;
	while(scanf("%d%d%d%d",&ncities,&src,&ndst,&nvisit)==4) {
		if(ncities==0 && src==0 && ndst == 0 && nvisit==0) break;
		memset(F,0,sizeof(F));
		memset(memo,-1,sizeof(memo));
		for(int i = 1; i <= ncities; ++i) {
			for(int j = 1; j <= ncities; ++j)
				scanf("%d",&adj[i][j]);
		}
		for(int i = 0; i < ndst; ++i) {
			scanf("%d",&k);
			F[k]=1;
		}
		printf("%lld\n",profit(nvisit,src));
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

