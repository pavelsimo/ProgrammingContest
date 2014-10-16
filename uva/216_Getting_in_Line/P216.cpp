/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  216  C++  "Brute Force, Backtracking" */
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
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) { }
	Point(int _x, int _y) : x(_x), y(_y) { }
};

const double INF = 1000000.0;
const double EPS = 1e-9;
const int MAXN = 8;
int idx[MAXN];
Point p[MAXN];

bool doubleLess(double left, double right, bool equal = false) {
  if (fabs(left - right) < EPS)
    return equal;
  return left < right;
}

double distance(int x1, int y1, int x2, int y2) {
	int dx = x1-x2;
	int dy = y1-y2;
	return sqrt(dx*dx+dy*dy);
}

int main() {
	int n, x, y;
	string cur;
	double cost;
	int TC=0;
	while(scanf("%d",&n)==1) {
		if(n==0) break;
		printf("**********************************************************\n");
		cost = INF;
		cur="";
		for(int i = 0; i < n; ++i) {
			scanf("%d%d",&x,&y);
			Point t(x,y);
			p[i] = t;
			idx[i] = i;
		}
		do {
			double t=0.0;
			for(int i=0; i < n-1; ++i)
				t+=distance(p[idx[i]].x,p[idx[i]].y,p[idx[i+1]].x,p[idx[i+1]].y) + 16.0;
			if(doubleLess(t,cost)) {
				cost=t;
				cur="";
				for(int i = 0; i < n; ++i) cur += (char)('0'+idx[i]);
			}
		} while(next_permutation(idx,idx+n));
		printf("Network #%d\n",++TC);
		for(int i=0; i < n-1; ++i) {
			double t=0.0;
			int k1 = cur[i]-'0';
			int k2 = cur[i+1]-'0';
			t = distance(p[k1].x,p[k1].y,p[k2].x,p[k2].y) + 16.0;
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n",p[k1].x,p[k1].y,p[k2].x,p[k2].y,t);
		}
		printf("Number of feet of cable required is %.2lf.\n",cost);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
