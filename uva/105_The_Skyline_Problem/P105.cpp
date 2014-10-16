/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  105 C++  "Ad Hoc" */
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

const int maxn = 10010;
int a[maxn];

int main(int argc, char *argv[]) {
	int n=0, l, h, r, src=maxn;
	memset(a, 0, sizeof(a));
	while(scanf("%d%d%d",&l,&h,&r)==3) {
		for(int i = l; i < r; ++i)
			a[i] = max(a[i], h);
		n = max(n,r);
		src = min(src,l);
	}
	int prev = src;
	printf("%d",src);
	for(int i = src; i <= n; ++i) {
		if(a[prev]!=a[i])
			printf(" %d %d",a[prev],i);
		prev = i;
	}
	printf(" 0\n");
	return 0;
}
/* @END_OF_SOURCE_CODE */

