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

#define INF 1000
#define BITCOUNT(mask) ( __builtin_popcount((mask)) )


int main(int argc, char *argv[]) {
	
	int N, Q, x, TC=0;
	while ( scanf("%d %d",&N, &Q) == 2 ) {
		TC++;
		if ( N==0 && Q==0 ) break;
		vector<int> a;
		for(int i = 0; i < N; ++i) {
			scanf("%d",&x);
			a.push_back(x);
		}
		sort(a.begin(), a.end());
		printf("CASE# %d:\n",TC);
		for(int i = 0; i < Q; ++i) {
			scanf("%d",&x);
			int j;
			for(j = 0; j < N; ++j) {
				if ( a[j] == x ) {
					printf("%d found at %d\n",x,(j+1));
					break;
				}
			}
			if ( j == N ) {
				printf("%d not found\n",x);
			}
		}
	}
	return 0;
}
