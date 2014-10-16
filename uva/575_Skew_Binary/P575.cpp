/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  575  C++  "Ad Hoc" */
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
char buf[64];

int main(int argc, char *argv[]) {
	ll ans;
	int n;
	while(gets(buf)) {
		n = strlen(buf);
		if(buf[0]=='0'&&buf[1]=='\0')break;
		ans=0LL;
		for(int i = 0; i < n; ++i) {
         int d = (buf[i]-'0');
         ans+=d*((1<<n-i)-1);
		}
		printf("%lld\n",ans);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
