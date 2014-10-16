/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10718  C++  "Bit Mask" */
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
#define INF 100000000

bool is_set(long long x, int bit) {
	return (x&1LL<<bit)!=0;
}

int main() {
	long long n, l, u, ans;
	while (scanf("%lld %lld %lld",&n,&l,&u)==3) {
		ans = 0LL;
		for(int i=31; i >= 0; --i) {
			if ((ans+(1LL<<i)) > u ) continue;
			if ( (ans + ((1LL<<i)-1LL)) < l ) {
				ans |= (1LL<<i);
			} else {
				if ( !is_set(n,i) ) {
					long long t = ans;
					t |= (1LL<<i);
					if ( t <= u  ) 
						ans |= t;
				}
			}
		}
		printf("%lld\n",ans);
	}
}
/* @END_OF_SOURCE_CODE */
