/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10019  C++  "Ad Hoc" */
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
#include <utility>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)
#define BITCOUNT(mask) ( __builtin_popcount((mask)) )
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

int main(int argc, char *argv[]) {
	int TC, n, x, hex;
	scanf("%d",&TC);
	while(TC-- > 0) {
		scanf("%d",&n);
		x = n;
		hex=0;
		while(x>0) {
			int d=x%10;
			hex+=BITCOUNT(d);
			x/=10;
		}
		printf("%d %d\n",BITCOUNT(n),hex);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
