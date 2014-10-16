/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  445  C++  "Ad Hoc, String Manipulation" */
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

void go(char ch, int N) {
	REP(i,N) putchar(ch);
}

int main(int argc, char *argv[]) {
	char buf[256];
	int n, count;
	while(gets(buf)) {
		n = strlen(buf);
		count=0;
		REP(i,n) {
			if(isdigit(buf[i])) {
				count+=buf[i]-'0';
				continue;
			}
			if(buf[i]=='b')
				go(' ',count);
			else if(isalpha(buf[i]))
				go(buf[i],count);
			else if(buf[i]=='*')
				go(buf[i],count);
			else if(buf[i]=='!')
				putchar('\n');
			count = 0;
		}
		putchar('\n');
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

