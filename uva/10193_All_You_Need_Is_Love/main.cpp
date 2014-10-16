/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10193  C++  "GCD, Simple Math" */
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
	int TC, a, b, n;
	char buffer[32];
	scanf("%d\n",&TC); 
	FOR(tc,1,TC) {
		a=b=0;
		gets(buffer);
		n = strlen(buffer);
		REP(i,n) 
			if(buffer[i]-'0') 
				a|=1<<(n-i-1);
		gets(buffer);
		n = strlen(buffer);
		REP(i,n) 
		    if(buffer[i]-'0') 
				b|=1<<(n-i-1);
		if ( a == b )
			printf("Pair #%d: All you need is love!\n",tc);
		else if ( gcd(a,b) > 1 )
			printf("Pair #%d: All you need is love!\n",tc);
		else
			printf("Pair #%d: Love is not all you need!\n",tc);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

