/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  473 C++  "DP" */
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
const int maxm = 100;
const int maxt = 100;
const int INF = 10000000;
int memo[maxn][maxm][maxt];
int N, M, T;

int d(int n, int m, int t) {
	
	
	if(memo[n][m][t] >= 0) return memo[n][m][t];
	
	
	
}

int main(int argc, char *argv[]) {
	int TC, k, ans;
	scanf("%d",&TC);
	while(TC-- > 0) {
		memset(memo,-1,sizeof(memo));
		scanf("%d%d",&M,&C);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

