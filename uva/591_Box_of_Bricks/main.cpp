/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  591  C++  "Ad Hoc, Greedy" */
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

#define M 52
int h[M];

int main(int argc, char *argv[]) {
	int TC=0,n,k,ans,x;
	while(scanf("%d",&n)==1) {
		if(n == 0) break;
		ans=k=0;
		REP(i,n) {
			scanf("%d",&h[i]);
			k+=h[i];
		}
		x=k/n;
		REP(i,n)
			if(h[i] > x)
				ans+=h[i]-x;
		printf("Set #%d\nThe minimum number of moves is %d.\n\n", ++TC,ans);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

