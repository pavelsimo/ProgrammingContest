/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11715  C++  "Ad Hoc, Simple Math" */
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

/*
If 1 u v t are given then print s and a
If 2 u v a are given then print s and t
If 3 u a s are given then print v and t
If 4 v a s are given then print u and t
*/
int main(int argc, char *argv[]) {
	int n, tc=0;
	double x[3], ans[2], u, v, t, s, a;
	while(scanf("%d%lf%lf%lf",&n,&x[0],&x[1],&x[2])==4) {
		switch(n) {
			case 1:
				u=x[0]; v=x[1]; t=x[2];
				ans[1] = (v-u)/t;
				ans[0] = u*t + (ans[1]*t*t)/2.0;
			break;
			case 2:
				u=x[0]; v=x[1]; a=x[2];
				ans[0] = (v*v - u*u)/(2.0*a);
				ans[1] = (v-u)/a;
			break;
			case 3:
				u=x[0]; a=x[1]; s=x[2];
				ans[0] = sqrt(u*u + 2.0*a*s);
				ans[1] = (ans[0]-u)/a;
			break;
			case 4:
				v=x[0]; a=x[1]; s=x[2];
				ans[0] = sqrt(v*v-2.0*a*s);
				ans[1] = (v-ans[0])/a;
			break;			
		}
		printf("Case %d: %.3lf %.3lf\n",++tc,ans[0],ans[1]);
	}
	return 0; 
}
/* @END_OF_SOURCE_CODE */

