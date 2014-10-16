/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11764  C++  "Ad Hoc" */
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
#include <utility>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)

int a[55];

int main(int argc, char *argv[]) {
	int TC, n, low, high;
	scanf("%d",&TC);
	for(int tc=1;tc<=TC; ++tc) {
		scanf("%d",&n);
		for(int i = 0; i < n; ++i)
			scanf("%d",&a[i]);
		low=high=0;
		for(int i = 1; i < n; ++i) {
			if(a[i-1] > a[i]) low++;
			if(a[i-1] < a[i]) high++;
		}
		printf("Case %d: %d %d\n",tc,high,low);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

