/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11743  C++  "Ad Hoc" */
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

char buf[32];

int sum(int x) {
	return x%10 + (x/10)%10;
}

int main(int argc, char *argv[]) {
	int TC, n, x, y;
	gets(buf);
	sscanf(buf,"%d",&TC);
	while(TC-- > 0) {
		gets(buf);
		n=strlen(buf);
		x=y=0;
		for(int i=0, j=0; i < n; ++i) {
			if(!isdigit(buf[i])) continue;
			if(j%2==0) x+=sum((buf[i]-'0')*2);
			else y+=(buf[i]-'0');
			j++;
		}
		if((x+y)%10==0) puts("Valid");
		else puts("Invalid");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
