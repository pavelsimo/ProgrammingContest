/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10323 C++  "Math, Factorial" */
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

void doit(int n) {
	if(n<0) {
		if(n%2==0) puts("Underflow!");
		else puts("Overflow!");
		return;
	}
	if(n>13) {
		puts("Overflow!");
		return;
	}
	if(n >= 0 && n < 8) puts("Underflow!");
	else if(n==8)puts("40320");
	else if(n==9)puts("362880");
	else if(n==10)puts("3628800");
	else if(n==11)puts("39916800");
	else if(n==12)puts("479001600");
	else if(n==13)puts("6227020800"); 
}


int main(int argc, char *argv[]) {
	int n;
	while(scanf("%d",&n)==1) {
		doit(n);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

