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

#define N 1000000

int A[N+2];
int B[N+2];
int P[N+2];

void sieve(int n) {
	for(int i = 0; i < n; ++i) P[i] = 1;
	P[0] = 0;
	P[1] = 0;
	int m = (int)sqrt(n);
	for (int i = 2; i <= m; i++)
		if (P[i])
			for (int k = i * i; k <= n; k += i)
				P[k] = 0;
}

int main() {
    sieve(N);
    for (int k = 6; k <= N; k+=2) {
    		for (int m = k-1; m >= 0; m-=2) {
    			if ( P[m] ) {
    				int t = k-m;
    				if ( !P[t] ) continue;
    				A[k] = t;
    				B[k] = m;
    				break;
    		}
    	}
   	}
   	
    int x;
    while ( scanf("%d",&x) == 1)  {
		if (x == 0)
			break;
		if ( A[x]==0 && B[x]==0 )
			printf("Goldbach's conjecture is wrong.");
		else {
			printf("%d = %d + %d\n", x, A[x],B[x]);
		}
    }
    return 0;
}
