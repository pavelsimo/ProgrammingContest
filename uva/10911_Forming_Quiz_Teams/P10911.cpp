/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10911  C++  "DP" */
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
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)

struct point {
	int x;
	int y;
	point(int _x=0, int _y=0) {
		x = _x;
		y = _y;
	}
};

double INF = 1000000000.0;
char name[32];
point p[20];
bool vis[1<<16];
double memo[1<<16];
char buf[1024];
int n;

double distance(double x1, double x2, double y1, double y2) {
	double dx = x1-x2;
	double dy = y1-y2;
	return sqrt(dx*dx+dy*dy);
}

double go(int mask) {
	if(vis[mask]) return memo[mask];
	if(mask==(1<<n+n)-1) return 0.0;
   double &ans = memo[mask];
   ans = INF;
	vis[mask] = true;
	for(int i = 0; i < n+n; ++i) {
		if(!(mask&(1<<i))) {
			for(int j = 0; j < n+n; ++j) {
				if(i==j) continue;
				if(!(mask&(1<<j)))
					ans = min(ans,go(mask|(1<<i)|(1<<j))+distance(p[i].x,p[j].x,p[i].y,p[j].y));
			}
		}
	}
	return ans;
}

int main(int argc, char *argv[]) {
	int x, y, tc=0;
	while(gets(buf)) {
      memset(vis,false,sizeof(vis));
		sscanf(buf,"%d",&n);
		if(n==0) break;
		for(int i = 0; i < n+n; ++i) {
			gets(buf);
			sscanf(buf,"%s %d %d",&name,&x,&y);
			p[i].x = x;
			p[i].y = y;
		}
		printf("Case %d: %.2lf\n",++tc,go(0));
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

