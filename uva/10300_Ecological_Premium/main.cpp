/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10300  C++  "Math" */
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
#include <list>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

// a - farmyard area (m^2)
// b - number of animals
// c - enviroment-friendliness
int main(int argc, char *argv[]) {
	int TC, N;
	int budget, a, b, c;
	scanf("%d",&TC);
	while(TC-- > 0) {
		scanf("%d",&N);
		budget=0;
		REP(i,N) {
			scanf("%d%d%d",&a,&b,&c);
			budget+=a*c;
		}
		printf("%d\n",budget);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

