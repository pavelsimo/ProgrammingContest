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
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

#define INF 1000
#define BITCOUNT(mask) ( __builtin_popcount((mask)) )


int main(int argc, char *argv[]) {
	
	int TC, n, x, rmin, rmax;
	scanf("%d\n",&TC);
	while ( TC-- > 0 ) {
		scanf("%d\n",&n);
		rmin = INF;
		rmax = -INF;
		for(int i = 0; i < n; ++i) {
			scanf("%d",&x);
			rmin = min(rmin,x);
			rmax = max(rmax,x);
		}
		printf("%d\n",((rmax-rmin)+(rmax-rmin)));
	}
	return 0;
}
