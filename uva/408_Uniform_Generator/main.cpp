/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  408  C++  "GCD, Simple Math" */
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
	int step, mod;
	while(scanf("%d %d",&step,&mod) == 2) {
		if(step==mod || gcd(step,mod) != 1)
			printf("%10d%10d    Bad Choice\n",step,mod);
		else
			printf("%10d%10d    Good Choice\n",step,mod);
		printf("\n");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

