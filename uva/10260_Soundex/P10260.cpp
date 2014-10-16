/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10260  C++  "Ad Hoc" */
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

int soundex[255];
char s[32];

int main(int argc, char *argv[]) {
	memset(soundex,0,sizeof(soundex));
	soundex['B'] = 1;
	soundex['F'] = 1;
	soundex['P'] = 1;
	soundex['V'] = 1;
	soundex['C'] = 2;
	soundex['G'] = 2;
	soundex['J'] = 2;
	soundex['K'] = 2;
	soundex['Q'] = 2;
	soundex['S'] = 2;
	soundex['X'] = 2;
	soundex['Z'] = 2;
	soundex['D'] = 3;
	soundex['T'] = 3;
	soundex['L'] = 4;
	soundex['M'] = 5;
	soundex['N'] = 5;
	soundex['R'] = 6;
	int n;
	while(gets(s)) {
		n = strlen(s);
		for(int i = 0; i < n; ++i) {
			if(soundex[s[i]]) {
				int j = 0;
				char ch = s[i];
				putchar(soundex[ch]+'0');
				while(i+1 < n && soundex[ch]==soundex[s[i+1]]) i=i+1;
			}
		}
		putchar('\n');
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
