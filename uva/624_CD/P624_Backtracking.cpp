/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  624  C++  "Backtracking, DP" */
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
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)

const int maxn = 22;
int n, ntrack, best, nbest, sum, ans[maxn], vis[maxn], t[maxn];

void dfs(int cur, int tm) {
	if(cur==ntrack) {
		if(tm > best) {
			int k = 0;
			for(int i = 0; i < ntrack; ++i)
				if(vis[i]) ans[k++] = t[i];
			best = tm;
			nbest = k;
		}
		return;
	}
	if(tm+t[cur] <= n) {
		vis[cur] = 1;
		dfs(cur+1,tm+t[cur]);
	}
	vis[cur] = 0;
	dfs(cur+1,tm);
}

int main() {
	while(scanf("%d%d",&n,&ntrack)==2) {
		memset(vis,0,sizeof(vis));
		for(int i = 0; i < ntrack; ++i) 
			scanf("%d",t+i);
		best = 0;
		nbest = 0;
		sum=0;
		dfs(0,0);
		for(int i = 0; i < nbest; ++i) {
			sum+=ans[i];
			printf("%d ", ans[i]);
		}
		printf("sum:%d\n",sum);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
