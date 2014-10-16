/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  694  C++  "Recursion" */
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
	ll a, x, limit;
	int TC=0,ans;
	while(scanf("%lld %lld",&a,&limit)==2)  {
		if(a < 0LL || limit < 0LL)break;
		ans=1;
		x = a;
		while(x > 1LL) {
			if(x%2LL==0LL) {
				x/=2LL;
			} else {
				x = 3LL*x + 1LL;
				if(x > limit) break;
			}
			ans++;
		}
		printf("Case %d: A = %lld, limit = %lld, number of terms = %d\n",++TC,a,limit,ans);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

