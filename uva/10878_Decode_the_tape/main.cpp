/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10878  C++  "Bits, String Manipulation" */
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

int main(int argc, char *argv[]) {
	char buf[20];
	int ch, k;
	while(gets(buf)) {
		if(buf[0] == '_') continue;
		k = 7;
		ch = 0;
		for(int i = 1; buf[i] != '|'; ++i) {
			if ( buf[i] == 'o' ) ch |= 1 << k--;
			else if ( buf[i] == ' ') k--;
		}
		putchar(ch);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

