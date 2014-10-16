/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11825  C++  "DP bitmask" */
#include <iostream>
#include <cstring> 
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#define BITCOUNT(mask) ( __builtin_popcount((mask)) )
using namespace std;

const int maxn = 16;
int memo[1<<maxn];
vector<int> adj[maxn];
int n;
int C[maxn];

int go(int v, int mask) {
	if(memo[mask]>=0) return memo[mask];
	int ans = BITCOUNT(mask);
	C[v]++;
	for(int i = 0; i < adj[v].size(); ++i) {
		int u = adj[v][i];
		if((mask&(1<<u))) continue;
      // DEBUG
      //printf("from=%d to to=%d\n",v,u);
		ans = max(ans,go(u,mask|(1<<u)));
	}
	return memo[mask] = ans;
}

int main(int argc, char *argv[]) {
	int ans,m,u,tc=0;
	while(scanf("%d",&n)==1) {
		if(n==0) break;
		memset(C,0,sizeof(C));
		for(int i = 0; i < maxn; ++i) adj[i].clear();
		for(int v = 0; v < n; ++v) {
			scanf("%d",&m);
			while(m-- > 0) {
				scanf("%d",&u);
				adj[v].push_back(u);
			}
		}
		for(int i = 0; i < n; ++i) {
			memset(memo,-1,sizeof(memo));
			//DEBUG
         //printf("#%d\n",i);
			go(i,(1<<i));
		}
		ans = C[0];
		for(int i = 0; i < n; ++i) {
         ans = min(ans,C[i]);
		}
		printf("Case %d: %d\n",++tc,ans);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

