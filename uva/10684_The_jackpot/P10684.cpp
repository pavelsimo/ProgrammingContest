/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10684  C++  "DP, Maximum Consecutive Subsequence 1D" */
#include <iostream>
#include <cstring> 
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

typedef long long llong;
llong memo[10010];
llong a[10010];
int n;
const llong INF = 1000000000000000LL;

llong mcs() {
	llong best = a[0], sum=0LL;
	for(int i = 0; i < n; ++i) {
		sum+=a[i];
		if(sum > best) best = sum;
		if(sum < 0) sum = 0LL;
	}
	return best;
}

int main(int argc, char *argv[]) {	
	llong ans;
	while(scanf("%d",&n)==1) {
      if(n==0) break;
		for(int i = 0; i < n; ++i) scanf("%lld",&a[i]);
		ans = mcs();
		if(ans <= 0LL) puts("Losing streak.");
		else printf("The maximum winning streak is %lld.\n",ans);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
