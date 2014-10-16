/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  590  C++  "DP, Graph Theory" */
#include <iostream>
#include <cstring> 
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

typedef long long llong;
const llong INF = 100000000000LL;
llong memo[1010][12];
llong adj[12][12][32];
int s[12][12];
int n, k, d;

llong go(int cur, int v) {
	if(cur==k) return v==n ? 0: INF;
	if(memo[cur][v]>=0) return memo[cur][v];
	llong ans = INF;
	for(int u = 1; u <= n; ++u) {
		if(v==u) continue;
		llong cost = adj[v][u][cur%s[v][u]];
		if(cost==0) continue;
		ans = min(ans,go(cur+1,u)+cost);
	}
	return memo[cur][v] = ans;
}

int main(int argc, char *argv[]) {	
	llong flight, ans;
	int tc=0;
	while(scanf("%d%d",&n,&k)==2) {
		if(n==0&&k==0)break;
		memset(memo,-1,sizeof(memo));
      memset(adj,0,sizeof(adj));
      memset(s,0,sizeof(s));
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j) {
				if(i==j) continue;
				scanf("%d",&d);
				s[i][j] = d;
				for(int k = 0; k < d; ++k) {
					scanf("%lld",&flight);
					adj[i][j][k]=flight;
				}
			}
		}
		printf("Scenario #%d\n",++tc);
		ans = go(0,1);
		if(ans==INF) puts("No flight possible.");
		else printf("The best flight costs %lld.\n",ans);
		putchar('\n');
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

