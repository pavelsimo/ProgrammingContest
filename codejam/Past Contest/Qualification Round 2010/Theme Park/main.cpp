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
#include <cstdio>
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
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int T, N;
	int a[1001][2];
	long long dp[1001][2];
	long long R, k, cost;
	scanf("%d\n",&T);
	for (int c = 1; c <= T; ++c) {
        scanf("%I64d %I64d %d\n",&R,&k,&N);
		cost = 0;
		for (int i = 0; i < N; ++i)
			 scanf("%d", a[i]);
		for (int i = 0; i < N; ++i) {
			dp[i][0] = 0;
			for (int j = 0; j < N; ++j) {
                int index = (i+j)%N;
				if ( dp[i][0]+a[index] <= k) {
					dp[i][0] += a[index];
					dp[i][1] = j + 1;
				} else
					break;
			}
		}
		int idx = 0;
		for (int i = 0; i < R; i++) {
			cost += dp[idx][0];
			idx = (idx + (int)(dp[idx][1])) % N;
		}
		printf("Case #%d: %I64d\n",c,cost);
	}
}
