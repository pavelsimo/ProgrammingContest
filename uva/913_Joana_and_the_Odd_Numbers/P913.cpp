/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  913  C++  "Simple Math" */
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

int main(int argc, char *argv[]) {
	ll n;
	while(scanf("%lld",&n)==1) {
		ll x = (n+1LL)/2LL;
		ll m = x*x;
		ll a = 2LL*m-5LL < 0LL? 0LL: 2LL*m-5LL;
		ll b = 2LL*m-3LL < 0LL? 0LL: 2LL*m-3LL;
		ll c = 2LL*m-1LL < 0LL? 0LL: 2LL*m-1LL;
		printf("%lld\n",a+b+c);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
