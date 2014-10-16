/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11479  C++  "Math, Geometry" */
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

typedef long long ll;

int main(int argc, char *argv[]) {
	int TC;
	ll a, b, c;
	scanf("%d",&TC);
	for(int tc=1; tc<=TC; ++tc) {
		scanf("%lld%lld%lld",&a,&b,&c);
		printf("Case %d: ",tc);
		if(a <= 0 || b <= 0 || c <= 0 || a+b <= c || b+c <= a || a+c <= b) puts("Invalid");
		else if(a==b && b==c && a==c) puts("Equilateral");
		else if(a==b || a==c || b==c) puts("Isosceles");
		else puts("Scalene");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

