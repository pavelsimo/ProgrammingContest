/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  900 C++  "Simple Math, Fibonnaci" */
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

typedef long long ll;

const int maxn = 51;
ll a[maxn];

int main(int argc, char *argv[]) {
	a[0] = 0LL;
	a[1] = 1LL;
	a[2] = 2LL;
	for(int i = 3; i <= maxn; ++i)
		a[i] = a[i-1]+a[i-2];
	int n;
	while(scanf("%d",&n)==1) {
		if(n==0)break;
		printf("%lld\n",a[n]);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

