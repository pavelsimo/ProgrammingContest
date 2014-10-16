/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10935  C++  "Queue" */
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

int main(int argc, char *argv[]) {
	int n;
	deque<int> a;
	while ( scanf("%d",&n) == 1 ) {
		if ( n == 0 ) break;
		for(int i = 1; i <= n; ++i)
			a.push_back(i);
		printf("Discarded cards:");
		for(int i = 0; a.size() > 1; ++i) {
			if(i != 0) printf(",");
			printf(" %d", a[0]);
			a.pop_front();
			a.push_back(a[0]);
			a.pop_front();
		}
		printf("\n");
		printf("Remaining card: %d\n",a[0]);
		a.clear();
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
