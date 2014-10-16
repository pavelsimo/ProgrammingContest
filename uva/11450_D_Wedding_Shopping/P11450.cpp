/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11450 C++  "DP" */
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

const int maxn = 300;
const int maxm = 30;
const int INF = 10000000;
int memo[maxn][maxm];
int sz[maxm];
int price[maxm][maxm];
int M, C;

int d(int budget, int cur) {
	int ans = -INF;
	if(budget < 0) return -INF;
	if(cur==C) return 0;
	if(memo[budget][cur] >= 0) return memo[budget][cur];
	for(int i = 0; i < sz[cur]; ++i)
		ans = max(ans,d(budget-price[cur][i],cur+1)+price[cur][i]);
	return memo[budget][cur] = ans;
}

int main(int argc, char *argv[]) {
	int TC, k, ans;
	scanf("%d",&TC);
	while(TC-- > 0) {
		memset(memo,-1,sizeof(memo));
		scanf("%d%d",&M,&C);
		for(int i = 0; i < C; ++i) {
			scanf("%d",&k);
			sz[i] = k;
			for(int j = 0; j < k; ++j)
				scanf("%d",&price[i][j]);
		}
		ans=d(M,0);
		if(ans<0) puts("no solution");
		else printf("%d\n",ans);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

