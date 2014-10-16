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
	int TC=0, N;
	long long x, res, a[20];
	while ( scanf("%d",&N) == 1 ) {
		TC++;
		res = 0;
		for(int i = 0; i < N; ++i)
			scanf("%lld",&a[i]);
		for(int i = 0; i < N; ++i) {
			for(int j = i; j < N; ++j) {
				x = 1;
				for(int k = i; k <= j; ++k)
					x*=a[k];
				if ( x > res ) 
					res = x;
			}
		}
		printf("Case #%d: The maximum product is %lld.\n\n",TC,res);
	}
	return 0;
}
