/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11369  C++  "Graph Theory, BFS" */
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
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)

typedef long long llong;
int a[20010];

int main(int argc, char *argv[]) {	
	int TC, n, x;
	llong ans;
	scanf("%d",&TC);
	while(TC-- > 0) {
		scanf("%d",&n);
		for(int i=0; i < n; ++i)
			scanf("%d",&a[i]);
		sort(a,a+n,greater<int>());
		ans=0LL;
		for(int i=2; i < n; i+=3) ans+=a[i];
		printf("%lld\n",ans);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */



