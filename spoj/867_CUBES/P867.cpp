/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ CUBES C++ "Simple Math" */
#include <cstdio>
#include <cstring>
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

int cubes[202];

int main(int argc, char *argv[]) {
	for (int i = 0; i <= 200; ++i)
		cubes[i] = i * i * i;
	for (int a = 2; a <= 100; a++) {
		for (int b = 2; b < a; b++) {
			if ( a == b ) continue;
			for (int c = b + 1; c < a; ++c) {
				for (int d = c + 1; d < a; ++d) {
					if (cubes[a] == (cubes[b] + cubes[c] + cubes[d]))
						printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
				}
			}
		}
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
