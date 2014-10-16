/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11530  C++  "Ad Hoc" */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
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
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

int a[] = {1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};

int main() {
	char s[255];
	int TC, k=0, m, res;
	scanf("%d",&TC);
	getchar();
	while(TC-- > 0) {
		gets(s);
		m = strlen(s);
		res=0;
		REP(i,m) {
			if(s[i]==32) res++;
			else res+=a[s[i]-'a'];
		}
		printf("Case #%d: %d\n",++k,res);
	}
	return 0;
}
