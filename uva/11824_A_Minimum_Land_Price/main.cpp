/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11824  C++  "Math, Sorting" */
#include <iostream>
#include <cstring> 
#include <algorithm>
#include <functional>
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
#include <list>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

#define BUDGET 2500000
typedef long long ll;
ll L[40];

int main(int argc, char *argv[]) {
	int TC, ok, N;
	ll x, cost;
	scanf("%d",&TC);
	while(TC-- > 0) {
		cost = 0LL;
		ok = 1;
		N = 0;
		while(scanf("%lld",L+N)==1) {
			if(L[N]==0LL)break;
			N++;
		}
		sort(L,L+N,greater<int>());
		for(int i = 0; i < N; ++i) {
			ll t = 1LL;
			for(int j = 0; j <= i && t <= BUDGET; ++j)
				t *= L[i];		
			cost += t;
			if(cost > BUDGET) break;
		}
		if(cost > BUDGET) 
			puts("Too expensive\n");
		else
			printf("%lld\n",cost*2LL);
	}	
	return 0;
}
/* @END_OF_SOURCE_CODE */

