/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11900  C++  "DP" */
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cstring>
using namespace std;

int N, P, Q;
const int maxn = 32, INF=100000000;
int eggs[maxn];
int memo[maxn][maxn][maxn];

int doit(int cur, int weigth, int k)  {
	if(k>P) return -INF;
	if(cur>=N) return 0;
	if(memo[cur][weigth][k]>=0) return memo[cur][weigth][k];
	int ans = doit(cur+1,weigth,k);
	if(weigth >= eggs[cur])
		ans = max(ans,doit(cur+1,weigth-eggs[cur],k+1)+1);
	return memo[cur][weigth][k] = ans;
}


int main(int argc, char *argv[]) {
	int TC;
	scanf("%d",&TC);
	for(int tc=1; tc<=TC; ++tc) {
		memset(memo,-1,sizeof(memo));
		scanf("%d%d%d",&N,&P,&Q);
		for(int i = 0; i < N; ++i)
			scanf("%d",&eggs[i]);
		printf("Case %d: %d\n",tc,doit(0,Q,0));
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
