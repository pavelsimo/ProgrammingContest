/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11878  C++  "Ad Hoc" */
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
#include <bitset>
#include <utility>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)

char s[128];
char res[16];

int main() {
	int a, b, c;
	int ans = 0;
	while(gets(s)) {
		if(strchr(s,'+')!=NULL) {
			sscanf(s,"%d+%d=%s",&a,&b,&res);
			c = a+b;
		} else {
			sscanf(s,"%d-%d=%s",&a,&b,&res);
			c = a-b;
		}
		if(res[0]!='?') {
		  int d = atoi(res);
		  if(c==d) ans++;
      }		
	}
	printf("%d\n",ans);
	return 0;
}
/* @END_OF_SOURCE_CODE */
