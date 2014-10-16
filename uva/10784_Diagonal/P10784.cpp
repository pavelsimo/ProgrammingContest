/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10784  C++  "Simple Math" */
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <cstring>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)

typedef long long ll;

ll cntdiag(ll n) {
   return ((n)*(n-3LL))/2LL;
}

int main(int argc, char *argv[]) {
	ll n;
	int TC = 0;
	while(scanf("%lld",&n)==1) {
		if(n==0LL)break;
		ll x = (ll)sqrt(9+2*n);
		for(int i = -5; i <= 5; ++i) {
			ll x1 = x+i;
			if(cntdiag(x1)>=n) {
				printf("Case %d: %lld\n",++TC,x1);
				break;
			}
		}
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
