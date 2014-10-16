/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  412  C++  "Ad Hoc, Simple Math, GCD" */
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

int gcd(int a, int b) {
	int t;
	while(b != 0) {
		t = b;
		b = a%b;
		a = t;
	}
	return a;
}

int main(int argc, char *argv[]) {
	int n, x, k, c;
	while(scanf("%d",&n)==1) {
		if ( n == 0 ) break;
		vector<int> a;
		REP(i,n) {
			scanf("%d",&x);
			a.push_back(x);
		}
		k = 0;
		c = 0;
		for(int i = 0; i < n; ++i) {
			for(int j = i+1; j < n; ++j) {
				k++;
				if (gcd(a[i],a[j])==1) c++;
			}
		}
		if ( c > 0 )
			printf("%.6f\n", sqrt((6.0*k)/(1.0*c)));
		else
			printf("No estimate for this data set.\n");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

