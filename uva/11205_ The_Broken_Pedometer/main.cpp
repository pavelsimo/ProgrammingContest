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
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

#define BITCOUNT(mask) ( __builtin_popcount((mask)) )
#define N 32769

int A[101];
int S[N];
int ncases, nsymbols, nbits;

int main(int argc, char *argv[]) {

	scanf("%d\n",&ncases);
	
	for(int tc = 0; tc < ncases; ++tc) {

		scanf("%d %d",&nbits, &nsymbols);
		
		int ans = nbits;
		int t;
		
		for(int i = 0; i < nsymbols; ++i) {
			A[i] = 0;
			for(int j = 0; j < nbits; ++j) {
				scanf("%d",&t);
				if ( t ) 
					A[i] |= 1 << j;	
			}
		}
    
		memset(S, 0, sizeof(S));
    
		for(int mask = (1<<nbits)-1; mask > 0; --mask) {
			int ok = 1;
			for(int i = 0; i < nsymbols; ++i) {
				if ( S[A[i] & mask] == mask ) {
					ok = 0;
					break;
				} 
				S[A[i] & mask] = mask;
			}	
			if ( ok )
				ans = min(ans, BITCOUNT(mask));
		}
		printf("%d\n",ans);
	}
	
	return 0;
}
