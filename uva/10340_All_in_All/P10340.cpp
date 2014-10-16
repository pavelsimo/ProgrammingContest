/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10340  C++  "Ad Hoc" */
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
#include <utility>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)
#define BITCOUNT(mask) ( __builtin_popcount((mask)) )
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

char buf[2000010];
char s[1000000];
char t[1000000];

int issubseq(char *a, char *b) {
	int n = strlen(a), m = strlen(b);
	int pos = 0;
	for(int i = 0; i < n; ++i)
		if(pos < m && a[i]==b[pos]) pos++;
	return pos==m;
}

int main(int argc, char *argv[]) {
	while(gets(buf)) {
		sscanf(buf,"%s %s",&s,&t);
		printf("%s\n",issubseq(t,s)? "Yes" : "No");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
