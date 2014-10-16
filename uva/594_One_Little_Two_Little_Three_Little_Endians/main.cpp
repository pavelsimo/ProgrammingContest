/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10110  C++  "Number Theory, Prime Factors" */
#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>
#include <map>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)

typedef long long ll;

void reverse_bits(ll &x) {
	ll res = 0LL;
	int N = 7;
	for(int i = 31; i >= 0; --i)
		if((x&1LL<<i)!=0LL) {
			N = i;
			break;
		}
	for(int i = 0; i <= N; ++i)
		if((x&1LL<<i)!=0LL)
			res|=1LL<<(N-i);
	x = res;
}

int main(int argc, char *argv[]) {
	
	ll ans, n, x, a, b, c, d;
	while(1==scanf("%lld",&n)) {
		a = (n&0xFFLL);
		b = (n&0xFF00LL) >> 8LL;
		c = (n&0xFF0000LL) >> 16LL;
		d = (n&0xFF000000LL) >> 24LL;
		a = a << 24LL;
		b = b << 16LL;
		c = c << 8LL;
		d = d;
		ans = a|b|c|d;
		
			
		printf("%lld converts to %lld\n",n,ans);
	}
	
	return 0;
}
/* @END_OF_SOURCE_CODE */
