/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10006  C++  "Ad Hoc, Number Theory" */
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
#include <queue>
#include <utility>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)

typedef long long llong;

const int MAXN = 68000;
bool prime[MAXN];

void sieve(int n) {
   for(int i = 0; i <= n; ++i) prime[i] = true;
   prime[0]=false;
   prime[1]=false;
   int m = (int)sqrt(n);
   for (int i=2; i<=m; i++)
      if (prime[i])
         for (int k=i*i; k<=n; k+=i)
            prime[k]=false;
}


llong exp(llong a, llong k, llong n) {
	if(k==0LL) return 1LL;
	if(k&1) {
		return ((exp(a,k-1,n)%n)*(a%n))%n;
	} else {
		llong x = exp(a,k>>1,n)%n;
		return (x*x)%n;
	}
}

int main(int argc, char *argv[]) {
	llong n;
	sieve(MAXN);
	while(scanf("%lld",&n)==1) {
		if(n==0LL)break;
		if(prime[n]) {
			printf("%lld is normal.\n",n);
		} else {
			llong k;
			for(k = 2; k < n; ++k) {
				llong res = exp(k,n,n);
				if(res!=k) break;
			}
			if(k==n) printf("The number %lld is a Carmichael number.\n",n);
			else printf("%lld is normal.\n",n);
		}
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

