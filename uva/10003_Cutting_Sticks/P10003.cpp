/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10003  C++  "DP" */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

const int maxn = 60;
int a[maxn];
int memo[maxn][maxn];
int n;
int INF = 1000000;

int d(int l, int r) {
   if(l+1==r) return 0;
	if(memo[l][r] >= 0) return memo[l][r];
	int cost = INF;
	for(int k = l+1; k < r; ++k)
      cost = min(cost, d(l,k) + d(k,r) + (a[r]-a[l]));
	return memo[l][r] = cost;
}

int main() {
	int m;
	while(scanf("%d",&m)==1) {
		if(m==0) break;
      memset(memo,-1,sizeof(memo));    
		scanf("%d",&n);
		a[0] = 0;
		a[n+1] = m;
		for(int i = 1; i <= n; ++i) scanf("%d",&a[i]);
		printf("The minimum cutting is %d.\n",d(0,n+1));		
	}	
	return 0;
}
