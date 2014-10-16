/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  495  C++  "Simple Math" */
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

typedef long long ll;
const int maxn = 5010;
ll DP[maxn];

int main(int argc, char *argv[]) {
	DP[0] = 0LL;
	DP[1] = 1LL;
	for(int i = 2; i < maxn; ++i)
		DP[i] += DP[i-1]+DP[i-2];
	int n;
	while(scanf("%d",&n)==1)
		printf("The Fibonacci number for %d is %lld\n",n,DP[n]);
	return 0;
}
/* @END_OF_SOURCE_CODE */
