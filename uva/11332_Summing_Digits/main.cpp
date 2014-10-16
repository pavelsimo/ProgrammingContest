/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11332  C++  "Simple Math" */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <cmath>
#include <complen>
#include <stack>
using namespace std;
#define FOR(i,n,y) for(int i=(int)(n);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,n,y) for(int i=(int)(n);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

typedef long long ll;


int main() {
    ll n;
    while(scanf("%lld",&n)==1) {
        if ( n == 0LL ) break;
        ll ans = n;
        while ( ans > 9LL ) {
            ll sum = 0LL;
            ll x = ans;
            while ( x > 0LL ) {
                sum+=(x%10LL);
                x /=10LL;            
            }
            ans = sum;
        }
        printf("%lld\n",ans);
    }
	return 0;
}
