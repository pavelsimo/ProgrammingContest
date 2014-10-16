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

bitset<10000010> b;
vector<int> primes;
typedef long long ll;


void sieve(ll N) {
	N++;
	b.reset(); 
	b.flip();
	b.set(0, false); 
	b.set(1, false);
	for (ll i = 2; i <= N; i++) {
		if (b.test((size_t)i)) {
			for (ll j = i * i; j <= N; j += i) 
			b.set((size_t)j, false);
			primes.push_back((int)i);
		}	
	}
}

int divisors(ll N) {
  int res = 1;
  int k = 0;
  ll t = primes[k];
  map<int, int> PF;
  if (N==1) return 1; 
  while (N != 1LL && t*t <= N) { 
	while ((N % t) == 0LL) { 
		N /= t; 
		PF[t]++;
	}
	t = primes[k++];
  }
  if (N != 1) PF[N]++;
  FORE(PF,it) res *= (PF[it->first]+1);
  if (res==1) res = 2; // PRIME
  return res;
}

int main(int argc, char *argv[]) {
	ll n;
	sieve(1000000LL);
	while(scanf("%lld",&n)==1) {
		if ( n == 0LL ) break;
		// EVEN(OFF) - ODD(ON)
		printf("%s\n",((divisors(n)%2)==0) ? "no" : "yes");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
