/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10954  C++  "Greedy, Priority Queue" */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <cmath>
#include <complex>
#include <stack>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

int main(int argc, char *argv[]) {
	int N, x, ans;
	priority_queue<int,vector<int>,greater<int> > Q;
	while(scanf("%d",&N)==1) {
		if(N==0) break;
		for(int i = 0; i < N; ++i) {
			scanf("%d",&x);
			Q.push(x);
		}
		ans = 0;
		while(!Q.empty()) {
			if(Q.size() > 1) {
				int a = Q.top(); Q.pop();
				int b = Q.top(); Q.pop();
				ans+=(a+b);
				Q.push(a+b);
			} else {
				Q.pop();
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
