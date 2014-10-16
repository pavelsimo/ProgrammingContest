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
#define ALARM1_ON 0x01
#define ALARM2_ON 0x02
#define ALARM3_ON 0x04
#define ALARM4_ON 0x08
#define ALARM1_HT 0x10
#define ALARM2_HT 0x20
#define ALARM3_HT 0x40
#define ALARM4_HT 0x80
#define IS_ALARM1_ON(x) (x & ALARM1_ON)
#define IS_ALARM2_ON(x) (x & ALARM2_ON)
#define IS_ALARM3_ON(x) (x & ALARM3_ON)
#define IS_ALARM4_ON(x) (x & ALARM4_ON)
#define IS_ALARM1_HT(x) (x & ALARM1_HT)
#define IS_ALARM2_HT(x) (x & ALARM2_HT)
#define IS_ALARM3_HT(x) (x & ALARM3_HT)
#define IS_ALARM4_HT(x) (x & ALARM4_HT)
#define SET_ALARM1(x) (x |= ALARM1_ON)
#define SET_ALARM2(x) (x |= ALARM2_ON)
#define SET_ALARM3(x) (x |= ALARM3_ON)
#define SET_ALARM4(x) (x |= ALARM4_ON)

int TC, M, S, A1, A2, A3, A4, C, K, t, tmp;

int main(int argc, char *argv[]) {
	
	scanf("%d", &TC);
	while ( TC-- > 0 ) {
		scanf("%d %d %d %d %d %d %d %d",&M,&S,&A1,&A2,&A3,&A4,&C,&K);
		for(int i = 0; i < K; ++i) {
			scanf("%d %d", &t, &tmp);
		}
	}
	
	return 0;
}
