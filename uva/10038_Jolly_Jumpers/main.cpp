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
#define BITCOUNT(mask) ( __builtin_popcount((mask)) )
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

#define SIZE 3002

int main(int argc, char *argv[]) {
	
	int N, k;
	int a[SIZE];
	int b[SIZE];
	while ( scanf("%d",&N) == 1 ) {
	
		memset(b,0,sizeof(b));
	
		for(int i = 0; i < N; ++i) {
			scanf("%d", &a[i]);
		}
		
		for(int i = 0; i < N-1; ++i) {
			k = abs(a[i+1]-a[i]);
			if ( k <= N-1 ) {
				b[k] = 1;
			}
		}
		int i;
		for(i = 1; i < N; ++i) {
			if (!b[i]) {
				printf("Not jolly\n");
				break;
			}
		}
		if ( i == N ) { 
			printf("Jolly\n");
		}
	}
	return 0;
}
