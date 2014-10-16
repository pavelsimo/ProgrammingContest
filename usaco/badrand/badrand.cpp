/*
ID: 12
PROG: badrand
LANG: C++
*/
#include <cstring>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <iostream>
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
#define DEBUG
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }
typedef pair<int,int> ii;
typedef vector<ii> vii;

set<int> vis;
char buf[10];

int main() {
	freopen("badrand.in", "r", stdin);
	freopen("badrand.out", "w", stdout);
	int a, b, x, ans=0;
	scanf("%s",&buf);
	while(1) {
		a=(buf[1]-'0')*10;
		b=(buf[2]-'0');
		x=(a+b)*(a+b);
		if(x>=0 && x<=9) sprintf(buf,"000%d",x);
		else if(x>=10 && x<=99) sprintf(buf,"00%d",x);
		else if(x>=100&& x<=999) sprintf(buf,"0%d",x);
		else sprintf(buf,"%d",x);
		ans++;
		if(vis.count(x)>0)break;
		vis.insert(x);
	}
	printf("%d\n",ans);
   return 0;
}
