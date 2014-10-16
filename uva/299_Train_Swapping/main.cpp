/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  299  C++  "Sorting" */
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
#include <list>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

#define L 52
int a[L];

void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}

int main(int argc, char *argv[]) {
	int TC, n, ans;
	scanf("%d",&TC);
	while(TC-- > 0) {
		scanf("%d",&n);
		REP(i,n)
			scanf("%d",&a[i]);
		ans=0;
		REP(i,n) {
			REP(j,n-1) {
				if ( a[j] > a[j+1] ) {
					swap(a[j],a[j+1]);
					ans++;
				}
			}
		}
		printf("Optimal train swapping takes %d swaps.\n",ans);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
