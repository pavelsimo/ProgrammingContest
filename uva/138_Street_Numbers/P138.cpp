/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  136  C++  "Number Theory, Prime Factors" */
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

typedef unsigned int uint;
uint maxn=65918169;

int main(int argc, char *argv[]) {
/*
    printf("%*s%*s\n",10,"6",10,"8");
    printf("%*s%*s\n",10,"35",10,"49");
    printf("%*s%*s\n",10,"204",10,"288");
    printf("%*s%*s\n",10,"1189",10,"1681");
    printf("%*s%*s\n",10,"6930",10,"9800");
    printf("%*s%*s\n",10,"40391",10,"57121");
    printf("%*s%*s\n",10,"100469",10,"107694");
    printf("%*s%*s\n",10,"125118",10,"135735");
    printf("%*s%*s\n",10,"1250970",10,"1251592");
    printf("%*s%*s\n",10,"2096128",10,"2097152");
*/
	for(uint k = 2; k <= maxn; ++k) {
		uint l = ((k-1)*k)/2;
		uint r = 0;
		for(uint j = k+1; j <= maxn; ++j) {
			r+=j;
			if(r > l) break;
			if(l==r) {
            printf("%*u%*u\n",10,k,10,j);
				break;
			}
		}
	}

	return 0; 
}
/* @END_OF_SOURCE_CODE */

