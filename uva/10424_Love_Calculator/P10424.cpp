/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10424  C++  "Ad Hoc" */
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

char a[32];
char b[32];

int getcost(char *name) {
	int t=0;
	int ans=0;
	int n = strlen(name);
	for(int i = 0; i < n; ++i) {
		if(name[i] >= 'a' && name[i] <= 'z') t+=name[i]-'a'+1;
		else if(name[i] >= 'A' && name[i] <= 'Z') t+=name[i]-'A'+1;
	}
	ans = t;
	while(ans > 9) {
		int x = ans;
		int sum = 0;
		while(x > 0) {
			sum+=x%10;
			x/=10;
		}
		ans=sum;
	}	
	return ans;
}

int main() {
   int c1, c2;
   double x1, x2;
   while(gets(a) && gets(b)) {
      c1 = getcost(a);
      c2 = getcost(b);
		x1 = min(c1,c2);
		x2 = max(c1,c2);
		printf("%.2lf %%\n",x2==0.0? 100.0:(x1/x2)*100.0);
   }
	return 0;
}
/* @END_OF_SOURCE_CODE */
