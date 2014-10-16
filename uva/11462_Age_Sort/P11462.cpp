/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11462  C++  "Sorting" */
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

const int maxn = 2000010;
int a[maxn];

int main(int argc, char *argv[]) {
	int n;
	int tc=0;
	while(scanf("%d",&n)==1) {
		if(n==0) break;
		for(int i = 0; i < n; ++i)
			scanf("%d",&a[i]);
		sort(a,a+n);
		for(int i = 0; i < n; ++i) {
			if(i!=0) putchar(' ');
			printf("%d",a[i]);
		}
		putchar('\n');
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
