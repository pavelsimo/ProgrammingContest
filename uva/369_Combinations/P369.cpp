/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  4217 369  C++  "Binomial Coeficients" */
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
#define DEBUG
#undef DEBUG
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }
typedef pair<int,int> ii;
typedef vector<ii> vii;

#define N 105
int pascal[N][N];

int main() {
    int n, k;
	pascal[0][0] = 1;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j)
			pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
	}
    while (scanf("%d %d", &n, &k) == 2) {
        if ( n == 0 && k == 0 ) break;
        printf("%d things taken %d at a time is %d exactly.\n",n,k,pascal[n+1][k+1]);
    }
	return 0;
}
/* @END_OF_SOURCE_CODE */
