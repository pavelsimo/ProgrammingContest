/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  729  C++  "Bitmask, Backtracking" */
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
#define BITCOUNT(mask) ( __builtin_popcount((mask)) )
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

const int maxn = 20;
int n, h;

void doit() {
   int S = 1<<n;
	for(int m = 0; m < S; ++m) {
		if(BITCOUNT(m)==h) {
			for(int i = n-1; i >= 0; --i) {
				if((m&(1<<i))!=0) putchar('1');
				else putchar('0');
			}
			putchar('\n');
		}
	}
}

int main(int argc, char *argv[]) {
	int TC;
	scanf("%d",&TC);
	for(int tc = 0; tc < TC; ++tc) {
		if(tc!=0) putchar('\n');
		scanf("%d%d",&n,&h);
		doit();
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
