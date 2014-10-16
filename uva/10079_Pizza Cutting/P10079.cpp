/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10079  C++  "Simple Math" */
#include <iostream>
#include <sstream>
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

typedef long long ll;

int main(int argc, char *argv[]) {
	ll n;
	while(scanf("%lld\n",&n)==1) {
		if(n < 0LL) break;
		printf("%lld\n",((n*(n+1LL))/2LL)+1LL);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
