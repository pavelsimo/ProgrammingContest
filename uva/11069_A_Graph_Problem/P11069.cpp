/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11069  C++  "DP" */
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cstring>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)

const int maxn = 80;
int a[maxn];
int memo[maxn];

int f(int i, int n) {
	if(i > n) return 0;
	if(memo[i]>=0) return memo[i];
	if(i==n || i==n-1) return 1;
	return memo[i] = f(i+2,n)+f(i+3,n);
}

int main() {
   int n;
   for(int i = 1; i <= 76; ++i) {
		memset(memo,-1,sizeof(memo));
		a[i] = f(1,i)+f(2,i);
	}
	while(scanf("%d",&n)==1)
		printf("%d\n",a[n]);
	return 0;
}
