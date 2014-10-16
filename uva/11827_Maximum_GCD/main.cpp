/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11827  C++  "Simple Math, GCD" */
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

int a[101];

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
	int TC, n, ans;
	string buf;
	scanf("%d\n",&TC);
	while(TC-- > 0) {
		getline(cin,buf);
		istringstream str(buf);
		n = 0;
		ans = 1;
		for(int i = 0; str >> a[i]; ++i) n++;
		for(int i = 0; i < n; ++i)
			for(int j = i+1; j < n; ++j)
				ans = max(ans, gcd(a[i],a[j]));
		printf("%d\n",ans);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

