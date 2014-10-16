/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10346  C++  "Recursion" */
#include <iostream>
#include <sstream>
#include <functional>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <cstring>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)

int doit(int n, int k, int left) {
	if(n==0) return 0;
	return n + doit((n+left)/k, k, (n+left)%k);
}

int main(int argc, char *argv[]) {
	int ans,n,k;
	while(scanf("%d%d",&n,&k)==2) {
		printf("%d\n",doit(n,k,0));
	}
}
/* @END_OF_SOURCE_CODE */

