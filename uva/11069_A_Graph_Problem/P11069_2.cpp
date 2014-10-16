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

int main() {
   int n;
   a[0] = 0;
   a[1] = 1;
   a[2] = 2;
   a[3] = 2;
   for(int i = 4; i <= 76; ++i)
		a[i] = a[i-2]+a[i-3];
	while(scanf("%d",&n)==1) 
       printf("%d\n",a[n]);
	return 0;
}
