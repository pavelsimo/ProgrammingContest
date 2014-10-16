/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  414  C++  "Ad Hoc, Greedy" */
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

#define M 25
int A[14];

int main(int argc, char *argv[]) {
	int N, t, ans;
	char buf[32];
	while(scanf("%d\n",&N)==1) {
		if(N==0)break;
		memset(A,0,sizeof(A));
		t=0;
		REP(i,N) {
			gets(buf);
			REP(j,M) if(buf[j]=='X')A[i]++;
			t = max(t,A[i]);
		}
		ans=0;
		REP(i,N) ans+=t-A[i];
		printf("%d\n",ans);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

