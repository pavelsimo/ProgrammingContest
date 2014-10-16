/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  583  C++  "Number Theory, Sieve, Prime Factors" */
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
#include <bitset>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

typedef long long ll;
typedef vector<int> vi;
ll _sieve_size;
bitset<10000010> bs;
vi primes;

void sieve(ll upperbound) { 
  _sieve_size = upperbound+1; 
  bs.reset(); bs.flip(); 
  bs.set(0, false); 
  bs.set(1, false);
  for (ll i = 2; i <= _sieve_size; i++) 
  if (bs.test((size_t)i)) {
    for (ll j = i * i; j <= _sieve_size; j += i) 
	bs.set((size_t)j, false);
    primes.push_back((int)i);
  }
}

void factors(vi &F, int N) {
  if ( N < 0 ) {
	F.push_back(-1);
	N = -N;
  }
  int PF_idx = 0;
  ll PF = primes[PF_idx]; 
  while (N != 1 && (PF * PF <= N)) { 
    while (N % PF == 0) { 
		N /= PF; 
		F.push_back(PF); 
	} 
    PF = primes[++PF_idx];
  }
  if (N != 1) F.push_back(N);
}

int main() {
	int n;
	sieve(60000);
	while(scanf("%d",&n)==1) {
		if(n==0) break;
		vi a;
		factors(a,n);
		printf("%d =",n);
		REP(i,a.size()) {
			if(i!=0) printf(" x");
			printf(" %d",a[i]);
		}
		putchar('\n');
	}
}
/* @END_OF_SOURCE_CODE */
