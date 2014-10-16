/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11137  C++  "DP" */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef long long ll;
const int maxn = 21;
const int maxm = 10000;
ll w[] = {1,8,27,64,125,216,343,512,729,1000,1331,1728,2197,2744,3375,4096,4913,5832,6859,8000,9261};
ll dp[maxm+20];

void doit() {
	memset(dp,0,sizeof(dp));
	dp[0] = 1;
	for(int i = 0; i < maxn; ++i) {
		for(int j = 0; j <= maxm; ++j) {
			if(j >= w[i])
				dp[j]+=dp[j-w[i]];
		}
	}
}

int main() {
	doit();
	int n;
	while(scanf("%d",&n)==1) {
		printf("%lld\n",dp[n]);
	}
	return 0;
}
