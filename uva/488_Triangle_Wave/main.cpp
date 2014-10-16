/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  488  C++  "Ad Hoc" */
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

int main() {
	int TC, amp, freq;
	scanf("%d",&TC);
	REP(tc,TC) {
		if(tc!=0) putchar('\n');
		scanf("%d%d",&amp,&freq);
		REP(i,freq) {
			if(i!=0) putchar('\n');
			FOR(j,1,amp) {
				FOR(k,1,j) putchar('0'+j);
				putchar('\n');
			}
			FORD(j,amp-1,1) {
				FOR(k,1,j) putchar('0'+j);
				putchar('\n');
			}
		}
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
